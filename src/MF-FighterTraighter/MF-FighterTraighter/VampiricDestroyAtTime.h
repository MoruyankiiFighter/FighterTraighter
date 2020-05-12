#pragma once
#include "DestroyAtTime.h"
#include "Health.h"

class VampiricDestroyAtTime : public DestroyAtTime
{
public:
	VampiricDestroyAtTime(double damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, Entity* e, double healAmount, bool mHit = false) :
		DestroyAtTime(damage, time, hitstun, knockback, guardbreaker, id, e, mHit), healAmount_(healAmount) {
	}
	virtual void onHit(b2Fixture* other) {
		DestroyAtTime::onHit(other);
		UserData* data = static_cast<UserData*>(other->GetUserData());
		if (data) {
			if (data->entity_ == data->entity_->getState()->getEntityManager().getHandler(ecs::Player1)) {
				Health* playerHealth = data->entity_->getState()->getEntityManager().getHandler(ecs::Player2)->getComponent<Health>(ecs::Health);
				playerHealth->GainLife((playerHealth->getMaxHealth() - playerHealth->getHealth()) * healAmount_);
			}
			else {
				Health* playerHealth = data->entity_->getState()->getEntityManager().getHandler(ecs::Player1)->getComponent<Health>(ecs::Health);
				playerHealth->GainLife((playerHealth->getMaxHealth() - playerHealth->getHealth()) * healAmount_);
			}
		}
	}
	virtual ~VampiricDestroyAtTime() {}
private:
	double healAmount_;
};