#include "hitbox.h"

void hitbox::update()
{
	time_--;
	if (time_ <= 0) {
		body_->DestroyFixture(this);		
	}
}

hitbox::~hitbox()
{
}

void hitbox::init()
{
	b2PolygonShape shape;
	shape.SetAsBox(100 / 2, 100 / 2,b2Vec2(200,0),0);
	
	//shape.s
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.05;			//densidad 0, para que no cambie segun el ancho y el alto por ahora

	body_->CreateFixture(&fixturedef);

}


