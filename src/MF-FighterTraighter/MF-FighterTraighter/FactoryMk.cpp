#include "FactoryMk.h"
#include "App.h"
#include "PhysicsTransform.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "Crouch.h"
#include "PlayerAttacks.h"
#include "PlayerState.h"

Entity* FactoryMk::addMkToGame(App* app, GameState* state, b2World* world, int orientation, std::vector<SDL_Scancode> keys, uint16 cBits, uint16 mBits, bool dyn)
{
	Entity* e = state->giveMeManager().addEntity();
	PhysicsTransform* pT =  e->addComponent<PhysicsTransform>(Vector2D(-orientation * 100 + 200, 10), Vector2D(10, 10), 50, 50, 0, world, cBits, mBits, dyn);
	pT->setOrientation(orientation);
	app->getHitboxMng()->addMainHitbox(pT->getMainFixture());

	e->addComponent<PlayerController>(keys[0], keys[1]);
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(0));
	e->addComponent<Jump>(-1000, keys[2]);
	e->addComponent<Crouch>(keys[3]);
	e->addComponent<PlayerState>();

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
	//vecMov.push_back(new Move(0, nullptr, HK2, e));
	vecMov.push_back(new Move(65, nullptr, nullptr, e));
	AnimationChain* testHK = new AnimationChain(vecMov);
	vecMov.clear();

	//std::vector<AnimationChain*> chains = app_->getAssetsManager()->getMoveParser()->parseFile("../../../../assets/Assets/Config/MovesMK.txt");
	e->addComponent<PlayerAttacks>(testNP, keys[4], testHP, keys[5], testNK, keys[6], testHK, keys[7]);

	return e;
}

//Esto es para geenrar hitboxes, habr� uno para cada hitbox generada
void FactoryMk::NP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Uppercut" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 35;
	int hitboxX = 20;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-75 }, width, 75, 20, 50, { (double)orientation_ * 0,0 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::HP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Hostia" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	
	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 60;
	int hitboxX = 20;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-45 }, width, 60, 17, 50000, { (double)orientation_ * 0,0 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::NK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Rodilla 1" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 45;
	int hitboxX = 25;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-20 }, width, 35, 13, 50, { (double)orientation_ * 0,0 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::NK2(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Rodilla 2" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 45;
	int hitboxX = 20;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -17 }, width, 35, 17, 50, { (double)orientation_ * 0,0 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::HK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Falcon stomp" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width1 = 35;
	int hitboxX1 = 20;
	if (orientation_ == -1) hitboxX1 += width1;
	int width2 = 200;
	int hitboxX2 = 0;
	if (orientation_ == -1) hitboxX2 += width2;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX1, -15 }, width1, 40, 17, 50, { (double)orientation_ * 0,0 }, body, filter.categoryBits, filter.maskBits);
	std::cout << "Brrrrrjrnkrrbr" << endl;
	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX2, 15 }, width2, 30, 35, 1, { (double)orientation_ * 0,0 }, body, filter.categoryBits, filter.maskBits);
}

/*void FactoryMk::HK2(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Brrrrrjrnkrrbr" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();
	ent->getApp()->getHitboxMng()->addHitbox({ orientation_ * 0, 15 }, 200, 30, 35, 1, { orientation_ * 0,0 }, body, filter.categoryBits, filter.maskBits);
}*/
