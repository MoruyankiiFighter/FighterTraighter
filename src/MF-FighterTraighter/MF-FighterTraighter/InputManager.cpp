#include "InputManager.h"
#include "App.h"

InputManager::InputManager(App* app) : app_(app)
{
	clearState();
	keyboardState_ = SDL_GetKeyboardState(NULL);
}

void InputManager::update()
{
	clearState();
	SDL_Event e;
	while(SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			app_->Exit();
			break;
		case SDL_KEYDOWN:
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				app_->Exit();
			break;
		case SDL_KEYUP:
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseChange(e, true);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseChange(e, false);
			break;
		case SDL_MOUSEMOTION:
			onMouseMotion(e);
			
			break;
		case SDL_JOYAXISMOTION:
			onJoyMotion(e);
			break;
	

		}
	}
}

InputManager::~InputManager()
{
}

void InputManager::clearState()
{
	for (int i = 0; i < mouseState_.size(); ++i) {
		mouseState_[i] = false;
	}
}

inline void InputManager::onJoyMotion(SDL_Event& e)
{
	if (e.jaxis.which == 0){
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

