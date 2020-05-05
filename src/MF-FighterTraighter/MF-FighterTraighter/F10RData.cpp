#include "F10RData.h"

F10RData::F10RData(double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, double speed, double ini_health, double attack, double defense, int playerNumber):
	PlayerData(width, height, rotation, jump_impulse, ini_pos, speed, ini_health, attack, defense, playerNumber) {
	animLength_ = { {4, true, 12}, {3, true, 15}, {2, true, 3}, {1, true, 15}, {2, false, 2}, {4, false, 10}, {4, false, 10}, {5, false, 8},
	{3, false, 7}, {4, false, 13}, {4, false, 10}, {4, false, 7}, {5, false, 15}, {2, true, 15}, {2, false, 10}, {2, true, 4}, {2, false, 10},
	{2, false, 3}, {2, true, 12}, {2, false, 7}, {3, false, 7}, {4, true, 15}, {3, true, 10} };
}

void F10RData::init()
{
}
