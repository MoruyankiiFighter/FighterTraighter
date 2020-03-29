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
	window = SDL_CreateWindow("Fighter Traighter ver 1.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, SDL_WINDOW_SHOWN);
	if (!window) throw new SDLExceptions::SDLException("Unable to create window");
	SDL_GetCurrentDisplayMode(0, &curr);
	//setFullscreen(true);
	//setResolution(currentResolution_);
}

void WindowManager::setFullscreen(bool fullscreen)
{
	bool isFullscreen = SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP;
	if (!fullscreen) {
		if (isFullscreen) {
			SDL_SetWindowFullscreen(window, 0);
			fullscreen_ = fullscreen;
		}
	}
	else if (!isFullscreen) {
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		SDL_RenderSetLogicalSize(app_->getRenderer(), supportedResolutions_[currentResolution_].w, supportedResolutions_[currentResolution_].h); //para que se redimensionen a su proporcion
		fullscreen_ = fullscreen;
	}
}

void WindowManager::setResolution(int resIndex)
{
	if (fullscreen_) {
		SDL_RenderSetLogicalSize(app_->getRenderer(), supportedResolutions_[resIndex].w, supportedResolutions_[resIndex].h); //para que se redimensionen a su proporcion
		currentResolution_ = resIndex;
	}
}

void WindowManager::setBrightness(float brightness)
{
	SDL_SetWindowBrightness(window, brightness); // si a alguien se le queda la pantalla oscura, que ponga aqu� un 1 y descomente lo de abajo
	//int b = 0;
	//int a = 1 / b;
	currentBrightness_ = brightness;
}
