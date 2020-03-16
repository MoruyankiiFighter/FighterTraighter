#pragma once
#include "GameState.h"
#include "Texture.h"

/// C A L L B A C K S ///

void GoBackCallback(App* app);

void SetBright(App* app, double value);
void SetVolume(App* app, double value);


//fullscreen
void fullScreen(App* app);

void MenuCallback(App* app);


class OptionsMenu:public GameState
{
public:
	OptionsMenu(App* app);
	virtual ~OptionsMenu();

	void init() override;
};

