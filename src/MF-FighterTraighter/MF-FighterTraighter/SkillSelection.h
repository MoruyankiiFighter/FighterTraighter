#pragma once
#include "GameState.h"

class SkillSelection: public GameState
{
public:
	SkillSelection(App* app) : GameState(app) { init(); }

	void init() override;
	void handleInput() override;
	
	void createFirstMenu();

	void createInventoryMenu();


private:
//	vector<Entity*> hab_; //todas las habilidades que genere el saco????
	bool win1 = false;

};

