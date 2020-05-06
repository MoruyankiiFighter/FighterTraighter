#pragma once
#include "DestroyOnHit.h"
#include "PlayerData.h"
#include "BulletGravity.h"

class FallOnHit : public DestroyOnHit
{
public:
	FallOnHit(int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, Entity* e, bool destroyInContact = false) :
		DestroyOnHit(damage, time, hitstun, knockback, guardbreaker, id, e, destroyInContact) {}
	virtual void onHit(b2Fixture* other) {
		UserData* data = static_cast<UserData*>(other->GetUserData());
		if (data) {
			if (data->entity_->getComponent<PlayerData>(ecs::PlayerData)){//other is player
				BulletGravity* bullet = entity_->getComponent<BulletGravity>(ecs::Bullet);
				//phTr->setSpeed(Vector2D(0, phTr->getSpeed().getY()));
				bullet->changeSpeed(Vector2D(0,bullet->getSpeed().getY()));
				entity_->getComponent<PhysicsTransform>(ecs::Transform)->changeMask(entity_->getState()->NONE);

			}
			else {
				DestroyOnHit::onHit(other);
				//entity_->getComponent<PhysicsTransform>(ecs::Transform)->changeMask(entity_->getState()->NONE);
			}
		}
	}
	virtual ~FallOnHit() {}
};

