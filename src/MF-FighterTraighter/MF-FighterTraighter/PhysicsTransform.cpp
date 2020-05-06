#include "PhysicsTransform.h"

//	cBits are the category bits, the collision group this body is in
//	cMask are the mask bits, the collision groups to check
//	if not modified, the body will collide with everything
PhysicsTransform::PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, uint16 cBits, uint16 mBits, bool dyn)
	: Transform(position, speed, width, height, rotation)
{
	cBits_ = cBits;
	mBits_ = mBits;
	b2BodyDef bodydef;
	bodydef.position.Set(position.getX(), position.getY());
	if (dyn)  
		bodydef.type = b2_dynamicBody;	//makes the dynamic body if it is dynamic
	body_ = world->CreateBody(&bodydef);
	b2PolygonShape shape;
	shape.SetAsBox(width * wMult_/2 , height * hMult_/2 );
	resetMainFixture(shape);
	body_->SetFixedRotation(true);
	
}


PhysicsTransform::~PhysicsTransform() {
	//world_->DestroyBody(body_);
}

void PhysicsTransform::init() {
	mainFixture_->SetUserData(this->entity_);	//tener acceso a la entidad para hacer cosas con las colisiones // ahora es en la mainFixture para poder acceder a la entidad en el HBManager
}

void PhysicsTransform::setHeight(double height) {
	height_ = height;
}

void PhysicsTransform::setColliderHeight(double height) {

	body_->DestroyFixture(mainFixture_);

	b2PolygonShape shape;
	shape.SetAsBox(width_ / 2, height / 2);
	resetMainFixture(shape);
	mainFixture_->SetUserData(this->entity_);
}

void PhysicsTransform::setWidth(double width) {
	width_ = width;
}

void PhysicsTransform::setColliderWidth(double width) {

	body_->DestroyFixture(mainFixture_);

	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height_ / 2);
	resetMainFixture(shape);
	mainFixture_->SetUserData(this->entity_);
}

void PhysicsTransform::setWidthHeight(double width, double height) {

	body_->DestroyFixture(mainFixture_);

	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2);
	resetMainFixture(shape);
	mainFixture_->SetUserData(this->entity_);
	width_ = width;
	height_ = height;
}

void PhysicsTransform::resetMainFixture(const b2PolygonShape& shape) {

	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.0f;
	fixturedef.filter.categoryBits = cBits_;
	fixturedef.filter.maskBits = mBits_;
	fixturedef.friction = 1;
	mainFixture_ = body_->CreateFixture(&fixturedef);
}