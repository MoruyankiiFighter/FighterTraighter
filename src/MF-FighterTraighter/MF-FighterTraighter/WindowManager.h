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

	inline SDL_Window* getWindow() const { return window; }
	inline const SDL_DisplayMode& getCurResolution() { return supportedResolutions_[currentResolution_]; }
	inline int getCurResolutionIndex() { return currentResolution_; }
	inline int getAvailableResolutions() { return supportedResolutions_.size(); }
	inline bool getFullscreen() { return fullscreen_; }
	inline float getCurBrightness() { return currentBrightness_; }

	virtual ~WindowManager() { SDL_DestroyWindow(window); }
protected:
	App* app_;
	std::vector<SDL_DisplayMode> supportedResolutions_;
	int currentResolution_ = 0;
	float currentBrightness_ = 1;
	bool fullscreen_ = true;
	SDL_Window* window;
};

