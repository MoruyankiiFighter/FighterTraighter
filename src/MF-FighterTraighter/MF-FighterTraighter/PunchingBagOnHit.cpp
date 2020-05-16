#include "PunchingBagOnHit.h"
#include "Health.h"
#include "HitboxData.h"
void PunchingBagOnHit::onHit(b2Fixture* other)
{
	HitboxData* other_data = static_cast<HitboxData*>(other->GetUserData());

	Health* h = entity_->getComponent<Health>(ecs::Health);
	h->LoseLife(other_data->damage_);
	// saco died
	if (h->getHealth() == 0) {
		//entity_->getApp()->getGameManager()->trainingEnded();
		entity_->getApp()->getGameManager()->trainingEnded(0);
	}
}
