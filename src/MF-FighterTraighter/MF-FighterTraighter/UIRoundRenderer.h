#pragma once
#include "Component.h"
class UIRoundRenderer :
	public Component
{
public:
	UIRoundRenderer(std::vector<Entity*> images) : Component(ecs::UIRoundRenderer), images_(images) {}

	void setRoundsWon(int rounds);
protected:
	uint roundsWon_;
	std::vector<Entity*> images_;
};

