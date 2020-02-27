#pragma once
#include "GameState.h"
#include "Button.h"
class MainMenu : public GameState
{

private:
	static const std::string s_menuID;
	Button* arcadeButton;
	Button* onevsoneButton;
	Button* optionsButton;
	Button* exitButton;
	vector<Texture*>buttons;
public:
	MainMenu(App* app, Transform* arcButt, Transform* oneVsone, Transform* exit, Transform* options);
	virtual std::string getStateID() const { return s_menuID; };
};



