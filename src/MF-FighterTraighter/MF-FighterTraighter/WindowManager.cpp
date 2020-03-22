#include "WindowManager.h"
#include "App.h"
#include "consts.h"

WindowManager::WindowManager(App* app) : app_(app) {
	int numResolutions = SDL_GetNumDisplayModes(0); // first display
	supportedResolutions_.reserve(numResolutions);
	SDL_DisplayMode curr;
	int j = SDL_GetCurrentDisplayMode(0, &curr);
	for (int i = 0; i < numResolutions; ++i) {
		SDL_DisplayMode mode;
		SDL_GetDisplayMode(0, i, &mode);
		supportedResolutions_.emplace_back(mode);
		if (&mode == &curr) currentResolution_ = i;
	}
	setFullscreen(true);
	setResolution(currentResolution_);
	cout << numResolutions << endl;
}

void WindowManager::setFullscreen(bool fullscreen)
{
	bool isFullscreen = SDL_GetWindowFlags(app_->getWindow()) & SDL_WINDOW_FULLSCREEN_DESKTOP;
	if (!fullscreen) {
		if (isFullscreen) {
			SDL_SetWindowFullscreen(app_->getWindow(), 0);
			fullscreen_ = fullscreen;
		}
	}
	else if (!isFullscreen) {
		SDL_SetWindowFullscreen(app_->getWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);
		SDL_RenderSetLogicalSize(app_->getRenderer(), supportedResolutions_[currentResolution_].w, supportedResolutions_[currentResolution_].h); //para que se redimensionen a su proporcion
		fullscreen_ = fullscreen;
	}
}

void WindowManager::setResolution(int resIndex)
{
	if (fullscreen_) {
		SDL_RenderSetLogicalSize(app_->getRenderer(), supportedResolutions_[resIndex].w, supportedResolutions_[resIndex].h); //para que se redimensionen a su proporcion
		cout << "setResolution" << endl;
		currentResolution_ = resIndex;
	}
}

void WindowManager::setBrightness(float brightness)
{
	SDL_SetWindowBrightness(app_->getWindow(), brightness); // si a alguien se le queda la pantalla oscura, que ponga aquí un 1 y descomente lo de abajo
	//int b = 0;
	//int a = 1 / b;
	currentBrightness_ = brightness;
}
