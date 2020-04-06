#pragma once
#include "GameState.h"
#include "Texture.h"

class OptionsMenu:public GameState
{
public:
	//constructor
	OptionsMenu(App* app);
	//destructor
	virtual ~OptionsMenu();

	//method overrided from GameState where the objects are created from the different factories
	void init() override;


	//callbacks of the Entitys
	
	//go to the state that was before
	static void GoBackCallback(App* app);
	
	//go to movements/controls menu
	static void GoMovementsCallback(App* app);

	//change the brightness
	static void SetBright(App* app, double value);
	
	//add brightness if it's possible
	static void MoreBright(App* app);
	
	//substract brightness if it's posible
	static void LessBright(App* app);
	
	//changes the volume
	static void SetVolume(App* app, double value);

	//fullscreen
	static void fullScreen(App* app);
	
	//changes the resolution
	static void setResolution(App* app, double value);	
};

