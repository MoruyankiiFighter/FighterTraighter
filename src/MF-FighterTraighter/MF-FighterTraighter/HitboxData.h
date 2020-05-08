#pragma once
#include "UserData.h"
#include "Vector2D.h"

class HitboxData :  public UserData
{
public:
	HitboxData(int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, Entity* e, bool destroyInContact = false, bool mHit = false) : UserData(e),
		damage_(damage), time_(time), hitstun_(hitstun), knockBack_(knockback), guardBreaker_(guardbreaker), id_(id), destroyInContact_(destroyInContact), multiHit_(mHit){}
	virtual ~HitboxData() {}
	virtual void onHit(b2Fixture* other) {
		if (!multiHit_ && !destroy_) {			
			entity_->getState()->killHitbox(it_, id_);
			destroy_ = true;
		}
	}
	void setIt(std::list<b2Fixture*>::iterator i) {
		it_ = i;
	}
	std::list<b2Fixture*>::iterator it_; 
	unsigned int id_ = 1;
	int damage_ = -1,
		time_ = -1,
		hitstun_ = -1;
	Vector2D knockBack_; //Assuming looking to the right
	bool guardBreaker_ = false;
	bool destroy_ = false;//if its true it means that it has to be destroyed
	bool destroyInContact_ = false;
	bool multiHit_ = false;	//si la hitbox es multiHit, solo se destruye cuando pasa su tiempo
};

