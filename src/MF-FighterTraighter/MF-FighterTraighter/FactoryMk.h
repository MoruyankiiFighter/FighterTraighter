#pragma once
#include "Entity.h"
#include "Box2D\Box2D.h"

class App;

class FactoryMk
{
public:
	static Entity* addMkToGame(App* app, GameState* state, int orientation, HID* hid, b2World* world, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, int playerNumber = 0);
	static Entity* addMockToGame(App* app, GameState* state, int orientation, HID* hid, b2World* world, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, int playerNumber = 0);
private:
	FactoryMk() = delete;
	~FactoryMk() {};
};