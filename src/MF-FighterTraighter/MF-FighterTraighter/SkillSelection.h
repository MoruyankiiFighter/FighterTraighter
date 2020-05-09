#pragma once
#include "GameState.h"

class SkillSelection: public GameState
{

public:
	SkillSelection(App* app) : GameState(app) { init(); }

	void init() override;

	static void GoToNextSubMenu(App* app);
	static void Pressed1(App* app);
	static void Pressed2(App* app);
private:
	bool win1=false;

};

