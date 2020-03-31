#include "HitboxMng.h"
#include <iostream>
#include "OnHit.h"
#include "Entity.h"
#include "Jump.h"
#include "PlayerState.h"
#include "PlayerAttacks.h"

//removes the hitboxes that their time is 0 or overlap
//with a object with OnHit component(players and punching bag)
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
						objOnHit->onHit(*it,mainHB);
						hitboxListToRemove_.push_back(*it);
					}
				}
			}			
		}
	}
	//destroy the hitbox and pop it from the hitbox list
	for (b2Fixture* h : hitboxListToRemove_) {
		std::cout << "Borro " << static_cast<HitboxData*>(h->GetUserData())->damage_ << std::endl;
		delete static_cast<HitboxData*>(h->GetUserData());
		h->GetBody()->DestroyFixture(h);
		hitboxList_.remove(h);
	}
	hitboxListToRemove_.clear();

	//to check if you are on the floor
	for (b2Fixture* mainHB : mainHitboxes) {
		Entity* player = static_cast<Entity*>(mainHB->GetUserData());
		Jump* jump = player->getComponent<Jump>(ecs::Jump);
		
		if (jump!=nullptr && checkOverlap(mainHB, floorFixture_)) {
			PlayerState* currState = player->getComponent<PlayerState>(ecs::PlayerState);
			OnHit* objOnHit2 = static_cast<Entity*>(floorFixture_->GetUserData())->getComponent<OnHit>(ecs::OnHit);
			if (objOnHit2 != nullptr && currState->isJumping()) {
				if (currState->isAttacking()) player->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->interruptAttack();
				currState->goLanding(25);
				objOnHit2->onHit(mainHB, mainHB);
			}
		}
		

	}
}

//create a hitbox (fixture) in a specific body with the data that we want
void HitboxMng::addHitbox(Vector2D pos, int width, int height, int time, int damage, Vector2D knockBack, b2Body* body, uint16 cBits, uint16 mBits)
{
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2, { float32(pos.getX() + width / 2),float32(pos.getY() + height / 2) }, 0);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001;			//densidad casi 0, para que no cambie segun el ancho y el alto por ahora
	fixturedef.isSensor=true;
	fixturedef.filter.categoryBits = cBits;
	fixturedef.filter.maskBits = mBits;//colission mask
	HitboxData* hitbox_ = new HitboxData{ damage,time, knockBack };//create the hitbox's data
	hitboxList_.push_back(body->CreateFixture(&fixturedef));//create fixture and saving it in the list
	hitboxList_.back()->SetUserData(hitbox_);//saving hitbox's data
}

