#pragma once
#include "Entity.h"
#include "Box2D\Box2D.h"

class App;

class FactoryMk
{
public:
	
	static Entity* addMkToGame(App* app, GameState* state, b2World* world);
	static void moveHurt(Entity* ent);
private:
	//fake constructor
	FactoryMk() = delete;
	//destructor
	~FactoryMk() {};
};

