#pragma once
#include "GameState.h"
#include "Texture.h"
#include <string>

class PauseMenu: public GameState
{

public:

	//constructor
	PauseMenu(App* app) : GameState(app) {
		std::cout << "Pausado" << endl;
		init();
	};
	//destructor
	~PauseMenu() {}

	//methods overrided from GameState
	void init() override;
	
	//Callbacks of pause
	//Resume the game
	static void Resume(App* app);
	//quit the game and goes to main menu
	static void GoMainMenu(App* app);
	//show the moves
	static void ShowMeYourMoves(App* app);
	//go to options
	static void GoOptions(App* app);
};

