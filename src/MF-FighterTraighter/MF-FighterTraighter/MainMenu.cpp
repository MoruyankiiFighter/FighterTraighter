#include "MainMenu.h"


MainMenu::MainMenu(App* app, Transform* arcButt, Transform* oneVsone, Transform* exit, Transform* options) : GameState(app) {
	//cargar texturas de botones del menu principal
	buttons.at(0)->load("logofightertraighter.png", 1, 1);
	buttons.at(1)->load("buttons.png", 3, 1);
	
	arcadeButton = new Button(arcButt, buttons.at(1)/*app->getTexture()*/, this, ArcadeCallback);
	onevsoneButton = new Button(oneVsone, buttons.at(1)/*app->getTexture()*/, this, OnevsOneCallback);
	exitButton = new Button(exit, buttons.at(1)/*app->getTexture()*/, this, ExitCallback);
	optionsButton = new Button(options, buttons.at(1)/*app->getTexture()*/, this, OptionsCallback);
	scene.emplace_back(arcadeButton);
	scene.emplace_back(onevsoneButton);
	scene.emplace_back(exitButton);
	scene.emplace_back(optionsButton);
}