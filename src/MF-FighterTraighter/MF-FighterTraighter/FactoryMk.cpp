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
	PhysicsTransform* pT = e->addComponent<PhysicsTransform>(Vector2D(-orientation * 100 + 960, 50), Vector2D(0, 0), 500, 500, 0, world, cBits, mBits, dyn);
	pT->setOrientation(orientation);
	pT->setColliderWidth(pT->getWidth() / 2);
	app->getHitboxMng()->addMainHitbox(pT->getMainFixture());

	e->addComponent<PlayerController>(keys[0], keys[1], keys[8], -1500, keys[2], keys[3]);
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::Player));
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
	int width = 150;
	int hitboxX = 100;
	if (orientation_ == -1) hitboxX += width;

	

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-250 }, width, 225, 20, 9, 42, { (double)orientation_ * 10, -50 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::HP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Hostia" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 175;
	int hitboxX = 100;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-85 }, width, 150, 17, 15, 55, { (double)orientation_ * 4, 250 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::NK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Rodilla 1" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 155;
	int hitboxX = 105;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, 125 }, width, 125, 13, 6, 16, { (double)orientation_ * 2.5, -2.5 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::NK2(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Rodilla 2" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 140;
	int hitboxX = 135;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, 100 }, width, 125, 17, 6, 35, { (double)orientation_ * 50, -30 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::HK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
{
	std::cout << "Falcon stomp" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width1 = 120;
	int hitboxX1 = 130;
	if (orientation_ == -1) hitboxX1 += width1;
	int width2 = 600;
	int hitboxX2 = 0;
	if (orientation_ == -1) hitboxX2 += width2;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX1, 105 }, width1, 150, 17, 17, 50, { (double)orientation_ * 5, 500 }, body, filter.categoryBits, filter.maskBits);
	std::cout << "Brrrrrjrnkrrbr" << endl;
	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX2, 220 }, width2, 50, 20, 5, 40, { (double)orientation_ * 500, -300 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::ANP1(Entity* ent)
{
	std::cout << "Speeeee-" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 350;
	int hitboxX = -165;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -65 }, width, 120, 35, 5, 16, { (double)orientation_ * 1, -1 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::ANP2(Entity* ent)
{
	std::cout << "-eeeeeeen" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 350;
	int hitboxX = -165;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -45 }, width, 120, 35, 8, 30, { (double)orientation_ * 75, -10 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::AHP1(Entity* ent)
{
	std::cout << "Get spiked son" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 125;
	int hitboxX = 115;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -65 }, width, 300, 25, 22, 65, { (double)orientation_ * 25, 1000000 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::ANK1(Entity* ent)
{
	std::cout << "Steppy" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 155;
	int hitboxX = 105;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, 125 }, width, 155, 17, 4, 15, { (double)orientation_ * 5, -5 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::ANK2(Entity* ent)
{
	std::cout << "STEPPY!!!" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 155;
	int hitboxX = 105;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, 135 }, width, 155, 17, 10, 28, { (double)orientation_ * 25, 25 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::AHK1(Entity* ent)
{
	std::cout << "Dropkick" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 250;
	int hitboxX = 50;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -75 }, width, 200, 50, 18, 55, { (double)orientation_ * 4000, 0 }, body, filter.categoryBits, filter.maskBits);
}

void FactoryMk::GB(Entity* ent)
{
}
