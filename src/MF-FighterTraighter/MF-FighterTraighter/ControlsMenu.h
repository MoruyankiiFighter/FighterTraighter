#pragma once

#include "GameState.h"
#include "Texture.h"
#include <vector>
class App;

class ControlsMenu:public GameState
{
public:
	//constructor
	ControlsMenu(App* app);

	//destructor
	virtual ~ControlsMenu();

	//methods overrided from GameState where we create the entitys
	void init() override;
	void handleInput() override;
	void change();
	void initString();
	//callback
	static void GoBack(App* app);
	static void ChangeControl(App*app,int index);

	std::vector<std::tuple<Entity*, Entity*> >botones;
	int index;
	string predet[12];
	string texto[12];

	

};

