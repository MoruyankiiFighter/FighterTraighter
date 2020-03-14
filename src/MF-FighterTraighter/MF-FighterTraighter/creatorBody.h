#pragma once
#include "Component.h"
#include "Box2D\Box2D.h"
#include "Transform.h"
#include "Vector2D.h"
#include "Hitbox.h"
class creatorBody : public Component
{
public:
	creatorBody(Transform* transform, b2World* world);
	~creatorBody() {}
	void update() override;
	void createHitbox(Vector2D pos,int width, int height, int time, int damage, Vector2D dir);
	void createMultiHitbox(Vector2D pos,int width, int height, int time, int damage, Vector2D dir, int numHitbox) {}
private:
	Transform* transform_;
	b2World* world_;	//puntero al mundo para destruirse
	b2Body* body_;
	int time_ = 0;
	b2Fixture* fixture_= nullptr;
};

