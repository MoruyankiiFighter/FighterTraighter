#pragma once
#include "GameState.h"
class InventorySelection :
	public GameState
{
public:
	InventorySelection(App* app): GameState(app) {}

	void init() override;

private:

};

