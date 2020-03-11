#pragma once
#include "Box2D/Box2D.h"
#include "Entity.h"
#include "PunchingBagCollision.h"

class PunchingBagListener : public b2ContactListener
{
public:
	PunchingBagListener() : b2ContactListener() {}
	~PunchingBagListener() {}
	//similar to OnCollision
	void BeginContact(b2Contact* contact) {
		//check if fixture A was was the punching bag
		void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		PunchingBagCollision* pbCol = dynamic_cast<PunchingBagCollision*>(static_cast<Entity*>(bodyUserData)->getComponent<PunchingBagCollision>(ecs::PunchingBagCollision));
		if (pbCol != nullptr) {
			pbCol->OnCollision();
		}

		//check if fixture B was was the punching bag
		bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		pbCol = dynamic_cast<PunchingBagCollision*>(static_cast<Entity*>(bodyUserData)->getComponent<PunchingBagCollision>(ecs::PunchingBagCollision));
		if (pbCol != nullptr) {
			pbCol->OnCollision();
		}
	}
	//called at the end of a collision
	void EndContact(b2Contact* contact) {}
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {}
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {}
};

