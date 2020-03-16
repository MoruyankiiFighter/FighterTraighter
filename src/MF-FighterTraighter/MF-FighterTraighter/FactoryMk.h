#pragma once
#include "Entity.h"
#include "Box2D\Box2D.h"

class App;

class FactoryMk
{
public:
	static Entity* addMkToGame(App* app, b2World* world);
	static void moveHurt();
private:
	FactoryMk() = delete;
	~FactoryMk() {};
};

