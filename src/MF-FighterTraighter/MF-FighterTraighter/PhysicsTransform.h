#pragma once
#include "Transform.h"
#include "Box2D\Box2D.h"
# include <vector>
class PhysicsTransform : public Transform
{
public:
	PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation,b2World* world,uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, int dyn = 2);
	//PhysicsTransform();
	virtual ~PhysicsTransform();

	//method overrided from transform 
	virtual void init() override;
	
	// get returns the position in pixels
	virtual Vector2D getPosition() const {
		Vector2D pos{(((float)(body_->GetTransform().p.x)) * app_->PIXELS_PER_METER) - width_ * wMult_ / 2, (((float)(body_->GetTransform().p.y)) * app_->PIXELS_PER_METER) - height_ * hMult_ / 2 };
		return  pos;
	}
	// set transforms the position in pixels in meters
	virtual void setPosition(Vector2D& v) {
		body_->SetTransform((b2Vec2)(v * app_->METERS_PER_PIXEL), body_->GetAngle()); 
	}
	// set transforms the position in pixels in meters
	virtual void setPosition(double x, double y) { 
		body_->SetTransform({ (float32)x * app_->METERS_PER_PIXEL,(float32)y * app_->METERS_PER_PIXEL}, body_->GetAngle());
	}

	//<---se puede transformar tb en pixeles la velocidad, pero como lo estamos usando, mejor poner los valores en m/s y nos ahorramos un par de operaciones->
	//gets the speed in m/s
	virtual Vector2D getSpeed() const { 
		return Vector2D((float)body_->GetLinearVelocity().x, (float)body_->GetLinearVelocity().y);
	}

	//sets the speed in m/s
	virtual void setSpeed(const Vector2D& v) { 
		body_->SetLinearVelocity({ (float32)v.getX(), (float32)v.getY()});
	}
	//sets the speed transforming pixels/s in m/s
	virtual void setSpeed(double x, double y) {
		body_->SetLinearVelocity({ (float32)x,(float32)y}); 
	}

	virtual void setWidth(double width);
	virtual void setColliderWidth(double width);
	virtual void setHeight(double height);
	virtual void setColliderHeight(double height);

	virtual void setWidthHeight(double width, double height);
	b2Body* getBody() { return body_; }
	b2Fixture* getMainFixture() { return mainFixture_; }
	uint16 getCategory() { return cBits_; }
	uint16 getMask() { return mBits_; }

private:
	b2Body* body_;
	uint16 cBits_, mBits_;
	b2Fixture* mainFixture_;
	int dynamic_;
	b2World* world_ = nullptr;
	void resetMainFixture(const b2PolygonShape& shape);
};

