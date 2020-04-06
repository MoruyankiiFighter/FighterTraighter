#include "FactoryMk.h"
#include "App.h"
#include "PhysicsTransform.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "Crouch.h"
#include "PlayerAttacks.h"
#include "PlayerState.h"
#include "Health.h"
#include "PlayerOnHit.h"
Entity* FactoryMk::addMkToGame(App* app, GameState* state, b2World* world, int orientation, std::vector<SDL_Scancode> keys, uint16 cBits, uint16 mBits, bool dyn)
{
	Entity* e = state->getEntityManager().addEntity();
	PhysicsTransform* pT = e->addComponent<PhysicsTransform>(Vector2D(-orientation * 100 + 200, 10), Vector2D(10, 10), 50, 50, 0, world, cBits, mBits, dyn);
	pT->setOrientation(orientation);
	app->getHitboxMng()->addMainHitbox(pT->getMainFixture());

	e->addComponent<PlayerController>(keys[0], keys[1], keys[8], -1500, keys[2], keys[3]);
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(0));
	//e->addComponent<Jump>(-1000, keys[2]);
	//e->addComponent<Crouch>(keys[3]);
	e->addComponent<PlayerState>();
	e->addComponent<Health>(110);
	e->addComponent<PlayerOnHit>();
	std::vector<Move*> vecMov;

	vecMov.push_back(new Move(27, nullptr, NP1, e));
	vecMov.push_back(new Move(32, nullptr, nullptr, e));
	AnimationChain* testNP = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(29, nullptr, HP1, e));
	vecMov.push_back(new Move(40, nullptr, nullptr, e));
	AnimationChain* testHP = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(25, nullptr, NK1, e));
	vecMov.push_back(new Move(20, nullptr, NK2, e));
	vecMov.push_back(new Move(25, nullptr, nullptr, e));
	AnimationChain* testNK = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(35, nullptr, HK1, e));
	//vecMov.push_back(new Move(0, nullptr, HK2, e));
	vecMov.push_back(new Move(65, nullptr, nullptr, e));
	AnimationChain* testHK = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(40, nullptr, ANP1, e));
	vecMov.push_back(new Move(25, nullptr, ANP2, e));
	vecMov.push_back(new Move(25, nullptr, nullptr, e));
	AnimationChain* testANP = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(49, nullptr, AHP1, e));
	vecMov.push_back(new Move(45, nullptr, nullptr, e));
	AnimationChain* testAHP = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(34, nullptr, ANK1, e));
	vecMov.push_back(new Move(17, nullptr, ANK2, e));
	vecMov.push_back(new Move(22, nullptr, nullptr, e));
	AnimationChain* testANK = new AnimationChain(vecMov);
	vecMov.clear();

	vecMov.push_back(new Move(32, nullptr, AHK1, e));
	vecMov.push_back(new Move(65, nullptr, nullptr, e));
	AnimationChain* testAHK = new AnimationChain(vecMov);
	vecMov.clear();

	//std::vector<AnimationChain*> chains = app_->getAssetsManager()->getMoveParser()->parseFile("../../../../assets/Assets/Config/MovesMK.txt");
	e->addComponent<PlayerAttacks>(testNP, testANP, keys[4], testHP, testAHP, keys[5], testNK, testANK, keys[6], testHK, testAHK, keys[7]);

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



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-75 }, width, 75, 20, 9, 42, { (double)orientation_ * 10, -50 }, body, filter.categoryBits, filter.maskBits);
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



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-45 }, width, 60, 17, 15, 55, { (double)orientation_ * 4, 25 }, body, filter.categoryBits, filter.maskBits);
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



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-20 }, width, 35, 13, 6, 16, { (double)orientation_ * 0.25, -0.25 }, body, filter.categoryBits, filter.maskBits);
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



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -17 }, width, 35, 17, 6, 35, { (double)orientation_ * 0.55, -0.75 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::HK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Falcon stomp" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width1 = 35;
	int hitboxX1 = 20;
	if (orientation_ == -1) hitboxX1 += width1;
	int width2 = 200;
	int hitboxX2 = 0;
	if (orientation_ == -1) hitboxX2 += width2;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX1, -15 }, width1, 40, 17, 17, 50, { (double)orientation_ * 0.05, 5 }, body, filter.categoryBits, filter.maskBits);
	std::cout << "Brrrrrjrnkrrbr" << endl;
	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX2, 15 }, width2, 30, 20, 5, 40, { (double)orientation_ * 3, -3 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::ANP1(Entity* ent)
{
	std::cout << "Speeeee-" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 84;
	int hitboxX = -42;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -15 }, width, 35, 35, 5, 16, { (double)orientation_ * 0.1, -0.1 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::ANP2(Entity* ent)
{
	std::cout << "-eeeeeeen" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 84;
	int hitboxX = -42;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -20 }, width, 35, 35, 8, 30, { (double)orientation_ * 0.25, 3 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::AHP1(Entity* ent)
{
	std::cout << "Get spiked son" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 38;
	int hitboxX = 25;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -25 }, width, 70, 25, 22, 65, { (double)orientation_ * 0.2, 100 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::ANK1(Entity* ent)
{
	std::cout << "Steppy" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 45;
	int hitboxX = 15;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, 0 }, width, 45, 17, 4, 15, { (double)orientation_ * 0.05, -0.05 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::ANK2(Entity* ent)
{
	std::cout << "STEPPY!!!" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 45;
	int hitboxX = 17;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, 2 }, width, 49, 17, 10, 28, { (double)orientation_ * 0.2, 0.2 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::AHK1(Entity* ent)
{
	std::cout << "Dropkick" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 70;
	int hitboxX = 5;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -20 }, width, 40, 50, 18, 55, { (double)orientation_ * 7, -1 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::GB(Entity* ent)
{
}
