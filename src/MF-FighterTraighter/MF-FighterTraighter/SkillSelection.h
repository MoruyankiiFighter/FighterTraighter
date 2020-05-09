#pragma once
#include "GameState.h"

class SkillSelection: public GameState
{

public:
	SkillSelection(App* app) : GameState(app) { init(); }

	void init() override;


private:

};

