#pragma once
#include "GameState.h"
class InventorySelection :
	public GameState
{
public:
	InventorySelection(App* app) : GameState(app) { init(); }
	void init() override;

	static void SetFirstSkill(App* app, int n);
	static void SetSecondSkill(App* app, int n);

	static void GoToFight(App* app);


private:

};

