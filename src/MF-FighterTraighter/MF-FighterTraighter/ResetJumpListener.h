#pragma once
#include "Box2D/Box2D.h"
#include "EntityData.h"
#include "PlayerState.h"
#include "PlayerAttacks.h"
#include "PlayerController.h"
#include "HitboxData.h"
//Handles collisions
//overlaps and kinematic interactions are handled 
//by the gameState hitbox system
class ResetJumpListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact) override {
	// if 1st fixture is the player, and 2nd fixture is the floor
		void* v_data = contact->GetFixtureA()->GetUserData();
		//if the fixture has some data
		if (v_data) {
			//if it has, it has to be a UserData subClass
			UserData* data = static_cast<UserData*>(v_data);
			//if its the player, it is an EntityData
			EntityData* e_data = dynamic_cast<EntityData*>(data);
			if (e_data != nullptr) {
				PlayerState* currState = e_data->entity_->getComponent<PlayerState>(ecs::PlayerState);
				//if the entity is a player, handles the its landing
				if (currState != nullptr
				&& contact->GetFixtureB()->GetFilterData().categoryBits == 1	//if it collides with boundary (floor)
				&& currState->isAirborne()
				&& contact->GetFixtureA()->GetBody()->GetLinearVelocity().y >= 0) {
					e_data->entity_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
					currState->goLanding(11 + (currState->getHoldingFrames()) * 0.8);
				}
				/*-----Podemos poner la fricción del saco y de las paredes en 0, o solo de las paredes y poco al saco-----*/
				//if the entity collides with walls or the punching bag
				if (currState != nullptr && (contact->GetFixtureB()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureB()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)
					if (e_data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
						e_data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);
					}
					else if (e_data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
						e_data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
					}
				}
			}
		}
		//the same but with the other object
		v_data = contact->GetFixtureB()->GetUserData();
		if (v_data) {
			//if it has, it has to be a UserData subClass
			UserData* data = static_cast<UserData*>(v_data);
			//if its the player, it is an EntityData
			EntityData* e_data = dynamic_cast<EntityData*>(data);
			if (e_data != nullptr) {
				PlayerState* currState = e_data->entity_->getComponent<PlayerState>(ecs::PlayerState);
				//if the entity is a player, handles the its landing
				if (currState != nullptr
					&& contact->GetFixtureA()->GetFilterData().categoryBits == 1	//if it collides with boundary (floor)
					&& currState->isAirborne()
					&& contact->GetFixtureB()->GetBody()->GetLinearVelocity().y >= 0) {
					e_data->entity_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
					currState->goLanding(11 + (currState->getHoldingFrames()) * 0.8);
				}
				/*-----Podemos poner la fricción del saco y de las paredes en 0, o solo de las paredes y poco al saco-----*/
				//if the entity collides with walls or the punching bag
				if (currState != nullptr && (contact->GetFixtureA()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureA()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)
					if (e_data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
						e_data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);
					}
					else if (e_data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
						e_data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
					}
				}
			}
		}
	}


	void EndContact(b2Contact* contact) override {

		// if 1st fixture is the player, and 2nd fixture is the floor
		void* v_data = contact->GetFixtureA()->GetUserData();
		//if the fixture has some data
		if (v_data) {
			//if it has, it has to be a UserData subClass
			UserData* data = static_cast<UserData*>(v_data);
			//if its the player, it is an EntityData
			EntityData* e_data = dynamic_cast<EntityData*>(data);
			if (e_data != nullptr) {
				PlayerState* currState = e_data->entity_->getComponent<PlayerState>(ecs::PlayerState);
				if (currState != nullptr && (contact->GetFixtureB()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureB()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)

					//if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
					e_data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(false);
					//}
					//else if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
					e_data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(false);
					//}
				}
			}
		}

		v_data = contact->GetFixtureB()->GetUserData();
		if (v_data) {
			//if it has, it has to be a UserData subClass
			UserData* data = static_cast<UserData*>(v_data);
			//if its the player, it is an EntityData
			EntityData* e_data = dynamic_cast<EntityData*>(data);
			if (e_data != nullptr) {
				PlayerState* currState = e_data->entity_->getComponent<PlayerState>(ecs::PlayerState);
				if (currState != nullptr && (contact->GetFixtureA()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureA()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)

					//if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
					e_data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(false);
					//}
					//else if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
					e_data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(false);
					//}
				}
			}
		}
	}
	

};

