#include "InputManager.h"
#include "App.h"

InputManager::InputManager(App* app) : app_(app)
{
	clearState();
	keyboardState_ = SDL_GetKeyboardState(NULL);
	initControllers();
	///
	
}

void InputManager::update()
{
	clearState();
	SDL_Event e;
	///Update control input
	for (int i = 0; i < numGamepads; i++) {
		for (int a = 0; a < SDL_CONTROLLER_AXIS_MAX; a++) {
			lastControllerInputs[i].axis[a] = controllerInputs[i].axis[a];
		}
		for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; b++) {
			lastControllerInputs[i].buttons[b] = controllerInputs[i].buttons[b];
		}
	}
	///
	

	while (SDL_PollEvent(&e)) {
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
		case SDL_CONTROLLERDEVICEADDED:
			std::cout << "DEVICEADDED cdevice.which = " << e.cdevice.which << std::endl;
			break;

			// If a controller button is pressed
		case SDL_CONTROLLERBUTTONDOWN:
			// Cycle through the controllers
			for (int i = 0; i < numGamepads; i++) {
				// Looking for the button that was pressed
				if (e.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(connectedControllers[i]))) {
					// So the relevant state can be updated
					controllerInputs[i].buttons[e.cbutton.button] = true;
				}
			}
			break;

			// Do the same for releasing a button
		case SDL_CONTROLLERBUTTONUP:
			for (int i = 0; i < numGamepads; i++) {
				if (e.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(connectedControllers[i]))) {
					controllerInputs[i].buttons[e.cbutton.button] = false;
				}
			}
			break;

			// And something similar for axis motion
		case SDL_CONTROLLERAXISMOTION:
			for (int i = 0; i < numGamepads; i++) {
				if (e.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(connectedControllers[i]))) {
					controllerInputs[i].axis[e.caxis.axis] = e.caxis.value;
				}
			}
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
void InputManager::initControllers()
{
	int nJoysticks = SDL_NumJoysticks();
	numGamepads = 0;

	// Count how many controllers there are
	for (int i = 0; i < nJoysticks; i++)
		if (SDL_IsGameController(i))
			numGamepads++;
	if (numGamepads > 0)
	{
		for (int i = 0; i < numGamepads; i++)
		{
			// Open the controller and add it to our list
			SDL_GameController* pad = SDL_GameControllerOpen(i);
			if (SDL_GameControllerGetAttached(pad) == 1)
				connectedControllers.push_back(pad);
			else
				std::cout << "SDL_GetError() = " << SDL_GetError() << std::endl;
		}
		SDL_GameControllerEventState(SDL_ENABLE);

	}	controllerInputs.resize(numGamepads);
	lastControllerInputs.resize(numGamepads);
	for (int i = 0; i < numGamepads; i++) {
		for (int a = 0; a < SDL_CONTROLLER_AXIS_MAX; a++) {
			controllerInputs[i].axis[a] = 0;
			lastControllerInputs[i].axis[a] = 0;
		}
		for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; b++) {
			controllerInputs[i].buttons[b] = false;
			lastControllerInputs[i].buttons[b] = false;
		}
	}
	///
}