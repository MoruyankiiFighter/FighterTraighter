#pragma once
#include "GameState.h"
class CharacterSelection: public GameState
{

public:
	//constructor
	CharacterSelection(App* app) : GameState(app) { init(); }

	//init overrided from GameState
	void init() override;
private:

};

