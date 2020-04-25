#pragma once
#include "UserData.h"
#include "Vector2D.h"

class HitboxData : virtual public UserData
{
public:
	HitboxData(int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, bool destroy = false) :
		damage_(damage), time_(time), hitstun_(hitstun), knockBack_(knockback), guardBreaker_(guardbreaker), destroy_(destroy) {}
	virtual ~HitboxData() {}
	//virtual void onHit() {}
	int damage_ = -1,
		time_ = -1,
		hitstun_ = -1;
	Vector2D knockBack_; //Assuming looking to the right
	bool guardBreaker_ = false;
	bool destroy_ = false;//if its true it means that it has to be destroyed
	/*destroyOnHit = false,//if its true dont destroy de entity on Hit, destroy it later (its for proyectiles)
	 destroyEntity = false;//if its true destroy de entity (its for abilities)*/
};

