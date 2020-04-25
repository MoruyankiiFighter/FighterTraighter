#pragma once
#include "EntityData.h"
#include "HitboxData.h"
class EntityHitboxData: public EntityData, public HitboxData
{
	EntityHitboxData(Entity* e, int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, bool destroy = false) : 
		EntityData(e), 
		HitboxData(damage, time, hitstun, knockback, guardbreaker, destroy){}
	//virtual void onHit();
};

