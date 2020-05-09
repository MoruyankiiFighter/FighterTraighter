#pragma once
#include "GameState.h"

class SkillSelection: public GameState
{

public:
	SkillSelection(App* app) : GameState(app) { init(); }

	void init() override;

	static void GoToFight(App* app);

private:
	bool win1=false; //necesito que el gm diga quien ha ganau o perdiu
};

