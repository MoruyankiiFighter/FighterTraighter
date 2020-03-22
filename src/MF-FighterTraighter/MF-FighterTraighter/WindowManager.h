#pragma once
#include <vector>
#include <SDL.h>
class App;

class WindowManager
{
public:
	WindowManager(App* app);
	WindowManager(WindowManager&) = delete;
	WindowManager& operator= (WindowManager&) = delete;

	void setFullscreen(bool fullscreen);
	void setResolution(int resIndex);
	void setBrightness(float brightness);

	const SDL_DisplayMode& getCurResolution() { return supportedResolutions_[currentResolution_]; }
	int getCurResolutionIndex() { return currentResolution_; }
	int getAvailableResolutions() { return supportedResolutions_.size(); }
	bool getFullscreen() { return fullscreen_; }
	float getCurBrightness() { return currentBrightness_; }

	virtual ~WindowManager() {}
protected:
	App* app_;
	std::vector<SDL_DisplayMode> supportedResolutions_;
	int currentResolution_ = 0;
	float currentBrightness_ = 1;
	bool fullscreen_ = true;
};

