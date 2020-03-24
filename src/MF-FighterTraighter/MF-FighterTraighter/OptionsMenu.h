#pragma once
#include "GameState.h"
#include "Texture.h"

class OptionsMenu:public GameState
{
public:
	OptionsMenu(App* app);
	virtual ~OptionsMenu();

	void init() override;



	static void GoBackCallback(App* app);

	static void SetBright(App* app, double value);
	static void MoreBright(App* app);
	static void LessBright(App* app);

	static void SetVolume(App* app, double value);

	//fullscreen
	static void fullScreen(App* app);

	static void setResolution(App* app, double value);

private:
	Entity* reg_bright; //button for regulate the slider
	Entity* b_slider;
};

