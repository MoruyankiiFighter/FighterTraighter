#pragma once
#include "Vector2D.h"
//#include "Entity.h"
struct HitboxData 
{
public:
	int damage_ = -1,
		time_ = -1,
		hitstun_ = -1;
	Vector2D knockBack_; //Assuming looking to the right
	bool guardBreaker = false,
	 destroy = false,//if its true it means that it has to be destroyed
	 destroyOnHit = false,//if its true dont destroy de entity on Hit, destroy it later (its for proyectiles)
	 destroyEntity = false;//if its true destroy de entity (its for abilities)
	Entity* entity = nullptr;
};

