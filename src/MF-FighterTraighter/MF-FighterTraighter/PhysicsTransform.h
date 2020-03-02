#pragma once
#include "Transform.h"
#include "Box2D\Box2D.h"

class PhysicsTransform :
	public Transform
{
	PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, bool dyn = true);
	PhysicsTransform();
	virtual ~PhysicsTransform();
	// get and set for position
	const Vector2D& getPosition() const { return Vector2D(body_->GetTransform().p.x, body_->GetTransform().p.y); }
	void setPosition(const Vector2D& v) {/* body_->SetTransform(b2Vec2());*/ }
	void setPosition(double x, double y) { body_->SetTransform({ (float32)x,(float32)y }, body_->GetAngle()); }

	//get and set for speed
	const Vector2D& getSpeed() const { /*return speed_;*/ return { body_->GetLinearVelocity().x,body_->GetLinearVelocity().y }; }
	void setSpeed(const Vector2D& v) { /*speed_ = v;*/ }
	void setSpeed(double x, double y) { body_->SetLinearVelocity({ (float32)x,(float32)y }); }

	// get and set for width and height
	double getWidth() const { return width_; }
	double getHeight() const { return height_; }

	void setWidth(double width);
	void setHeight(double height);

	void setWidthHeight(double width, double height);

	//get and set for rotation
	double getRotation() { return body_->GetTransform().q.GetAngle(); }
	void setRotation(double rotation) { body_->SetTransform(body_->GetTransform().p, rotation); }
private:
	b2Body* body_;
};

