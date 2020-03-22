#include "PhysicsTransform.h"
#include "Training.h"

//	cBits are the category bits, the collision group this body is in
//	cMask are the mask bits, the collision groups to check
//	if not modified, the body will collide with everything
PhysicsTransform::PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, uint16 cBits, uint16 mBits, bool dyn)
	: Transform(position, speed, width, height, rotation)
{
	world_ = world;

	b2BodyDef bodydef;
	bodydef.position.Set(position.getX(), position.getY());
	//position_ = bodydef.position();
	if (dyn)  bodydef.type = b2_dynamicBody;	//makes the dynamic body if it is dynamic
	body_ = world->CreateBody(&bodydef);
	b2PolygonShape shape;
	shape.SetAsBox(width * wMult_/2 , height * hMult_/2 );

	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001;			
	fixturedef.filter.categoryBits = cBits;
	fixturedef.filter.maskBits = mBits;
	body_->CreateFixture(&fixturedef);
	body_->SetFixedRotation(true);
}


PhysicsTransform::~PhysicsTransform() {
	//world_->DestroyBody(body_);
}

void PhysicsTransform::init() {
	body_->SetUserData(this->entity_);	//tener acceso a la entidad para hacer cosas con las colisiones

}

//al anadir mas hitbox puede dar fallo
void PhysicsTransform::setHeight(double height) {
	body_->DestroyFixture(body_->GetFixtureList());

	b2PolygonShape shape;
	shape.SetAsBox(width_ / 2, height / 2);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.0;

	body_->CreateFixture(&fixturedef);

	height_ = height;
}

//al anadir mas hitbox puede dar fallo
void PhysicsTransform::setWidth(double width) {

	body_->DestroyFixture(body_->GetFixtureList());

	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height_ / 2);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.0;

	body_->CreateFixture(&fixturedef);
	width_ = width;
}

//al anadir mas hitbox puede dar fallo
void PhysicsTransform::setWidthHeight(double width, double height) {

	body_->DestroyFixture(body_->GetFixtureList());

	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.0;

	body_->CreateFixture(&fixturedef);
	width_ = width;
	height_ = height;
}
