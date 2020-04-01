#pragma once
#include "Component.h"
#include "Box2D\Box2D.h"

class Collider : public Component
{
	Collider(double width, double height);
	virtual ~Collider() {}
	void init() override;
	void setWidth(double width);
	void setHeight(double width);
	void setWidthHeight(double width, double height);

private:
	b2Body* body_;
	uint16 cBits_, mBits_;
	b2Fixture* collider_;
	double width_ = 0,
			height_ = 0;
	void reset(const b2PolygonShape& shape);
};

