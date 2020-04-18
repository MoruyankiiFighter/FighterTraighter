#pragma once

#include "Vector2D.h"
#include <list>
#include <vector>
#include <array>
#include "HitboxData.h"
#include "Box2D/Box2D.h"

class App;
using uint = unsigned int;
using namespace std;

class HitboxMng 
{
	//	Collision filters for the b2d collision
	enum CollisionFilters : uint16 {
		BOUNDARY = 0x0001,
		PLAYER_1 = 0x0002,
		PLAYER_2 = 0x0004,
		P_BAG = 0X008,
		EVERYTHING = 0XFFFF
	};
public:
	//constructor
	HitboxMng(App* app) :app_(app) {}
	HitboxMng(HitboxMng&) = delete;
	HitboxMng& operator= (HitboxMng&) = delete;
	//destructor
	virtual ~HitboxMng() {}
	
	void update();
	void addHitbox(Vector2D pos, int width, int height, int time, int damage, int hitstun, Vector2D knockBack, b2Body* body, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, bool guardBreaker=false);
	void addHurtbox(b2Fixture* fixt) { mainHurtboxes.push_back(fixt); }

	bool checkOverlap(b2Fixture* a, b2Fixture* other) {
		return b2TestOverlap(a->GetAABB(0), other->GetAABB(0));
	}
	void resetGroup(int group);
	void clear();
private:
	App* app_;
};

