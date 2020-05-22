#pragma once
#include "Component.h"
#include "NavigationController.h"
class SkillSelectionLogic :
	public Component
{
public:
	SkillSelectionLogic(NavigationController* nav, int player);
	SkillSelectionLogic(NavigationController* nav, int player, const vector<GameManager::AbilityID>& v);
	~SkillSelectionLogic();
	void init() override;
	void update() override;
	void render() override;
	void handleInput() override;

private:
	int player_;
	NavigationController* nav_;
	GameManager::AbilityID curr;
	GameManager::AbilityID op;
	vector<GameManager::AbilityID> v_;
	bool eq;
};

