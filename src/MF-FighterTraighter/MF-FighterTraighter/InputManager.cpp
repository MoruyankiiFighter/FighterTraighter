#include "InputManager.h"
#include "App.h"

std::unique_ptr<InputManager> InputManager::instance_;

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
			App::instance()->exitApp();
			break;
		case SDL_KEYDOWN:
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				App::instance()->exitApp();
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
