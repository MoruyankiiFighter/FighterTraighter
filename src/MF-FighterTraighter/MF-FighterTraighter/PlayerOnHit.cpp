#include "PlayerOnHit.h"
#include "Health.h"
#include "HitboxData.h"

void PlayerOnHit::onHit(b2Fixture* fixture)
{
	unsigned int damage= static_cast<HitboxData*>(fixture->GetUserData())->damage_;
	entity_->getComponent<Health>(ecs::Health)->LoseLife(damage);
	cout << "Hago " << damage << " de damage en PlayerOnHit" << endl;
}

