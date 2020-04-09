#pragma once
#include "PlayerData.h"
class MkWH00PData : public PlayerData
{
public:
	MkWH00PData(std::vector<SDL_Scancode> keys, double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, Vector2D speed, double ini_health, double attack, double defense) :
	PlayerData(keys, width, height, rotation, jump_impulse, ini_pos, speed, ini_health, attack, defense){}
	virtual ~MkWH00PData() {}

private:
	//Moves Callbacks
	static void NP1(Entity* ent);
	static void HP1(Entity* ent);
	static void NK1(Entity* ent);
	static void NK2(Entity* ent);
	static void HK1(Entity* ent);
	static void ANP1(Entity* ent);
	static void ANP2(Entity* ent);
	static void AHP1(Entity* ent);
	static void ANK1(Entity* ent);
	static void ANK2(Entity* ent);
	static void AHK1(Entity* ent);
	static void GB(Entity* ent);
};

