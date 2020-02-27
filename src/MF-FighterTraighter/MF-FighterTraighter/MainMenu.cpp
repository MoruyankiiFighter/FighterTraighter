#include "MainMenu.h"


MainMenu::MainMenu(App* app, Transform* arcButt, Transform* oneVsone, Transform* exit, Transform* options) : GameState(app) {
	//cargar texturas de botones del menu principal
	arcadeButton = new Button(arcButt, nullptr/*app->getTexture()*/, this, ArcadeCallback);
	onevsoneButton = new Button(oneVsone, nullptr/*app->getTexture()*/, this, OnevsOneCallback);
	exitButton = new Button(exit, nullptr/*app->getTexture()*/, this, ExitCallback);
	optionsButton = new Button(options, nullptr/*app->getTexture()*/, this, OptionsCallback);
}