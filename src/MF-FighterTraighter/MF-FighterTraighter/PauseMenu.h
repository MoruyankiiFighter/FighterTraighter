#pragma once
#include "GameState.h"
#include "Texture.h"
#include <string>

//callbacks para el menu de pausa
class PauseMenu: public GameState
{

public:
	PauseMenu(App* app) : GameState(app) {
		std::cout << "Pausado" << endl;
		init();
	};
	~PauseMenu() {}

	void init();

	static void Resume(App* app);
	static void GoMainMenu(App* app);
	static void ShowMeYourMoves(App* app);
	static void GoOptions(App* app);
};

