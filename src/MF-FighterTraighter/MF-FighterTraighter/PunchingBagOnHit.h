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
		HitboxData* hBox_data = static_cast<HitboxData*>(fixture->GetUserData());

		Health* h = entity_->getComponent<Health>(ecs::Health);
		h->LoseLife(hBox_data->damage_);
		// saco died
		if (h->getHealth() == 0) {
			app_->getGameManager()->trainingEnded();
		}
	}
};

