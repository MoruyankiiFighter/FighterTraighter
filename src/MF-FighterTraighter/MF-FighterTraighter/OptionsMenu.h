#pragma once
#include "GameState.h"
#include "Texture.h"

/// C A L L B A C K S ///

void GoBackCallback(App* app);

void SetBright(App* app);
void SetVolume(App* app);


//brightness
void moreBright(App* app);
void lessBright(App* app);

//SFXVolume
void moreSFXVolume(App* app);
void lessSFXVolume(App* app);

//fullscreen
void fullScreen(App* app);

void MenuCallback(App* app);


class OptionsMenu:public GameState
{
public:
	OptionsMenu(App* app);
	virtual ~OptionsMenu();

	void init() override;
	virtual void update() override;

private:
	float current_volume = 0;
	float current_bright = 0;
	Entity* reg_bright;
	Entity* reg_volume;

};

