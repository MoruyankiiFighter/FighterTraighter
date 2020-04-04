#pragma once
#include "OnHit.h"
#include <iostream>
#include "PlayerState.h"
#include "PlayerAttacks.h"
class FloorOnHit : public OnHit
{
public:
	FloorOnHit() : OnHit() {}
	~FloorOnHit() {}
	void onHit(b2Fixture* fixture) override {
		Entity* player = static_cast<Entity*>(fixture->GetUserData());
		PlayerState* currState = player->getComponent<PlayerState>(ecs::PlayerState);

		if ( currState->isJumping()) {
			if (currState->isAttacking()) player->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
			currState->goLanding(25);
			
		}
	}
};
