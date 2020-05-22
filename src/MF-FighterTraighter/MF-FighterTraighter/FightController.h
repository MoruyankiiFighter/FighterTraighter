#pragma once
#include "Component.h"
class FightController :
	public Component
{
public:
	FightController(int roundIniTime, int roundEndTime) : Component(ecs::FightController), ini_timer(roundIniTime), roundEndTime_(roundEndTime) {}

	void init() override;
	void update() override;

	void PlayerLost(int playerNumber);

	virtual ~FightController() {}
protected:
	int playerLost_ = -1; // -1 = round is still going, 0 = leftPlayer, 1 = rightPlayer

	Entity* msgEnt = nullptr;
	bool showInitialMessage = true;
	int roundEndTime_;
	int end_timer = 0;
	int ini_timer = 0;

	//allows the players to perform any action
	void disablePlayers(bool mode);

	//displays a message in the middle of the screen
	void displayMessage(string msg);
};
