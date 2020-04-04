#include "Collider.h"

Collider::Collider(double width, double height, b2Body* body) : Component(ecs::Collider), body_(body) {

	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2);
	reset(shape);
}

void Collider::init() {
	collider_->SetUserData(this->entity_);	//tener acceso a la entidad para hacer cosas con las colisiones // ahora es en la mainFixture para poder acceder a la entidad en el HBManager
}

void Collider::setHeight(double height) {

	body_->DestroyFixture(collider_);

	height_ = height;
	b2PolygonShape shape;
	shape.SetAsBox(width_ / 2, height_ / 2);
	reset(shape);
	collider_->SetUserData(this->entity_);
}

void Collider::setWidth(double width) {

	body_->DestroyFixture(collider_);

	width_ = width;
	b2PolygonShape shape;
	shape.SetAsBox(width_ / 2, height_ / 2);
	reset(shape);
	collider_->SetUserData(this->entity_);
}

void Collider::setWidthHeight(double width, double height) {
	body_->DestroyFixture(collider_);

	width_ = width;
	height_ = height;
	b2PolygonShape shape;
	shape.SetAsBox(width_ / 2, height_ / 2);
	reset(shape);
	collider_->SetUserData(this->entity_);
}

void Collider::reset(const b2PolygonShape& shape) {
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001;
	fixturedef.filter.categoryBits = cBits_;
	fixturedef.filter.maskBits = mBits_;

	collider_ = body_->CreateFixture(&fixturedef);
}