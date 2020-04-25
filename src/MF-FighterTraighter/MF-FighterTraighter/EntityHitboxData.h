#pragma once
#include "EntityData.h"
#include "HitboxData.h"
class EntityHitboxData:  public HitboxData, public EntityData
{
public:
	EntityHitboxData(Entity* e, int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, bool destroy = false) : 
		EntityData(e), 
		HitboxData(damage, time, hitstun, knockback, guardbreaker, destroy){}
	//virtual void onHit();
	virtual ~EntityHitboxData() {}
};

