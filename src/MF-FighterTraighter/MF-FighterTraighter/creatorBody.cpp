#include "creatorBody.h"

creatorBody::creatorBody(Transform* transform, b2World* world):
	Component(ecs::CreatorBody),transform_(transform),world_(world), fixture_ (nullptr)
{

	b2BodyDef bodydef;
	bodydef.position.Set(transform_->getPosition().getX(), transform_->getPosition().getY());
	//position_ = bodydef.position();
	/*if (dyn)  */bodydef.type = b2_kinematicBody;
	body_ = world_->CreateBody(&bodydef);
	//fixture_ = nullptr;
	//b2PolygonShape shape;
	//shape.SetAsBox(width /** wMult_*/ / 2, height /** hMult_*/ / 2);
	////shape.s
	//b2FixtureDef fixturedef;
	//fixturedef.shape = &shape;
	//fixturedef.density = 0.00001;			//densidad casi 0, para que no cambie segun el ancho y el alto por ahora

	//body_->CreateFixture(&fixturedef);
}

void creatorBody::update()
{
	body_->SetTransform(b2Vec2(transform_->getPosition().getX(), transform_->getPosition().getY()), transform_->getRotation());
	if (body_->GetFixtureList() != nullptr) {
		if (time_-- <= 0) 
			body_->DestroyFixture(fixture_);
		
	}
}

void creatorBody::createHitbox(Vector2D pos, int width, int height, int time, int damage, Vector2D dir)
{
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2, { float32(pos.getX()+width/2),float32(pos.getY()+height/2) },0);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001;			//densidad casi 0, para que no cambie segun el ancho y el alto por ahora

	body_->CreateFixture(&fixturedef);
	fixture_ = body_->CreateFixture(&fixturedef);
	time_ = time;
}


