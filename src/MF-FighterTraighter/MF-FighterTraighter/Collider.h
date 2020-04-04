#pragma once
#include "Component.h"
#include "Box2D\Box2D.h"

class Collider : public Component
{
public:
	Collider(double width, double height, b2Body* body);
	virtual ~Collider() {}
	void init() override;
	void setWidth(double width);
	void setHeight(double width);
	void setWidthHeight(double width, double height);
	b2Fixture* getCollider() { return collider_; }

private:
	b2Body* body_;
	uint16 cBits_, mBits_;	//por ahora, no se usa
	b2Fixture* collider_;
	double width_ = 0,
			height_ = 0;
	void reset(const b2PolygonShape& shape);
};