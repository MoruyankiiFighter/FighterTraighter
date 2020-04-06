#pragma once
#include "Box2D/Box2D.h"
#include "Entity.h"
#include "PlayerState.h"
#include "PlayerAttacks.h"
class ResetJumpListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact) override {
		// if 1st fixture is the player, and 2nd fixture is the floor
		Entity* player = static_cast<Entity*>(contact->GetFixtureA()->GetUserData());
		PlayerState* currState = player->getComponent<PlayerState>(ecs::PlayerState);	
		if (currState != nullptr
			&& contact->GetFixtureB()->GetFilterData().categoryBits	== 1	//if it collides with boundary (floor)
			&& currState->isAirborne() 
			&& contact->GetFixtureA()->GetBody()->GetLinearVelocity().y >= 0) {
				player->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
				currState->goLanding(25);
		}

		player = static_cast<Entity*>(contact->GetFixtureB()->GetUserData());
		currState = player->getComponent<PlayerState>(ecs::PlayerState);	
		if (currState != nullptr
			&& contact->GetFixtureA()->GetFilterData().categoryBits	== 1	//if it collides with boundary (floor)
			&& currState->isAirborne()
			&& contact->GetFixtureB()->GetBody()->GetLinearVelocity().y >= 0) {
				currState->goLanding(25);
				player->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();

		}

	}
};

