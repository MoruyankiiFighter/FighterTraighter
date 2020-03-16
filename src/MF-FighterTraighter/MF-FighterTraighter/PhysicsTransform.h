#pragma once
#include "Transform.h"
#include "Box2D\Box2D.h"

class PhysicsTransform : public Transform
{
public:
	//constructor
	PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, bool dyn = true);
	
	//destructor
	virtual ~PhysicsTransform();


	virtual void init() override;
	
	//get and set for position
	virtual const Vector2D& getPosition() const;
	virtual void setPosition(const Vector2D& v) 
		{ body_->SetTransform({ (float32)v.getX(),(float32)v.getY() }, body_->GetAngle()); }
	virtual void setPosition(double x, double y) 
		{ body_->SetTransform({ (float32)x,(float32)y }, body_->GetAngle()); }

	//get and set for speed
	virtual const Vector2D& getSpeed() const;
	virtual void setSpeed(const Vector2D& v) 
		{ body_->SetLinearVelocity({ (float32)v.getX(),(float32)v.getY() }); }
	virtual void setSpeed(double x, double y) 
		{ body_->SetLinearVelocity({ (float32)x,(float32)y }); }


	//set width 
	virtual void setWidth(double width);
	//set height
	virtual void setHeight(double height);
	//set width and height
	virtual void setWidthHeight(double width, double height);

	//returns the body
	b2Body* getBody() { return body_; }

private:
	b2World* world_=nullptr;
	b2Body* body_=nullptr;
};

