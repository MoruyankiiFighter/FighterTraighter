#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include "HitboxData.h"
#include "Entity.h"
class Bullet : public Component
{
public:
	Bullet(GameState* state, uint16 playerNumber,Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact = false);

	void init() override;
private:
	PhysicsTransform* transform_ = nullptr;
	Vector2D speed_;
	int damage_;
	int hitstun_;
	int timeAlive_;
	Vector2D knockBack_;
	bool destroyInContact_ = false;
	int playerNumber_;
	GameState* state_;
};

