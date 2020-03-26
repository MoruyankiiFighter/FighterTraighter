#include "HitboxMng.h"
#include <iostream>
#include "OnHit.h"
#include "Entity.h"

void HitboxMng::update()
{
	for (auto it = hitboxList_.begin(); it != hitboxList_.end();++it) {
		HitboxData* hB = static_cast<HitboxData*>((*it)->GetUserData());
		if (hB->time_-- <= 0) {//time habra que modificar a frames			checks if the hitbox "dies"
			hitboxListToRemove_.push_back(*it);
		}
		else {	// if the hitbox doesnt "die", it checks overlaps with the main hitboxes
			for (b2Fixture* mainHB : mainHitboxes) {
				if (mainHB->GetBody() != (*it)->GetBody() && checkOverlap((*it), mainHB)) {
					//gets the OnHitComponent if the mainObject has it, if it doesnt, it does nothing
					OnHit* objOnHit = static_cast<Entity*>(mainHB->GetUserData())->getComponent<OnHit>(ecs::OnHit);
					if (objOnHit != nullptr) {
						objOnHit->onHit();
						hitboxListToRemove_.push_back(*it);
					}
				}
			}			
		}
	}

	for (auto h : hitboxListToRemove_) {
		std::cout << "Borro " << static_cast<HitboxData*>(h->GetUserData())->damage_ << std::endl;
		delete static_cast<HitboxData*>(h->GetUserData());
		h->GetBody()->DestroyFixture(h);
		hitboxList_.remove(h);
	}
	hitboxListToRemove_.clear();
}


void HitboxMng::addHitbox(Vector2D pos, int width, int height, int time, int damage, Vector2D knockBack, b2Body* body, uint16 cBits, uint16 mBits)
{
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2, { float32(pos.getX() + width / 2),float32(pos.getY() + height / 2) }, 0);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001;			//densidad casi 0, para que no cambie segun el ancho y el alto por ahora
	fixturedef.isSensor=true;
	fixturedef.filter.categoryBits = cBits;
	fixturedef.filter.maskBits = mBits;
	HitboxData* hitbox_ = new HitboxData{ damage,time, knockBack };//creamos los datos de la hitbox
	hitboxList_.push_back(body->CreateFixture(&fixturedef));//creamos la fixture 
	hitboxList_.back()->SetUserData(hitbox_);//guardamos los datos de la hitbox
}

