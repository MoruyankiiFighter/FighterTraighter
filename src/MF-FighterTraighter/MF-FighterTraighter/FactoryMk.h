#pragma once
#include "Entity.h"
#include "Box2D\Box2D.h"

class App;

class FactoryMk
{
public:
	static Entity* addMkToGame(App* app, GameState* state, b2World* world, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, bool dyn = true);
	static void NP1(Entity* ent);
	static void HP1(Entity* ent);
	static void NK1(Entity* ent);
	static void NK2(Entity* ent);
	static void HK1(Entity* ent);
	//static void HK2(Entity* ent);
private:
	FactoryMk() = delete;
	~FactoryMk() {};
};

