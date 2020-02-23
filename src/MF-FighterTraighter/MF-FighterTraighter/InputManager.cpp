#include "InputManager.h"
#include "App.h"

InputManager::InputManager()
{
	clearState();
	SDL_GetKeyboardState(NULL);
}

void InputManager::update()
{
	clearState();
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			app_->exitApp();
			break;
		case SDL_KEYDOWN:
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				app_->exitApp();
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
