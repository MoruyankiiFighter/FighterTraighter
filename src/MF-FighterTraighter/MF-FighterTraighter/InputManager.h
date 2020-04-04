#pragma once
#include "SDL.h"
#include <array>
#include "Vector2D.h"
#include <memory>
#include <vector>
#include <SDL_gamecontroller.h>
#include <iostream>
class App;

class InputManager
{
public:
	enum MouseButton : Uint8 {
		Left = 0,
		Right = 1,
		Middle = 2
	};
	enum Controllers {
		PLAYER1, PLAYER2
	};
	struct  GamePad {
		bool buttons[SDL_CONTROLLER_BUTTON_MAX];
		int axis[SDL_CONTROLLER_AXIS_MAX];
	};
	InputManager(App* app);
	InputManager(InputManager&) = delete;
	InputManager& operator= (InputManager&) = delete;

	void update();

	// Keyboard
	inline bool isKeyUp(SDL_Scancode code) {
		return keyboardState_[code] == 0;
	};
	inline bool isKeyUp(SDL_Keycode code) {
		return isKeyUp(SDL_GetScancodeFromKey(code));
	};
	inline bool isKeyDown(SDL_Scancode code) {
		return keyboardState_[code] == 1;
	};
	inline bool isKeyDown(SDL_Keycode code) {
		return isKeyDown(SDL_GetScancodeFromKey(code));
	};
	inline bool KeyPressed(SDL_Scancode code) {
		return lastKeyboardState_[code] == 0 && keyboardState_[code] == 1;
	};
	inline bool KeyPressed(SDL_Keycode code) {
		return KeyPressed(SDL_GetScancodeFromKey(code));
	}
	// if pressed or released a key this frame
	inline bool keyboardEvent() {
		return keyboardEvent_;
	}

	// Mouse
	inline bool isMouseButtonPressed(MouseButton button) {
		return mouseState_[button];
	};
	inline double getMousePosX() {
		return mousePos_.getX();
	};
	inline double getMousePosY() {
		return mousePos_.getY();
	};
	inline const Vector2D& getMousePos() {
		return mousePos_;
	};
	inline const Vector2D& getMouseMovement() {
		return mouseMovementInFrame_;
	}
	// if pressed or released a mouse button this frame
	inline bool mouseEvent() {
		return mouseEvent_;
	}

	// Controller

	bool isControllerButtonPressed(Controllers controllerID, SDL_GameControllerButton button)
	{
		// SMELLS A LOT
		if (controllerID < 0 || controllerID > numGamepads || !GamepadConnected()) return false;

		return controllerInputs[controllerID].buttons[button] && !lastControllerInputs[controllerID].buttons[button];
	}
	bool isControllerButtonHeld(Controllers controllerID, SDL_GameControllerButton button)
	{
		// SMELLS
		if (controllerID < 0 || controllerID > numGamepads || !GamepadConnected()) return false;

		return controllerInputs[controllerID].buttons[button] && lastControllerInputs[controllerID].buttons[button];
	}
	float getControllerAxis(Controllers controllerID, SDL_GameControllerAxis axis)
	{
		if (controllerID < 0 || controllerID > numGamepads || !GamepadConnected()) return 0.0;
		return controllerInputs[controllerID].axis[axis] / 32768.0f;
	}
	inline bool GamepadConnected() { return numGamepads > 0; }
	// if pressed or released a controller button this frame
	inline bool controllerEvent() {
		return controllerEvent_;
	}
	inline bool axisEvent() {
		return axisEvent_;
	}

	inline bool pressedUp() {
		return KeyPressed(SDL_SCANCODE_UP) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_DPAD_UP)
			|| (axisEvent() && getControllerAxis(InputManager::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.8f);
	}
	inline bool pressedLeft() {
		return KeyPressed(SDL_SCANCODE_LEFT) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_DPAD_LEFT)
			|| (axisEvent() && getControllerAxis(InputManager::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) < -0.8f);
	}
	inline bool pressedDown() {
		return KeyPressed(SDL_SCANCODE_DOWN) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_DPAD_DOWN)
			|| (axisEvent() && getControllerAxis(InputManager::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.8f);
	}
	inline bool pressedRight() {
		return KeyPressed(SDL_SCANCODE_RIGHT) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
			|| (axisEvent() && getControllerAxis(InputManager::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) > 0.8f);
	}
	inline bool pressedAccept() {
		return KeyPressed(SDL_SCANCODE_Z) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_A);
	}
	inline bool pressedCancel() {
		return KeyPressed(SDL_SCANCODE_X) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_B);
	}
	inline bool pressedStart() {
		if ((keyboardEvent() && isKeyDown(SDL_SCANCODE_ESCAPE)) // keyboard
			|| (controllerEvent() && isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_START)) // player 1
			|| (controllerEvent() && isControllerButtonPressed(InputManager::PLAYER2, SDL_CONTROLLER_BUTTON_START))) { // player 2
			startEvent_ = true;
		}
		else {
			startEvent_ = false;
		}
		return startEvent_;
	}

	virtual ~InputManager();
private:
	void clearState();

	void initControllers();
	inline void onMouseMotion(SDL_Event& e) {
		mousePos_.set(e.motion.x, e.motion.y);
	};


	void onMouseChange(SDL_Event& e, bool state) {
		if (e.button.button == SDL_BUTTON_LEFT) {
			mouseState_[Left] = state;
		}
		else if (e.button.button == SDL_BUTTON_MIDDLE) {
			mouseState_[Middle] = state;
		}
		else if (e.button.button == SDL_BUTTON_RIGHT) {
			mouseState_[Right] = state;
		}
	};

	App* app_;
	const Uint8* keyboardState_;
	Uint8* lastKeyboardState_;
	int numKeys_;
	Vector2D mousePos_;
	std::array<bool, 3> mouseState_; // true = pressed
	Vector2D mouseMovementInFrame_;
	std::vector<SDL_GameController*> connectedControllers;

	std::vector<GamePad> controllerInputs;
	std::vector<GamePad> lastControllerInputs;
	int numGamepads;

	// if in this frame there has been an event
	bool mouseEvent_ = false; // click
	bool keyboardEvent_ = false; // press
	bool controllerEvent_ = false; // button
	bool axisEvent_ = false; //axis
	bool upEvent_ = false;
	bool leftEvent_ = false;
	bool downEvent_ = false;
	bool rightEvent_ = false;
	bool acceptEvent_ = false;
	bool cancelEvent_ = false;
	bool startEvent_ = false;
};