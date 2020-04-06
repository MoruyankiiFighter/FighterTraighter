#pragma once
#include <vector>
#include <SDL.h>
class App;

class WindowManager
{
public:
	//constructor
	WindowManager(App* app);
	WindowManager(WindowManager&) = delete;
	WindowManager& operator= (WindowManager&) = delete;

	//destructor
	virtual ~WindowManager() { SDL_DestroyWindow(window); }

	//set fullscreen or window
	void setFullscreen(bool fullscreen);

	//change the resolution between the possible ones
	void setResolution(int resIndex);

	//change the brightness
	void setBrightness(float brightness);

	//return the window
	inline SDL_Window* getWindow() const { return window; }

	//get the current resolution
	inline const SDL_DisplayMode& getCurResolution() { return supportedResolutions_[currentResolution_]; }

	//get the position in the supported resolution vector
	inline int getCurResolutionIndex() { return currentResolution_; }

	//get the number of resolutions that are supported in the computer 
	inline int getAvailableResolutions() { return supportedResolutions_.size(); }

	//returns true if it's the fullscreen on
	inline bool getFullscreen() { return fullscreen_; }

	//returns the current brightness
	inline float getCurBrightness() { return currentBrightness_; }

	inline const std::vector<SDL_DisplayMode>& getSupportedResolutions() { return supportedResolutions_; }
	
protected:
	App* app_;
	SDL_Window* window;

	std::vector<SDL_DisplayMode> supportedResolutions_;

	int currentResolution_ = 0;
	float currentBrightness_ = 1;
	SDL_DisplayMode initialDisplayMode_;

	bool fullscreen_ = true;
};

