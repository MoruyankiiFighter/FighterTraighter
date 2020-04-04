#include "PhysicsTransform.h"

//	cBits are the category bits, the collision group this body is in
//	cMask are the mask bits, the collision groups to check
//	if not modified, the body will collide with everything
PhysicsTransform::PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, bool dyn)
	: Transform(position, speed, width, height, rotation)
{
	b2BodyDef bodydef;
	bodydef.position.Set(position.getX(), position.getY());
	if (dyn)  
		bodydef.type = b2_dynamicBody;	//makes the dynamic body if it is dynamic
	body_ = world->CreateBody(&bodydef);
	body_->SetFixedRotation(true);	//esto deberia ser solo para los personajes
}


PhysicsTransform::~PhysicsTransform() {
	//world_->DestroyBody(body_);
}

void PhysicsTransform::setHeight(double height) {
	height_ = height;
}


void PhysicsTransform::setWidth(double width) {
	width_ = width;
}

void PhysicsTransform::setWidthHeight(double width, double height) {
	width_ = width;
	height_ = height;
}