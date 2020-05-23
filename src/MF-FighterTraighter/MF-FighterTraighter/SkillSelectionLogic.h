#pragma once
#include "Component.h"
#include "NavigationController.h"
class SkillSelectionLogic :
	public Component
{
public:
	SkillSelectionLogic(NavigationController* nav, int player, vector<GameManager::AbilityID> v);
	~SkillSelectionLogic();
	void init() override;
	void update() override;
	void render() override;
	void handleInput() override;

	inline bool getPressed() { return pressed; }

private:
	Entity* ent;

	int player_;
	NavigationController* nav_;
	
	GameManager::AbilityID op;

	vector<GameManager::AbilityID> v_;


	bool eq;
	bool pressed;
};

