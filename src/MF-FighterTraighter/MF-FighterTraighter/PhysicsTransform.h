#pragma once
#include "Transform.h"
#include "Box2D\Box2D.h"

class PhysicsTransform : public Transform
{
public:
	PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, bool dyn = true);
	//PhysicsTransform();
	virtual ~PhysicsTransform();

	virtual void init();
	// get and set for position
	virtual const Vector2D& getPosition() const {
		Vector2D pos { body_->GetTransform().p.x - width_ * wMult_/2, body_->GetTransform().p.y  - height_ * hMult_/2};
		return  pos;
	}
	virtual void setPosition(const Vector2D& v) {/* body_->SetTransform(b2Vec2());*/ }
	virtual void setPosition(double x, double y) { body_->SetTransform({ (float32)x,(float32)y }, body_->GetAngle()); }

	//get and set for speed
	virtual const Vector2D& getSpeed() const { /*return speed_;*/ Vector2D pos{ body_->GetLinearVelocity().x,body_->GetLinearVelocity().y };
	return pos;
	}
	virtual void setSpeed(const Vector2D& v) { /*speed_ = v;*/ }
	virtual void setSpeed(double x, double y) { body_->SetLinearVelocity({ (float32)x,(float32)y }); }

	virtual void setWidth(double width);
	virtual void setHeight(double height);

	virtual void setWidthHeight(double width, double height);

	//forces
	virtual void ApplyLinearImpulse(float32 xImp, float32 yImp) {
		body_->ApplyLinearImpulse({xImp, yImp}, body_->GetWorldCenter(), true);
	}

	//void update() override { std::cout << body_->GetPosition().x << "/" <<body_->GetPosition().y << std::endl;} para testear

private:
	b2World* world_;	//puntero al mundo para destruirse
	b2Body* body_;
};

