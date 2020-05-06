#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include "HitboxData.h"
#include "Entity.h"
class Bullet : public Component
{
public:
	Bullet(uint16 playerNumber,Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact = false);
	virtual ~Bullet() {}
	virtual void init() override;
	//void update() override;
protected:
	PhysicsTransform* transform_ = nullptr;
	Vector2D speed_;
	int damage_;
	int hitstun_;
	int timeAlive_;
	Vector2D knockBack_;
	bool destroyInContact_ = false;
	int playerNumber_;
};

