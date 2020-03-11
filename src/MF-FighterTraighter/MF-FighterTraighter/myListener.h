#pragma once
#include "Box2D/Box2D.h"
#include <iostream>
class Fight;
class myListener : public b2ContactListener
{
public:
	myListener(Fight* fight);
	~myListener() {}
private:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	Fight* fight_ = nullptr;

};

