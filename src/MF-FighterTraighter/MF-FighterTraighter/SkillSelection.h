#pragma once
#include "GameState.h"
#include "GameManager.h"
#include <vector>

//class GameManager;
class SkillSelection: public GameState
{

public:
	
	SkillSelection(App* app, int winner) : GameState(app), winner_(winner) { init(); }

	void init() override;

	static void GoToNextSubMenu(App* app);
	static void Pressed1(App* app);
	static void Pressed2(App* app);
private:
	int winner_;

	GameManager::AbilityID	op1_, op2_;
	std::vector<GameManager::AbilityID>	generatedAbs_1, generatedAbs_2;
	bool checkAbility(GameManager::AbilityID newAb, int player);
};

