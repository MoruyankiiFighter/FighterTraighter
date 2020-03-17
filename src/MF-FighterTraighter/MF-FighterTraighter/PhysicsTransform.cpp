#include "PhysicsTransform.h"

//constructor
PhysicsTransform::PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, bool dyn)
	: Transform(position, speed, width, height, rotation), world_(world)
{
	b2BodyDef bodydef;
	bodydef.position.Set(position.getX(), position.getY());
	//position_ = bodydef.position();
	if (dyn)  bodydef.type = b2_dynamicBody;
	body_ = world->CreateBody(&bodydef);
	b2PolygonShape shape;
	shape.SetAsBox(width * scale_x/2 , height * scale_y/2 );
	//shape.s
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.5;			//density 0, for maintain the width and height of the body

	body_->CreateFixture(&fixturedef);
}

//destructor
PhysicsTransform::~PhysicsTransform() {
	//world_->DestroyBody(body_);
}

//init
void PhysicsTransform::init() {
	body_->SetUserData(this->entity_);	//tener acceso a la entidad para hacer cosas con las colisiones
}

const Vector2D& PhysicsTransform::getPosition() const
{
	Vector2D pos{ body_->GetTransform().p.x - width_ * scale_x / 2, body_->GetTransform().p.y - height_ * scale_y / 2 };
	return  pos;
}

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

const Vector2D& PhysicsTransform::getSpeed() const
{
	Vector2D pos{ body_->GetLinearVelocity().x,body_->GetLinearVelocity().y };
	return pos;
}

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
