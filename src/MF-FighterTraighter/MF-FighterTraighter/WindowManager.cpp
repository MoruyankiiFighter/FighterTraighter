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
		if (&mode == &curr) currentResolution = i;
	}
	setFullscreen(true);
	setResolution(currentResolution);
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
	else if(!isFullscreen) {
		SDL_SetWindowFullscreen(app_->getWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);
		SDL_RenderSetLogicalSize(app_->getRenderer(), supportedResolutions_[currentResolution].w, supportedResolutions_[currentResolution].h); //para que se redimensionen a su proporcion
		fullscreen_ = fullscreen;
	}
}

void WindowManager::setResolution(int resIndex)
{
	if (fullscreen_) {
		SDL_RenderSetLogicalSize(app_->getRenderer(), supportedResolutions_[resIndex].w, supportedResolutions_[resIndex].h); //para que se redimensionen a su proporcion
		cout << "setResolution" << endl;
		currentResolution = resIndex;
	}
}
