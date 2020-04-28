#include "WindowManager.h"
#include "App.h"
#include "consts.h"
#include "SDLExceptions.h"

WindowManager::WindowManager(App* app) : app_(app) {
	int numResolutions = SDL_GetNumDisplayModes(0); // first display
	supportedResolutions_.reserve(numResolutions);
	SDL_DisplayMode curr;
	for (int i = 0; i < numResolutions; ++i) {
		SDL_DisplayMode mode;
		SDL_GetDisplayMode(0, i, &mode);
		supportedResolutions_.emplace_back(mode);
		if (&mode == &curr) currentResolution_ = i;
	}
	//window = SDL_CreateWindow("Fighter Traighter ver 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		//supportedResolutions_[currentResolution_].w, supportedResolutions_[currentResolution_].h, SDL_WINDOW_SHOWN)
	window = SDL_CreateWindow("Fighter Traighter ver 0.2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1280, 720, SDL_WINDOW_SHOWN);
	if (!window) throw new SDLExceptions::SDLException("Unable to create window");
	SDL_GetCurrentDisplayMode(0, &initialDisplayMode_);
	//setFullscreen(true);
	//setResolution(currentResolution_);
}

// Sets the window in fullscreen
void WindowManager::setFullscreen(bool fullscreen)
{
	bool isFullscreen = SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN;
	if (!fullscreen) {
		if (isFullscreen) {
			SDL_SetWindowFullscreen(window, 0);
			SDL_SetWindowSize(window, 1280, 720);
			fullscreen_ = fullscreen;
		}
	}
	else if (!isFullscreen) {
		SDL_SetWindowDisplayMode(window, &supportedResolutions_[currentResolution_]);
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
		fullscreen_ = fullscreen;
	}
}

// Sets the current window resolution, if on fullscreen
void WindowManager::setResolution(int resIndex)
{
	if (fullscreen_) {
		SDL_SetWindowFullscreen(window, 0);
		SDL_SetWindowDisplayMode(window, &supportedResolutions_[resIndex]);
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
		currentResolution_ = resIndex;
	}
}

// Changes the brightness of the window (and whole screeen)
void WindowManager::setBrightness(float brightness)
{
	SDL_SetWindowBrightness(window, brightness); // si a alguien se le queda la pantalla oscura, que ponga aqu� un 1 y descomente lo de abajo
	//int b = 0;
	//int a = 1 / b;
	currentBrightness_ = brightness;
}
