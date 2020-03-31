#include "PlayerOnHit.h"
#include "Health.h"
#include "HitboxData.h"
#include <iostream>
#include "Jump.h"
#include "PlayerState.h"
#include "PlayerAttacks.h"

void PlayerOnHit::onHit(b2Fixture* fixture, b2Fixture* mainfixture)
{
	Entity* entity = static_cast<Entity*>(mainfixture->GetUserData());
	unsigned int damage= static_cast<HitboxData*>(fixture->GetUserData())->damage_;

	entity->getComponent<Health>(ecs::Health)->LoseLife(damage);
	cout << "Hago " << damage << " de damage en PlayerOnHit" << endl;
}
