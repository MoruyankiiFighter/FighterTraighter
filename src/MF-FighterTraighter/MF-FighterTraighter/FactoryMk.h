#pragma once
#include "Entity.h"
#include "Box2D\Box2D.h"

class App;

class FactoryMk
{
public:
	static Entity* addMkToGame(App* app, GameState* state, b2World* world, int orientation, std::vector<SDL_Scancode> keys, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, bool dyn = true);
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
	//static void HK2(Entity* ent);
private:
	FactoryMk() = delete;
	~FactoryMk() {};
};