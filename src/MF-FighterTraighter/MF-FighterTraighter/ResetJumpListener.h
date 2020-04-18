#pragma once
#include "Box2D/Box2D.h"
#include "Entity.h"
#include "PlayerState.h"
#include "PlayerAttacks.h"
#include "PlayerController.h"
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
				currState->goLanding(11 + (currState->getHoldingFrames()) * 0.8);
		}

		if (currState != nullptr && (contact->GetFixtureB()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureB()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)

			if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
				player->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);
			}
			else if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
				player->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
			}
		}


		player = static_cast<Entity*>(contact->GetFixtureB()->GetUserData());
		currState = player->getComponent<PlayerState>(ecs::PlayerState);	
		if (currState != nullptr
			&& contact->GetFixtureA()->GetFilterData().categoryBits	== 1	//if it collides with boundary (floor)
			&& currState->isAirborne()
			&& contact->GetFixtureB()->GetBody()->GetLinearVelocity().y >= 0) {
			player->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
			if (currState->isHitstun()) {
				currState->goHitLanding(16);
			}
			else currState->goLanding(10);
		}

		if (currState != nullptr && (contact->GetFixtureA()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureA()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with walls

			if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
				player->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);
			}
			else if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
				player->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
			}
		}
	}


	void EndContact(b2Contact* contact) override {

		// if 1st fixture is the player, and 2nd fixture is the floor
		Entity* player = static_cast<Entity*>(contact->GetFixtureA()->GetUserData());
		PlayerState* currState = player->getComponent<PlayerState>(ecs::PlayerState);
		

		if (currState != nullptr && (contact->GetFixtureB()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureB()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)

			//if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
				player->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(false);
			//}
			//else if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
				player->getComponent<PlayerController>(ecs::PlayerController)->wallRight(false);
			//}
		}


		player = static_cast<Entity*>(contact->GetFixtureB()->GetUserData());
		currState = player->getComponent<PlayerState>(ecs::PlayerState);
		

		if (currState != nullptr && (contact->GetFixtureA()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureA()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with walls

			//if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
				player->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(false);
			//}
			//else if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
				player->getComponent<PlayerController>(ecs::PlayerController)->wallRight(false);
			//}
		}
	}
	

};

