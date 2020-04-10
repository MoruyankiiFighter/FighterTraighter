#include "PlayerOnHit.h"
#include "Health.h"
#include "PhysicsTransform.h"
#include "PlayerState.h"
#include "HitboxData.h"
#include "PlayerAttacks.h"

void PlayerOnHit::onHit(b2Fixture* fixture)
{
	HitboxData* hBox_data = static_cast<HitboxData*>(fixture->GetUserData());

	//cout << "Hago " << hBox_data->damage_ << " de damage en PlayerOnHit" << endl;
	PhysicsTransform* pT = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	Health* helth = entity_->getComponent<Health>(ecs::Health);
	if (!currState->isProtected() /*&& !hBox_data->guardBreaker*/) {
		if (currState->isAttacking()) entity_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
		helth->LoseLife(hBox_data->damage_);
		if (hBox_data->knockBack_.getY() >= 0)	//vertical knockback, goes to airborne hitstun
			currState->goHitsun(hBox_data->hitstun_);
		else
			currState->goHitstunAirborne(hBox_data->hitstun_);
		
		pT->getBody()->ApplyLinearImpulse(b2Vec2(hBox_data->knockBack_.getX(), hBox_data->knockBack_.getY()), pT->getBody()->GetWorldCenter(), true);
		cout << "Hago X:" << hBox_data->knockBack_.getX() << " Y: " << hBox_data->knockBack_.getY() << endl;
	}
	else {
		if (hBox_data->guardBreaker) {
			currState->goHitsun(hBox_data->hitstun_);
		}
		else currState->goGuardingStun(hBox_data->hitstun_ * 0.75);
		helth->LoseLife(hBox_data->damage_ * 0.1);
		pT->getBody()->ApplyLinearImpulse(b2Vec2((hBox_data->knockBack_.getX() + hBox_data->knockBack_.getX()) * 0.015, 0), pT->getBody()->GetWorldCenter(), true);
		cout << "He bloqueado daño pero estoy en hitstun" << endl;
	}
}

