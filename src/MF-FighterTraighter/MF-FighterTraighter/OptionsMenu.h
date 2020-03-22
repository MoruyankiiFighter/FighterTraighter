#pragma once
#include "GameState.h"
#include "Texture.h"

/// C A L L B A C K S ///

void GoBackCallback(App* app);

void SetBright(App* app, double value);
void MoreBright(App* app);
void LessBright(App* app);

void SetVolume(App* app, double value);

//fullscreen
void fullScreen(App* app);

void setResolution(App* app, double value);

class OptionsMenu:public GameState
{
public:
	OptionsMenu(App* app);
	virtual ~OptionsMenu();

	void init() override;
private:
	Entity* reg_bright; //button for regulate the slider
	Entity* b_slider;
};

