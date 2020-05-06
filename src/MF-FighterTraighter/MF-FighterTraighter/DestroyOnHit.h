#pragma once
#include "HitboxData.h"
#include "PhysicsTransform.h"
class DestroyOnHit:  public HitboxData
{
public:
	DestroyOnHit(int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, Entity* e, bool destroyInContact = false) :
		HitboxData(damage, time, hitstun, knockback, guardbreaker, id, e, destroyInContact){}
	virtual void onHit(b2Fixture* other) {
		//destroy the hitbox by contact
		if (destroyInContact_) {
			HitboxData::onHit(other);
			entity_->getState()->getEntityManager().removeEntity(entity_);
		}
		else {//if we dont want to destroy the hitbox in contact
			if (time_ <= 0) {//destroy it when his time is 0 
				HitboxData::onHit(other);
				entity_->getState()->getEntityManager().removeEntity(entity_);
			}
			//the hitbox doesnt collide with anything
			else
			{//maybe detect if we want multihits
				entity_->getComponent<PhysicsTransform>(ecs::Transform)->changeMask(entity_->getState()->NONE);
			}
		}
	}
	virtual ~DestroyOnHit() {}
};