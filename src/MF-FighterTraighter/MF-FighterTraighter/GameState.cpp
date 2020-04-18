#include "GameState.h"
#include "Entity.h"
#include "App.h"
#include "OnHit.h"
#include "HitboxData.h"

GameState::GameState(App* app) : app_(app), entManager_(app) {

}
void GameState::init()
{
	
}

void GameState::handleInput()
{
	for (auto it = entManager_.getScene().begin();  it != entManager_.getScene().end() ;++it) {
		(*it)->handleInput();
	}
}

void GameState::update()
{
	//destroy the hitbox and pop it from the hitbox list
	RemoveHitbox();
	UpdateHitboxes();
	
	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		(*it)->update();
	}
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
					if (mainHB->GetBody() != (*it)->GetBody() && b2TestOverlap((*it)->GetAABB(0), mainHB->GetAABB(0))) {
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
	fixturedef.filter.maskBits = mBits;
	HitboxData* hitbox_ = new HitboxData{ damage,time, hitstun, knockBack,guardBreaker };//create the hitbox's data
	//for now we can use the category bits to use the group that we want Player1HB = hitboxgroup[0] // Player2HB = hitboxgroup[1]
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
	b2Body* cur = app_->getb2World()->GetBodyList();
	b2Body* aux = cur;
	while (aux != nullptr)
	{
		aux = cur->GetNext();
		app_->getb2World()->DestroyBody(cur);
		cur = aux;
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
	app_->getb2World()->DrawDebugData();
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
}
