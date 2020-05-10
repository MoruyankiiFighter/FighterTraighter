#pragma once
#include "Entity.h"
#include "Box2D\Box2D.h"
#include "GameManager.h"

class App;

class CharFactory
{
public:
	static Entity* addCharacterToGame(App* app, GameState* state, int orientation, b2World* world, const GameManager::PlayerInfo* character, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, int playerNumber = 0);
private:
	//static Entity* addMkToGame(App* app, GameState* state, int orientation, HID* hid, b2World* world, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, int playerNumber = 0);
	//static Entity* addMockToGame(App* app, GameState* state, int orientation, HID* hid, b2World* world, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, int playerNumber = 0);
	CharFactory() = delete;
	~CharFactory() {};
};