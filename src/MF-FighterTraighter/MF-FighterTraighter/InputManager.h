#pragma once
#include "SDL.h"
#include <array>
#include "Vector2D.h"
#include <memory>
class App;

class InputManager
{
public:
	//mouse buttons
	enum MouseButton : Uint8 {
		Left = 0,
		Right = 1,
		Middle = 2
	};
	//constructor
	InputManager(App* app);
	InputManager(InputManager&) = delete;
	InputManager& operator= (InputManager&) = delete;

	//destructor
	virtual ~InputManager();
	
	// updates the input
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

	// Controller
	inline  const int getJoyX()
	{
		return xDir;
	}
	inline  const int getJoyY()
	{
		return yDir;
	}

private:
	void clearState();

	inline void onMouseMotion(SDL_Event& e) {
		mousePos_.set(e.motion.x, e.motion.y);
	};
	inline void onJoyMotion(SDL_Event& e) {

		if (e.jaxis.which == 0)
		{
			//X axis motion
			if (e.jaxis.axis == 0)
			{
				//Left of dead zone
				if (e.jaxis.value < -JOYSTICK_DEAD_ZONE)
				{
					xDir = -1;
				}
				//Right of dead zone
				else if (e.jaxis.value > JOYSTICK_DEAD_ZONE)
				{
					xDir = 1;
				}
				else
				{
					xDir = 0;
				}
			}
		}
		//Y axis motion
		 if (e.jaxis.axis == 1)
		{
			//Below of dead zone
			if (e.jaxis.value < -JOYSTICK_DEAD_ZONE)
			{
				yDir = -1;
			}
			//Above of dead zone
			else if (e.jaxis.value > JOYSTICK_DEAD_ZONE)
			{
				yDir = 1;

			}
			else
			{
				yDir = 0;
			}
		}
	}

				
	

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
	Vector2D mousePos_;
	int xDir;
	int yDir;
    const int JOYSTICK_DEAD_ZONE = 8000;
	std::array<bool, 3> mouseState_; // true = pressed
};