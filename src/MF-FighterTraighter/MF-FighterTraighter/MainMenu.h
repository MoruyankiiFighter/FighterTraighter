#pragma once
#include "GameState.h"
#include "Texture.h"
class App;

class MainMenu : public GameState
{
public:
	//constructor
	MainMenu(App* app);
	//destructor
	virtual ~MainMenu();
	
	//method overrided from GameState
	void init() override;

	//Funciones botones
	static void GoArcade(App* app);
	static void Go1v1(App* app);
	static void GoOptions(App* app);
	static void Leave(App* app);

private:
	//Entitys of the buttons
	Entity* arcade;
	Entity* pvp;
	Entity* options;
	Entity* exit;
};
