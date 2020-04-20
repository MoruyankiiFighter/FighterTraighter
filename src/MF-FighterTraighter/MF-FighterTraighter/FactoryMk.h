#pragma once
#include "Entity.h"
#include "Box2D\Box2D.h"

class App;

class FactoryMk
{
public:
	static Entity* addMkToGame(App* app, GameState* state, int orientation, std::vector<SDL_Scancode> keys, b2World* world, bool gamePad,uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, int dyn = 0, int playerNumber = 0);
private:
	FactoryMk() = delete;
	~FactoryMk() {};
};