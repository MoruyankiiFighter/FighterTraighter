#include "F10RData.h"

F10RData::F10RData(double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, double speed, double ini_health, double attack, double defense, int playerNumber):
	PlayerData(width, height, rotation, jump_impulse, ini_pos, speed, ini_health, attack, defense, playerNumber) {
	animLength_ = { {4, true, 12}, {4, true, 15}, {2, true, 3}, {1, true, 15}, {4, false, 2}, {12, false, 10}, {7, false, 10}, {9, false, 8},
	{15, false, 7}, {7, false, 13}, {9, false, 10}, {10, false, 7}, {5, false, 15}, {2, true, 15}, {2, false, 10}, {3, true, 4}, {2, false, 10},
	{2, false, 3}, {4, true, 12}, {2, false, 7}, {2, false, 7}, {2, true, 15}, {8, true, 10} };
}

void F10RData::init()
{
}
