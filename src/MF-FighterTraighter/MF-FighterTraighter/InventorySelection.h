#pragma once
#include "GameState.h"
class InventorySelection :
	public GameState
{
public:
	InventorySelection(App* app) : GameState(app) { init(); }
	void init() override;

	static void SetSkill(App* app, int n);
private:

};

