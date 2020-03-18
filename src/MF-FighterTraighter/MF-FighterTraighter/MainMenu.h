#pragma once
#include "GameState.h"
#include "Texture.h"
#include <vector>
class App;

class MainMenu : public GameState
{
public:
	MainMenu(App* app);
	virtual ~MainMenu();
	void init();
	void update();

	//Callbacks main menu
	static void GoArcade(App* app);
	static void Go1v1(App* app);
	static void GoOptions(App* app);
	static void Leave(App* app);

private:

	//vector<Entity*> buttons;
	int buttonSel = 0;
};
