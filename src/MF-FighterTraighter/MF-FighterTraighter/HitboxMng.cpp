#include "HitboxMng.h"
#include <iostream>

void HitboxMng::update()
{
	for (auto it = hitboxList_.begin(); it != hitboxList_.end();++it) {
		if ((static_cast<hitbox*>((*it)->GetUserData())->time_--) <= 0) {//time habra que modificar a frames
			std::cout << "Borro " << static_cast<hitbox*>((*it)->GetUserData())->damage_ << std::endl;
			delete static_cast<hitbox*>((*it)->GetUserData());
			(*it)->GetBody()->DestroyFixture((*it));
			hitboxListToRemove_.push_back(*it);
			//hitboxList_.erase(it);
			
		}
	}

	for (auto h : hitboxListToRemove_) {	
		hitboxList_.remove(h);
	}
	hitboxListToRemove_.clear();
}


void HitboxMng::addHitbox(Vector2D pos, int width, int height, int time, int damage, b2Body* body)
{
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2, { float32(pos.getX() + width / 2),float32(pos.getY() + height / 2) }, 0);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001;			//densidad casi 0, para que no cambie segun el ancho y el alto por ahora
	fixturedef.isSensor=true;
	//fixturedef.filter.categoryBits = 
	hitbox* hitbox_ = new hitbox{ damage,time };//creamos los datos de la hitbox
	hitboxList_.push_back(body->CreateFixture(&fixturedef));//creamos la fixture 
	hitboxList_.back()->SetUserData(hitbox_);//guardamos los datos de la hitbox
}

