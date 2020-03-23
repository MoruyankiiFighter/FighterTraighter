#include "FactoryMk.h"
#include "App.h"
#include "PhysicsTransform.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "Crouch.h"
#include "PlayerAttacks.h"

Entity* FactoryMk::addMkToGame(App* app, GameState* state, b2World* world, uint16 cBits, uint16 mBits, bool dyn)
{
	Entity* e = state->giveMeManager().addEntity();
	e->addComponent<PhysicsTransform>(Vector2D(10, 10), Vector2D(10, 10), 50, 50, 0, world, cBits, mBits, dyn);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(0));
	e->addComponent<Jump>(-1000);
	e->addComponent<Crouch>();

	std::vector<Move*> vecMov;

	vecMov.push_back(new Move(85, nullptr, NP1, e));
	vecMov.push_back(new Move(42, nullptr, nullptr, e));
	AnimationChain* testNP = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(75, nullptr, HP1, e));
	vecMov.push_back(new Move(60, nullptr, nullptr, e));
	AnimationChain* testHP = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(65, nullptr, NK1, e));
	vecMov.push_back(new Move(45, nullptr, NK2, e));
	vecMov.push_back(new Move(60, nullptr, nullptr, e));
	AnimationChain* testNK = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(95, nullptr, HK1, e));
	vecMov.push_back(new Move(0, nullptr, HK2, e));
	vecMov.push_back(new Move(65, nullptr, nullptr, e));
	AnimationChain* testHK = new AnimationChain(vecMov);
	vecMov.clear();

	//std::vector<AnimationChain*> chains = app_->getAssetsManager()->getMoveParser()->parseFile("../../../../assets/Assets/Config/MovesMK.txt");
	e->addComponent<PlayerAttacks>(testNP, SDL_SCANCODE_Q, testHP, SDL_SCANCODE_E, testNK, SDL_SCANCODE_Z, testHK, SDL_SCANCODE_X);

	return e;
}

//Esto es para geenrar hitboxes, habrá uno para cada hitbox generada
void FactoryMk::NP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Uppercut" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	ent->getApp()->getHitboxMng()->addHitbox({ 20,-75 }, 35, 75, 20, 50, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::HP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Hostia" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	ent->getApp()->getHitboxMng()->addHitbox({ 20,-45 }, 60, 60, 17, 50000, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::NK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Rodilla 1" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	ent->getApp()->getHitboxMng()->addHitbox({ 25,-20 }, 45, 35, 13, 50, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::NK2(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Rodilla 2" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	ent->getApp()->getHitboxMng()->addHitbox({ 20, -17 }, 45, 35, 17, 50, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::HK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Falcon stomp" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	ent->getApp()->getHitboxMng()->addHitbox({ 20, -15 }, 35, 40, 17, 50, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::HK2(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Brrrrrjrnkrrbr" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	ent->getApp()->getHitboxMng()->addHitbox({ 0, 15 }, 200, 30, 35, 1, body, filter.categoryBits, filter.maskBits);
}
