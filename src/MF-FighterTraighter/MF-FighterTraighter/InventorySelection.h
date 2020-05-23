#pragma once
#include "GameState.h"
class InventorySelection :
	public GameState
{
public:
	InventorySelection(App* app) : GameState(app) { init(); }
	~InventorySelection() {};
	void init() override;

private:

};

