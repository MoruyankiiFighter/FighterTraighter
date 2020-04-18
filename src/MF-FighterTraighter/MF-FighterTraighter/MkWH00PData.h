#pragma once
#include "PlayerData.h"
class MkWH00PData : public PlayerData
{
public:
	MkWH00PData(std::vector<SDL_Scancode> keys, double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, Vector2D speed, double ini_health, double attack, double defense, int playerNumber);
	virtual ~MkWH00PData() {}
	void init() override;
private:
	//Moves Callbacks
	//lista de vectores pero no se
	static void NP1(Entity* ent);
	CallbackData np1;
	static void HP1(Entity* ent);
	CallbackData hp1;
	static void NK1(Entity* ent);
	CallbackData nk1;
	static void NK2(Entity* ent);
	CallbackData nk2;
	static void HK1(Entity* ent);
	CallbackData hk1;
	static void ANP1(Entity* ent);
	CallbackData anp1;
	static void ANP2(Entity* ent);
	CallbackData anp2;
	static void AHP1(Entity* ent);
	CallbackData ahp1;
	static void ANK1(Entity* ent);
	CallbackData ank1;
	static void ANK2(Entity* ent);
	CallbackData ank2;
	static void AHK1(Entity* ent);
	CallbackData ahk1;
	static void GB(Entity* ent);
};

