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
	struct GamePad {
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

	bool isControllerButtonPressed(int controllerID, SDL_GameControllerButton button)
	{
		// SMELLS A LOT
		if (controllerID < 0 || controllerID > numGamepads || !GamepadConnected()) return false;

		return controllerInputs[controllerID].buttons[button] && !lastControllerInputs[controllerID].buttons[button];
	}
	bool isControllerButtonHeld(int controllerID, SDL_GameControllerButton button)
	{
		// SMELLS
		if (controllerID < 0 || controllerID > numGamepads || !GamepadConnected()) return false;

		return controllerInputs[controllerID].buttons[button] && lastControllerInputs[controllerID].buttons[button];
	}
	bool isControllerButtonUp(int controllerID, SDL_GameControllerButton button)
	{
		// SMELLS
		if (controllerID < 0 || controllerID > numGamepads || !GamepadConnected()) return false;

		return !controllerInputs[controllerID].buttons[button] && lastControllerInputs[controllerID].buttons[button];
	}
	float getControllerAxis(int controllerID, SDL_GameControllerAxis axis)
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
		return KeyPressed(SDL_SCANCODE_UP) || isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_DPAD_UP)
			|| (axisEvent() && getControllerAxis(0, SDL_CONTROLLER_AXIS_LEFTY) < -0.8f);
	}
	inline bool pressedLeft() {
		return KeyPressed(SDL_SCANCODE_LEFT) || isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_DPAD_LEFT)
			|| (axisEvent() && getControllerAxis(0, SDL_CONTROLLER_AXIS_LEFTX) < -0.8f);
	}
	inline bool pressedDown() {
		return KeyPressed(SDL_SCANCODE_DOWN) || isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_DPAD_DOWN)
			|| (axisEvent() && getControllerAxis(0, SDL_CONTROLLER_AXIS_LEFTY) > 0.8f);
	}
	inline bool pressedRight() {
		return KeyPressed(SDL_SCANCODE_RIGHT) || isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
			|| (axisEvent() && getControllerAxis(0, SDL_CONTROLLER_AXIS_LEFTX) > 0.8f);
	}
	inline bool pressedAccept() {
		return KeyPressed(SDL_SCANCODE_RETURN) || isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_A);
	}
	inline bool pressedCancel() {
		return KeyPressed(SDL_SCANCODE_X) || isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_B);
	}
	inline bool pressedStart() {
		return KeyPressed(SDL_SCANCODE_ESCAPE) || isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_START) 
			|| isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_START);
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
	
	std::vector<std::string>mando= {
	"a","b","x","y","leftshoulder","rightshoulder","lefttrigger","rigthtrigger"
	};
		
	
	public:
		SDL_Scancode lastKey()
		{
			return e.key.keysym.scancode;
		}
		SDL_GameControllerAxis lastAxis()
		{
			return RepairGamePadAxis();
		}
		SDL_GameControllerButton lastButton()
		{
			return RepairGamePadButton();
		}
		std::string lastKeystring()
		{
			return SDL_GetScancodeName(e.key.keysym.scancode);
		}
		std::string lastAxisstring()
		{
			return SDL_GameControllerGetStringForAxis(lastAxis());
		}
		std::string lastButtonstring()
		{
			return SDL_GameControllerGetStringForButton(lastButton());
		}
		void change(int index, int control) 
		{
			bool usado = false;
			if (control==0)
			{
			
				for (int i = 0; i < keys_.size(); i++)
				{
					if (keys_[i]==lastKey())
					{
						usado = true;
						SDL_Scancode aux= keys_[i];
						keys_[i] = keys_[index];
						keys_[index] = aux;
						break;
					}
				}
				if (!usado)
				{
					keys_[index] = lastKey();

				}

			}
			else if(index>3)
			{
				for (int i = 0; i < mando.size(); i++)
				{
					if (mando[i] == lastAxisstring() || mando[i] == lastButtonstring())
					{
						usado = true;
						std::string aux = mando[i];
						mando[i] = mando[index-4];
						mando[index-4] = aux;
						break;
					}
				}
				if (!usado)
				{
					if (controllerEvent_)
					{
						mando[index] = lastButtonstring();

					}
					else
					{
						mando[index] = lastAxisstring();

					}

				}
				

			}
			
		};
		std::vector<SDL_Scancode>ControlKeyboard()
		{
			return keys_;
		}
		std::vector<std::string>ControlMando()
		{
			return mando;
		}
	
		//hell code to repair the gamepad
		SDL_GameControllerButton RepairGamePadButton()
		{
			switch ((SDL_GameControllerButton)e.cbutton.button)
			{
			case SDL_CONTROLLER_BUTTON_BACK:
				return SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
				break;
			case SDL_CONTROLLER_BUTTON_GUIDE:
				return SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
				break;
			default: 
				return (SDL_GameControllerButton)e.cbutton.button;
			}

		}
		SDL_GameControllerAxis RepairGamePadAxis()
		{
			switch ((SDL_GameControllerAxis)e.caxis.axis)
			{
			case SDL_CONTROLLER_AXIS_RIGHTX:
				return SDL_CONTROLLER_AXIS_TRIGGERLEFT;
				break;
			default: 
				return (SDL_GameControllerAxis)e.caxis.axis;
			}

		}
};