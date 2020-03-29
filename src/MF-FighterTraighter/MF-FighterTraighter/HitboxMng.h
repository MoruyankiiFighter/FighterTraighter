#pragma once

#include "Vector2D.h"
#include <list>
#include <vector>
#include "HitboxData.h"
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
	void addHitbox(Vector2D pos, int width, int height, int time, int damage, Vector2D knockBack, b2Body* body, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF);
	void addMainHitbox(b2Fixture* fixt) { mainHitboxes.push_back(fixt); }
	void addFloorHitbox(b2Fixture* fixt) { floorFixture_ =fixt; }

	bool checkOverlap(b2Fixture* a, b2Fixture* other) {
		return b2TestOverlap(a->GetAABB(0), other->GetAABB(0));
	}
private:
	std::vector<b2Fixture*> mainHitboxes;	//to get the main fixtures of the players and the punching bag to check overlaps
	std::list<b2Fixture*> hitboxList_;
	std::list<b2Fixture*> hitboxListToRemove_;
	b2Fixture* floorFixture_ = nullptr;
	App* app_;
};

