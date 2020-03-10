#pragma once
#include "GameState.h"
#include "Texture.h"

class App;

//brightness
void moreBright(App* app);
void lessBright(App* app);

//volume music
void moreVolume(App* app);
void lessVolume(App app);

//SFXVolume
void moreSFXVolume(App* app);
void lessSFXVolume(App* app);

//fullscreen
void fullScreen(App* app);




class OptionsMenu:public GameState
{
public:
	OptionsMenu(App* app);
	virtual ~OptionsMenu();

	void init() override;
	virtual void update() override;
	virtual void render() override;
	void handleInput();
};

