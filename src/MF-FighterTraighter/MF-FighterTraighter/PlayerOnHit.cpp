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

void PlayerOnHit::onHitAlt(b2Fixture* fixture)
{
	//Según entiendo, este método se llama cuando a un jugador LE DAN, no cuando da
	//Por ello, y para que todos los onHit tengan los mismo parámetros (una fixture), 
	//¿no sería mejor esto? Lo hablamos

	unsigned int damage = static_cast<HitboxData*>(fixture->GetUserData())->damage_;
	entity_->getComponent<Health>(ecs::Health)->LoseLife(damage);
	cout << "Hago " << damage << " de damage en PlayerOnHit" << endl;
}
