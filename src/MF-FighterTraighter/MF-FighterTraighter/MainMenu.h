#pragma once
#include "GameState.h"
#include "Texture.h"
class App;

class MainMenu : public GameState
{
public:
	MainMenu(App* app);
	virtual ~MainMenu();
	void init();
	void update();

	//Funciones botones
	static void GoArcade(App* app);
	static void Go1v1(App* app);
	static void GoOptions(App* app);
	static void Leave(App* app);

private:
	Entity* arcade;
	Entity* pvp;
	Entity* options;
	Entity* exit;

	vector<Entity*> buttons;
	int buttonSel = 0;
};
