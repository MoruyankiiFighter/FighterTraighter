#pragma once
#include "Transform.h"
#include "Box2D\Box2D.h"

class PhysicsTransform : public Transform
{
public:
	PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, bool dyn = true);
	//PhysicsTransform();
	virtual ~PhysicsTransform();
	// get and set for position
	virtual const Vector2D& getPosition() const {
		Vector2D pos { body_->GetTransform().p.x, body_->GetTransform().p.y };
		return  pos;
	}
	virtual void setPosition(const Vector2D& v) {/* body_->SetTransform(b2Vec2());*/ }
	virtual void setPosition(double x, double y) { body_->SetTransform({ (float32)x,(float32)y }, body_->GetAngle()); }

	//get and set for speed
	virtual const Vector2D& getSpeed() const { /*return speed_;*/ return { body_->GetLinearVelocity().x,body_->GetLinearVelocity().y }; }
	virtual void setSpeed(const Vector2D& v) { /*speed_ = v;*/ }
	virtual void setSpeed(double x, double y) { body_->SetLinearVelocity({ (float32)x,(float32)y }); }

	// get and set for width and height
	virtual double getWidth() const { return width_; }
	virtual double getHeight() const { return height_; }

	virtual void setWidth(double width);
	virtual void setHeight(double height);

	virtual void setWidthHeight(double width, double height);

	//get and set for rotation
	virtual double getRotation() { return body_->GetTransform().q.GetAngle(); }
	virtual void setRotation(double rotation) { body_->SetTransform(body_->GetTransform().p, rotation); }

	//forces
	virtual void ApplyLinearImpulse(float32 xImp, float32 yImp) {
		body_->ApplyLinearImpulse({xImp, yImp}, body_->GetWorldCenter(), true);
	}
private:
	b2Body* body_;
};

