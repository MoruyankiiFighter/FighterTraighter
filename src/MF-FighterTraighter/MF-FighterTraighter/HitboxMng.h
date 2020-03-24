#pragma once
#include "hitbox.h"
#include "Vector2D.h"
#include <list>
#include "Hitbox.h"
#include "Box2D/Box2D.h"

class App;

class HitboxMng 
{
public:
	//constructor
	HitboxMng(App* app) :app_(app) {}
	HitboxMng(HitboxMng&) = delete;
	HitboxMng& operator= (HitboxMng&) = delete;
	//destructor
	virtual ~HitboxMng() {}
	
	void update();
	//create a hitbox with parameters
	void addHitbox(Vector2D pos, int width, int height, int time, int damage, b2Body* body);
private:
	std::list<b2Fixture*> hitboxList_; //current active hitbxes
	std::list<b2Fixture*> hitboxListToRemove_;//hitboxes that will be deleted
	App* app_;

};

