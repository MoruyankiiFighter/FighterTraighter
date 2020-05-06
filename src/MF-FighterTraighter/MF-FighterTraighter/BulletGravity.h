#pragma once
#include "Bullet.h"
class BulletGravity : public Bullet
{
public:
	BulletGravity(uint16 playerNumber, Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact = false);
	virtual ~BulletGravity() {}
	//void init() override;
	void update() override;
	//void update() override;

};

