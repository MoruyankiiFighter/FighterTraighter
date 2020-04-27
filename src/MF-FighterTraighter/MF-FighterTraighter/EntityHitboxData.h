#pragma once
#include "EntityData.h"
#include "HitboxData.h"
class EntityHitboxData:  public HitboxData, public EntityData
{
public:
	EntityHitboxData(Entity* e, int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, GameState* state, bool destroy = false) : 
		EntityData(e), 
		HitboxData(damage, time, hitstun, knockback, guardbreaker, id, state, destroy){}
	virtual void onHit() {
		HitboxData::onHit();
		EntityData::onHit();
	}
	virtual ~EntityHitboxData() {}
};

