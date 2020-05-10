#pragma once
#include "GameState.h"
class InventorySelection :
	public GameState
{
public:
	InventorySelection(App* app) : GameState(app) { init(); }
	void init() override;

	static void SetFirstSkill(App* app, int n);
	void SetSecondSkill(App* app, int n);
private:

};

