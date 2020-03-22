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

	virtual ~WindowManager() {}
protected:
	App* app_;
	std::vector<SDL_DisplayMode> supportedResolutions_;
	int currentResolution = 0;
	bool fullscreen_ = true;
};

