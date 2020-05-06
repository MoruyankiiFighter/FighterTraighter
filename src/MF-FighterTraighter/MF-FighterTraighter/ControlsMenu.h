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
	void initString();
	//callback
	static void GoBack(App* app);
	static void ChangeControl(App*app,int index,int control);

	std::vector<std::tuple<Entity*, Entity*> >botones;
	int index;
	string predet[16];
	string predetMando[8];
	string texto[16];

	

};

