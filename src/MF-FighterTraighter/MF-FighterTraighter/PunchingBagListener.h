#pragma once
#include "Box2D/Box2D.h"
#include "Entity.h"
#include "PunchingBagCollision.h"
#include "PlayerAttacks.h"
class PunchingBagListener : public b2ContactListener
{
public:
	PunchingBagListener() : b2ContactListener() {}
	~PunchingBagListener() {}
	//similar to OnCollision
	void BeginContact(b2Contact* contact);
	//called at the end of a collision
	void EndContact(b2Contact* contact) {}
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {}
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {}
};

