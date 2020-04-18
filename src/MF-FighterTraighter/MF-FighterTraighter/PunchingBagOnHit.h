#pragma once
#include "OnHit.h"
#include <iostream>
#include "Entity.h"
#include "Health.h"
class PunchingBagOnHit : public OnHit
{
public:
	PunchingBagOnHit() : OnHit() {}
	~PunchingBagOnHit() {}
	void onHit(b2Fixture* fixture) override {
		entity_->getComponent<Health>(ecs::Health)->LoseLife(30);
	}
};

