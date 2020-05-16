#include "LastHit_Wins.h"
#include "Health.h"
#include "HitboxData.h"

void LastHit_Wins::onHit(b2Fixture* other)
{
	HitboxData* other_data = static_cast<HitboxData*>(other->GetUserData());
	last_hit = other_data->entity_;
	Health* h = entity_->getComponent<Health>(ecs::Health);
	h->LoseLife(other_data->damage_);
	// saco died
	if (h->getHealth() == 0) {
		//entity_->getApp()->getGameManager()->trainingEnded();
		int winner = other_data->entity_->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber();		//esto solo funciona si las hitbox no son proyectiles, hay que cambiarlo si no
		entity_->getApp()->getGameManager()->trainingEnded(winner);
	}
}

int LastHit_Wins::drawWinner() {
	return last_hit->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber();
}