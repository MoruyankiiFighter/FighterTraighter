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
	bool isControllerButtonUp(Controllers controllerID, SDL_GameControllerButton button)
	{
		// SMELLS
		if (controllerID < 0 || controllerID > numGamepads || !GamepadConnected()) return false;

		return !controllerInputs[controllerID].buttons[button] && lastControllerInputs[controllerID].buttons[button];
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
		return KeyPressed(SDL_SCANCODE_RETURN) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_A);
	}
	inline bool pressedCancel() {
		return KeyPressed(SDL_SCANCODE_X) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_B);
	}
	inline bool pressedStart() {
		return KeyPressed(SDL_SCANCODE_ESCAPE) || isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_START) 
			|| isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_START);
	}

	SDL_Scancode lastKey()
	{
		return e.key.keysym.scancode;
	}
	SDL_GameControllerAxis lastAxis()
	{
		return (SDL_GameControllerAxis)e.caxis.axis;
	}
	SDL_GameControllerButton lastButton()
	{
		return (SDL_GameControllerButton)e.cbutton.button;
	}
	std::string lastKeystring()
	{
	
		return SDL_GetScancodeName( e.key.keysym.scancode);
	}
	std::string lastAxisstring()
	{
		return SDL_GameControllerGetStringForAxis((SDL_GameControllerAxis) e.caxis.axis);
	}
	std::string lastButtonstring()
	{
		
		return SDL_GameControllerGetStringForButton((SDL_GameControllerButton)e.cbutton.button);
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
	SDL_Event e;
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
	std::vector<SDL_Scancode> keys_ = { SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_Q, SDL_SCANCODE_E, SDL_SCANCODE_Z, SDL_SCANCODE_X,
		SDL_SCANCODE_SPACE, SDL_SCANCODE_R, SDL_SCANCODE_1, SDL_SCANCODE_2,};
	
	std::vector<SDL_GameControllerButton>botonesMando = {
	SDL_CONTROLLER_BUTTON_A,
	SDL_CONTROLLER_BUTTON_B,
	SDL_CONTROLLER_BUTTON_X,
	SDL_CONTROLLER_BUTTON_Y,
	SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
	SDL_CONTROLLER_BUTTON_RIGHTSHOULDER
	};

	std::vector<SDL_GameControllerAxis>EjesMando = {
	SDL_CONTROLLER_AXIS_TRIGGERLEFT,
	SDL_CONTROLLER_AXIS_TRIGGERRIGHT
	};

	
	public:
		void change(int index, int control) 
		{
			if (control==0)
			{
				keys_[index] = lastKey();

			}
			else
			{
				if (controllerEvent_)
				{
					//keys_[index] = lastKey();

				}
				else if(axisEvent_)
				{

				}

			}
			
		};
		std::vector<SDL_Scancode>ControlKeyboard()
		{
			return keys_;
		}
		std::vector<SDL_GameControllerAxis>ControlAxis()
		{
			return EjesMando;
		}
		std::vector<SDL_GameControllerButton>ControlButton()
		{
			return botonesMando;
		}

};