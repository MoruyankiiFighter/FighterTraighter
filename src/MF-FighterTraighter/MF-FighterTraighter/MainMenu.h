#pragma once
#include "GameState.h"
#include "Texture.h"
#include <vector>
class App;

class MainMenu : public GameState
{
public:
	//constructor
	MainMenu(App* app);
	//destructor
	virtual ~MainMenu();

	//methods overrided from GameState where we create the entitys
	void init() override;

	//Callbacks for the buttons
	static void GoArcade(App* app);
	static void Go1v1(App* app);
	static void GoOptions(App* app);
	static void Leave(App* app);

private:
	int buttonSel = 0;
};
