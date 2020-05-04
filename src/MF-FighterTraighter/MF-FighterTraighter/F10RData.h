#pragma once
#include "PlayerData.h"

class F10RData : public PlayerData
{
public:
	F10RData(double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, double speed, double ini_health, double attack, double defense, int playerNumber);
	virtual ~F10RData() {}
	void init() override;
private:
};