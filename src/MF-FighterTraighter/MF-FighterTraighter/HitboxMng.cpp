#include "HitboxMng.h"
#include <iostream>
#include "OnHit.h"
#include "Entity.h"
#include "PlayerState.h"
#include "PlayerAttacks.h"
#include "PlayerController.h"
#include "PlayerOnHit.h"

//removes the hitboxes that their time is 0 or overlap
//with a object with OnHit component(players and punching bag)
void HitboxMng::update()
{
	//delete the hitbox when you interrupt an attack
	//if (toRemove)
		remove();
	

	for (uint i = 0; i < 2; i++) {
		for (auto it = hitboxGroups_[i].begin(); it != hitboxGroups_[i].end(); ++it) {
			HitboxData* hB = static_cast<HitboxData*>((*it)->GetUserData());
			if (hB->time_-- <= 0) {//time habra que modificar a frames			checks if the hitbox "dies"
				if (!hB->destroy) {
					hitboxRemove_pair_.push_back(pair<list<b2Fixture*>::iterator, uint>(it, i));
					hB->destroy = true;
				}
			}
			else {	// if the hitbox doesnt "die", it checks overlaps with the main hitboxes
				for (b2Fixture* mainHB : mainHurtboxes) {
					if (mainHB->GetBody() != (*it)->GetBody() && checkOverlap((*it), mainHB)) {
						//gets the OnHitComponent if the mainObject has it, if it doesnt, it does nothing
						OnHit* objOnHit = static_cast<Entity*>(mainHB->GetUserData())->getComponent<OnHit>(ecs::OnHit);
						if (objOnHit != nullptr) {
							objOnHit->onHit(*it);
							if (!hB->destroy) {
								hitboxRemove_pair_.push_back(pair<list<b2Fixture*>::iterator, uint>(it, i));
								hB->destroy = true;
							}
							
						}
					}
				}
			}
		}
	}
	//if (toRemove)remove();//remove if a hitbox has hit a enemy or his time is 0

}

//create a hitbox (fixture) in a specific body with the data that we want
void HitboxMng::addHitbox(Vector2D pos, int width, int height, int time, int damage, int hitstun, Vector2D knockBack, b2Body* body, uint16 cBits, uint16 mBits)
{
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2, { float32(pos.getX() + width / 2),float32(pos.getY() + height / 2) }, 0);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001f;			//densidad casi 0, para que no cambie segun el ancho y el alto por ahora
	fixturedef.isSensor=true;
	fixturedef.filter.categoryBits = cBits;
	if (0x0002 == cBits >> 2) fixturedef.filter.maskBits = 0x0004;
	else  fixturedef.filter.maskBits = 0x0002;
	//fixturedef.filter.maskBits = mBits;//colission mask
	HitboxData* hitbox_ = new HitboxData{ damage,time, hitstun, knockBack };//create the hitbox's data
	//for now we can use the category bits to use the group that we want Player1HB = hitboxgroup[0] // Player2HB = hitboxgroup[1]
	hitboxGroups_[cBits >> 2].push_back(body->CreateFixture(&fixturedef));
	hitboxGroups_[cBits >> 2].back()->SetUserData(hitbox_);//saving hitbox's data
}


//deleting all 
void HitboxMng::clear() {
	mainHurtboxes.clear();
	hitboxRemove_pair_.clear();
	for (int i = 0; i < 2; i++) {
		for (auto it = hitboxGroups_[i].begin(); it != hitboxGroups_[i].end(); ++it) {
			delete static_cast<HitboxData*>((*it)->GetUserData());
			(*it)->GetBody()->DestroyFixture(*it);
		}
		hitboxGroups_[i].clear();
	}
	
}

//destroy the hitbox and pop it from the hitbox list
void HitboxMng::remove()
{
	for (auto hb_it = hitboxRemove_pair_.begin(); hb_it != hitboxRemove_pair_.end(); ++hb_it) {
		
		delete static_cast<HitboxData*>((*(*hb_it).first)->GetUserData());
		(*(*hb_it).first)->GetBody()->DestroyFixture((*(*hb_it).first));
		hitboxGroups_[(*hb_it).second].erase((*hb_it).first);
	}
	hitboxRemove_pair_.clear();
	toRemove = false;
}

//hacer un refresh para destruir las hitboxes
//it is called when you interrupt an attack 
void HitboxMng::resetGroup(int group) {
	
	for (auto it = hitboxGroups_[group].begin(); it != hitboxGroups_[group].end(); ++it) {
		HitboxData* hB = static_cast<HitboxData*>((*it)->GetUserData());
		if (!hB->destroy) {
			hitboxRemove_pair_.push_back(pair<list<b2Fixture*>::iterator, uint>(it, group));
			hB->destroy = true;
		}
	}
}