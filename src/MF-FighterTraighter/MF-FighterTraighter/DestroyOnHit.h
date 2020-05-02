#pragma once
#include "HitboxData.h"
class DestroyOnHit:  public HitboxData
{
public:
	DestroyOnHit(int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, Entity* e, bool destroy = false) :
		HitboxData(damage, time, hitstun, knockback, guardbreaker, id, e, destroy){}
	virtual void onHit(/*b2Fixture* other*/) {
		HitboxData::onHit(/*other*/);
		//destruye la hitbox
		entity_->getState()->getEntityManager().removeEntity(entity_);
	}
	virtual ~DestroyOnHit() {}
};