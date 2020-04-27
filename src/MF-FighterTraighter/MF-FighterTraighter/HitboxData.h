#pragma once
#include "UserData.h"
#include "Vector2D.h"
#include "GameState.h"

class HitboxData :  public UserData
{
	
public:
	HitboxData(int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, GameState* state, bool destroy = false) :
		damage_(damage), time_(time), hitstun_(hitstun), knockBack_(knockback), guardBreaker_(guardbreaker), id_(id), destroy_(destroy), state_(state){}
	virtual ~HitboxData() {}
	virtual void onHit() {
		if (!destroy_) {
			state_->killHitbox(it_, id_);
			destroy_ = true;
		}
	}
	void setIt(std::list<b2Fixture*>::iterator i) {
		it_ = i;
	}
	GameState* state_;
	std::list<b2Fixture*>::iterator it_; 
	unsigned int id_ = 1;
	int damage_ = -1,
		time_ = -1,
		hitstun_ = -1;
	Vector2D knockBack_; //Assuming looking to the right
	bool guardBreaker_ = false;
	bool destroy_ = false;//if its true it means that it has to be destroyed
	/*destroyOnHit = false,//if its true dont destroy de entity on Hit, destroy it later (its for proyectiles)
	 destroyEntity = false;//if its true destroy de entity (its for abilities)*/
};

