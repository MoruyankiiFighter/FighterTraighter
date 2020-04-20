#include "GameState.h"
#include "Entity.h"
#include "App.h"
#include "OnHit.h"
#include "HitboxData.h"
#include "ResetJumpListener.h"

GameState::GameState(App* app) : app_(app), entManager_(app)
{
}
void GameState::init()
{
	gravity = { 0, 18.0f };//10.0
	world = new b2World(gravity);
#ifdef NDEBUG
	debugInstance = nullptr;
#else
	debugInstance = new SDLDebugDraw(app_->getRenderer());//, app_->PIXELS_PER_METER);
	world->SetDebugDraw(debugInstance);
	debugInstance->SetFlags(b2Draw::e_aabbBit);
#endif
	resJumpListener = new ResetJumpListener();
	world->SetContactListener(resJumpListener);

}

void GameState::handleInput()
{
	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		(*it)->handleInput();
	}
}

void GameState::update()
{

	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		(*it)->update();
	}
	//destroy the hitbox and pop it from the hitbox list
	UpdateHitboxes();
	RemoveHitbox();

	if (doStep)
		world->Step(1.0 / app_->getFrameRate(), 8, 3); //update box2d
}

void GameState::UpdateHitboxes()
{
	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = hitboxGroups_[i].begin(); it != hitboxGroups_[i].end(); ++it) {
			HitboxData* hB = static_cast<HitboxData*>((*it)->GetUserData());
			if (hB->time_-- <= 0) {//time habra que modificar a frames			checks if the hitbox "dies"
				if (!hB->destroy) {
					hitboxRemove_pair_.push_back(std::pair<std::list<b2Fixture*>::iterator, unsigned int>(it, i));
					hB->destroy = true;
				}
			}
			else {	// if the hitbox doesnt "die", it checks overlaps with the main hitboxes
				
				for (b2Fixture* mainHB : mainHurtboxes) {
					if ((mainHB->GetFilterData().maskBits & (*it)->GetFilterData().categoryBits) != 0
						&& (mainHB->GetFilterData().categoryBits & (*it)->GetFilterData().maskBits) != 0
						&& b2TestOverlap((*it)->GetAABB(0), mainHB->GetAABB(0))) {
						//gets the OnHitComponent if the mainObject has it, if it doesnt, it does nothing
						OnHit* objOnHit = static_cast<Entity*>(mainHB->GetUserData())->getComponent<OnHit>(ecs::OnHit);
						if (objOnHit != nullptr) {
							objOnHit->onHit(*it);
							if (!hB->destroy) {
								hitboxRemove_pair_.push_back(std::pair<std::list<b2Fixture*>::iterator, unsigned int>(it, i));
								hB->destroy = true;
							}
						}
					}
				}
			}
		}
	}
}

void GameState::addHitbox(Vector2D pos, int width, int height, int time, int damage, int hitstun, Vector2D knockBack, b2Body* body, uint16 id, uint16 cBits, uint16 mBits, bool guardBreaker)
{
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2, { float32(pos.getX() + width / 2),float32(pos.getY() + height / 2) }, 0);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0.00001f;			//densidad casi 0, para que no cambie segun el ancho y el alto por ahora
	fixturedef.isSensor = true;
	fixturedef.filter.categoryBits = cBits;
	fixturedef.filter.maskBits = mBits & (PLAYER_1 | PLAYER_2 | P_BAG); //kk
	HitboxData* hitbox_ = new HitboxData{ damage,time, hitstun, knockBack,guardBreaker };//create the hitbox's data

	//if (PLAYER_1 == cBits >> 2) fixturedef.filter.maskBits = PLAYER_2;
	//else  fixturedef.filter.maskBits = PLAYER_1;
	//HitboxData* hitbox = new HitboxData{ damage,time, hitstun, knockBack,guardBreaker };//create the hitbox's data
	////for now we can use the category bits to use the group that we want Player1HB = hitboxgroup[0] // Player2HB = hitboxgroup[1]
	//hitboxGroups_[cBits >> 2].push_back(body->CreateFixture(&fixturedef));
	//hitboxGroups_[cBits >> 2].back()->SetUserData(hitbox);//saving hitbox's data
	////for now we can use the category bits to use the group that we want Player1HB = hitboxgroup[0] // Player2HB = hitboxgroup[1]

	hitboxGroups_[id].push_back(body->CreateFixture(&fixturedef));
	hitboxGroups_[id].back()->SetUserData(hitbox_);//saving hitbox's data
}

void GameState::RemoveHitbox()
{
	for (auto hb_it = hitboxRemove_pair_.begin(); hb_it != hitboxRemove_pair_.end(); ++hb_it) {

		delete static_cast<HitboxData*>((*(*hb_it).first)->GetUserData());
		(*(*hb_it).first)->GetBody()->DestroyFixture((*(*hb_it).first));
		hitboxGroups_[(*hb_it).second].erase((*hb_it).first);
	}
	hitboxRemove_pair_.clear();
}

//deleting all 
void GameState::clearHitboxes() {
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



//hacer un refresh para destruir las hitboxes
//it is called when you interrupt an attack 
void GameState::resetGroup(int group) {

	for (auto it = hitboxGroups_[group].begin(); it != hitboxGroups_[group].end(); ++it) {
		HitboxData* hB = static_cast<HitboxData*>((*it)->GetUserData());
		if (!hB->destroy) {
			hitboxRemove_pair_.push_back(std::pair<std::list<b2Fixture*>::iterator, unsigned int>(it, group));
			hB->destroy = true;
		}
	}
}

void GameState::render()
{
	SDL_RenderClear(app_->getRenderer());

	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		(*it)->render();
	}
#ifdef NDEBUG
#else
	world->DrawDebugData();
#endif
	SDL_RenderPresent(app_->getRenderer());
}

void GameState::empty()
{
	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		delete* it;
	}
	entManager_.getScene().clear();
}

GameState::~GameState()
{
	empty();
	clearHitboxes();

	delete world;
	delete debugInstance;
	delete resJumpListener;
}
