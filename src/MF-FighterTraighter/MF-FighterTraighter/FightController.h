#pragma once
#include "Component.h"
class FightController :
	public Component
{
public:
	FightController(int roundEndTime) : Component(ecs::FightController), roundEndTime_(roundEndTime) {}

	void update() override;

	void PlayerLost(int playerNumber);

	virtual ~FightController() {}
protected:
	int playerLost_ = -1; // -1 = round is still going, 0 = leftPlayer, 1 = rightPlayer

	int roundEndTime_;
	int timer = 0;
};

