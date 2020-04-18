#pragma once
#include "Entity.h"
#include "Box2D\Box2D.h"

class App;

class FactoryMk
{
public:
	static Entity* addMkToGame(App* app, GameState* state, b2World* world, int orientation, std::vector<SDL_Scancode> keys, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, bool dyn = true, int playerNumber = 0);
private:
	FactoryMk() = delete;
	~FactoryMk() {};
};