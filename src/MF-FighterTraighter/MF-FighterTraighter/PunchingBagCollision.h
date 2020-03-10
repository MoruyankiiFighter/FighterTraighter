#pragma once
#include "Box2D/Box2D.h"
#include <iostream>
class PunchingBagCollision : b2ContactListener
{
	//similar a OnCollision
	virtual void BeginContact(b2Contact* contact) {
		void* bodyUserData = contact->GetFixtureA()->GetUserData();
	}
	//Se llama al finalizar la colision
	virtual void EndContact(b2Contact* contact);
};

