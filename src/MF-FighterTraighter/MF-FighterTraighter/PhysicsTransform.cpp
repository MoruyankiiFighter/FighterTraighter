#include "PhysicsTransform.h"
#include "Training.h"
PhysicsTransform::PhysicsTransform(Vector2D position, Vector2D speed, double width, double height, double rotation, b2World* world, bool dyn)
	: Transform(position, speed, width, height, rotation)
{
	world_ = world;

	b2BodyDef bodydef;
	bodydef.position.Set(position.getX(), position.getY());
	//position_ = bodydef.position();
	if (dyn)  bodydef.type = b2_dynamicBody;
	body_ = world->CreateBody(&bodydef);
	b2PolygonShape shape;
	shape.SetAsBox(width * wMult_/2 , height * hMult_/2 );
	//shape.s
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001;			//densidad 0, para que no cambie segun el ancho y el alto por ahora
	//body_->CreateFixture(&fixturedef);
	body_->SetFixedRotation(true);
	fList.push_back(body_->CreateFixture(&fixturedef));

	b2PolygonShape shape2;
	shape2.SetAsBox(width * wMult_ / 2, height * hMult_ / 2,b2Vec2(100,0),0);
	//shape.s
	b2FixtureDef fixturedef2;
	fixturedef2.shape = &shape2;
	fixturedef2.density = 0.00001;			//densidad 0, para que no cambie segun el ancho y el alto por ahora
	//body_->SetFixedRotation(true);
	//body_->CreateFixture(&fixturedef2);
	fList.push_back(body_->CreateFixture(&fixturedef2));

	

}


PhysicsTransform::~PhysicsTransform() {
	//world_->DestroyBody(body_);
}

void PhysicsTransform::init() {
	body_->SetUserData(this->entity_);	//tener acceso a la entidad para hacer cosas con las colisiones

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

void PhysicsTransform::destroy()
{
	static_cast<Training*>(app_->getStateMachine()->getCurrentState())->addToRemove(fList.back());

}
