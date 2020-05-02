#pragma once
#include "Box2D/Box2D.h"
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
		void* v_data2 = contact->GetFixtureB()->GetUserData();
		//if the fixture has some data
		if (v_data) {
			//if it has, it has to be a UserData class/subClass
			UserData* data = static_cast<UserData*>(v_data);

			if (data != nullptr) {
				PlayerState* currState = data->entity_->getComponent<PlayerState>(ecs::PlayerState);
				//if the entity is a player, handles the its landing
				if (currState != nullptr
				&& contact->GetFixtureB()->GetFilterData().categoryBits == 1	//if it collides with boundary (floor)
				&& currState->isAirborne()
				&& contact->GetFixtureA()->GetBody()->GetLinearVelocity().y >= 0) {
					data->entity_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
					currState->goLanding(11 + (currState->getHoldingFrames()) * 0.8);
				}
				//PLAYER_1 = 0x0002,
				//PLAYER_2 = 0x0004,
				/*-----Podemos poner la fricción del saco y de las paredes en 0, o solo de las paredes y poco al saco-----*/
				//if the entity collides with walls or the punching bag
				/*if (currState != nullptr && (contact->GetFixtureB()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureB()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)
					if (data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
						data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);
					}
					else if (data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
						data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
					}
				}*/
				if (v_data2 != nullptr) {
					UserData* data2 = static_cast<UserData*>(v_data2);
					if (data2 != nullptr) {
						PlayerState* currState2 = data2->entity_->getComponent<PlayerState>(ecs::PlayerState);

						if (currState != nullptr && currState2 != nullptr) {	//if it collides with boundary (floor)
							PhysicsTransform* Pt1 = data->entity_->getComponent<PhysicsTransform>(ecs::Transform);
							PhysicsTransform* Pt2 = data2->entity_->getComponent<PhysicsTransform>(ecs::Transform);
							PlayerController* Pc1 = data->entity_->getComponent<PlayerController>(ecs::PlayerController);
							PlayerController* Pc2 = data2->entity_->getComponent<PlayerController>(ecs::PlayerController);
							//if (abs(Pt1->getSpeed().getY()) > 0.1 || abs(Pt2->getSpeed().getY()) > 0.1) {//not both on the floor
							if (!data->entity_->getComponent <PlayerState>(ecs::PlayerState)->canCrouch() || !data2->entity_->getComponent <PlayerState>(ecs::PlayerState)->canCrouch()) {
								
								//Pt1->changeFriction(0.1);
								//Pt2->changeFriction(0.1);
								//Pc1->wallRight(true);
								//Pc2->wallLeft(true);
							}
							/*else if(!data2->entity_->getComponent <PlayerState>(ecs::PlayerState)->canCrouch()) {
								Pt2->changeFriction(0); Pt1->changeFriction(0);
							}*/
								/*if(!data2->entity_->getComponent <PlayerState>(ecs::PlayerState)->canCrouch()){
								if (Pt1->getPosition().getX() < Pt2->getPosition().getX())
								{
									data2->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);
									data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
								}
								else {
									data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
									data2->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);

								}*/
							//}
						}

					}

				}
			}
		}
		//the same but with the other object
		v_data = contact->GetFixtureB()->GetUserData();
		v_data2 = contact->GetFixtureA()->GetUserData();
		if (v_data) {
			//if it has, it has to be a UserData subClass
			UserData* data = static_cast<UserData*>(v_data);
			//if its the player, it is an EntityData
			if (data != nullptr) {
				PlayerState* currState = data->entity_->getComponent<PlayerState>(ecs::PlayerState);
				//if the entity is a player, handles the its landing
				if (currState != nullptr
					&& contact->GetFixtureA()->GetFilterData().categoryBits == 1	//if it collides with boundary (floor)
					&& currState->isAirborne()
					&& contact->GetFixtureB()->GetBody()->GetLinearVelocity().y >= 0) {
					data->entity_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
					currState->goLanding(11 + (currState->getHoldingFrames()) * 0.8);
				}
				/*-----Podemos poner la fricción del saco y de las paredes en 0, o solo de las paredes y poco al saco-----*/
				//if the entity collides with walls or the punching bag
				//if (currState != nullptr && (contact->GetFixtureA()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureA()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)
				//	if (data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
				//		data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);
				//	}
				//	else if (data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
				//		data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
				//	}
				//}
				/*if (v_data2 != nullptr) {
					UserData* data2 = static_cast<UserData*>(v_data2);
					if (data2 != nullptr) {
						PlayerState* currState2 = data2->entity_->getComponent<PlayerState>(ecs::PlayerState);

						if (currState != nullptr && currState2 != nullptr) {	//if it collides with boundary (floor)
							if (data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getPosition().getX() <
								data2->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getPosition().getX())
							{
								data2->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);
								data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
							}
							else {//if (data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() >= 0) {
								data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(true);
								data2->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(true);

							}
						}

					}
				}*/
			}
		}
	}

	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override {
		//contact->SetEnabled(!bothPlayerCollide);
	}
	void EndContact(b2Contact* contact) override {

		// if 1st fixture is the player, and 2nd fixture is the floor
		void* v_data = contact->GetFixtureA()->GetUserData();
		void* v_data2 = contact->GetFixtureB()->GetUserData();

		//if the fixture has some data
		if (v_data) {
			//if it has, it has to be a UserData subClass
			UserData* data = static_cast<UserData*>(v_data);
			//if its the player, it is an EntityData
			//if (data != nullptr) {
			//	PlayerState* currState = data->entity_->getComponent<PlayerState>(ecs::PlayerState);
			//	if (currState != nullptr && (contact->GetFixtureB()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureB()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)

			//		//if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
			//		data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(false);
			//		//}
			//		//else if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
			//		data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(false);
			//		//}
			//	}
			//}
			if (v_data2 != nullptr) {
				PlayerState* currState = data->entity_->getComponent<PlayerState>(ecs::PlayerState);
				UserData* data2 = static_cast<UserData*>(v_data2);
				if (data2 != nullptr) {
					PlayerState* currState2 = data2->entity_->getComponent<PlayerState>(ecs::PlayerState);

					if (currState != nullptr && currState2 != nullptr) {	//if it collides with boundary (floor)
						
						PhysicsTransform* Pt1 = data->entity_->getComponent<PhysicsTransform>(ecs::Transform);
						PhysicsTransform* Pt2 = data2->entity_->getComponent<PhysicsTransform>(ecs::Transform);
						PlayerController* Pc1 = data->entity_->getComponent<PlayerController>(ecs::PlayerController);
						PlayerController* Pc2 = data2->entity_->getComponent<PlayerController>(ecs::PlayerController);

						//if (abs(Pt1->getSpeed().getY()) > 0.1 || abs(Pt2->getSpeed().getY()) > 0.1) {//not both on the floor
						//if (!data->entity_->getComponent <PlayerState>(ecs::PlayerState)->canCrouch() || !data2->entity_->getComponent <PlayerState>(ecs::PlayerState)->canCrouch()) {
							//Pt1->changeFriction(1);
						//}
						//else if (!data2->entity_->getComponent <PlayerState>(ecs::PlayerState)->canCrouch()) {
							//Pt2->changeFriction(1);
							//Pc1->wallRight(false);
							//Pc2->wallLeft(false);

						//}
						/*if (data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getPosition().getX() <
							data2->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getPosition().getX())
						{
							data2->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(false);
							data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(false);
						}
						else {//if (data->entity_->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() >= 0) {
							data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(false);
							data2->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(false);

						}*/
					}

				}

			}
		}
		/*
		v_data = contact->GetFixtureB()->GetUserData();
		if (v_data) {
			//if it has, it has to be a UserData subClass
			UserData* data = static_cast<UserData*>(v_data);
			//if its the player, it is an EntityData
			if (data != nullptr) {
				PlayerState* currState = data->entity_->getComponent<PlayerState>(ecs::PlayerState);
				//if (currState != nullptr && (contact->GetFixtureA()->GetFilterData().categoryBits == 0x0010 || contact->GetFixtureA()->GetFilterData().categoryBits == 0x0008)) {	//if it collides with boundary (floor)

				//	//if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() < 0) {
				//	data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallLeft(false);
				//	//}
				//	//else if (player->getComponent<PhysicsTransform>(ecs::Transform)->getSpeed().getX() > 0) {
				//	data->entity_->getComponent<PlayerController>(ecs::PlayerController)->wallRight(false);
				//	//}
				//}
			}
		}*/
	}
private:
	bool bothPlayerCollide = false; //kk

};

