#include "MkWH00PData.h"


//Esto es para geenrar hitboxes, habr? uno para cada hitbox generada
void MkWH00PData::NP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
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

void MkWH00PData::HP1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
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

void MkWH00PData::NK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
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

void MkWH00PData::NK2(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
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

void MkWH00PData::HK1(Entity* ent)//cBits and mBits are there to use the same collision filters as the body when adding hitboxes
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

void MkWH00PData::ANP1(Entity* ent)
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

void MkWH00PData::ANP2(Entity* ent)
{
	std::cout << "-eeeeeeen" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 84;
	int hitboxX = -42;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -20 }, width, 35, 35, 8, 30, { (double)orientation_ * 1.1, -0.25 }, body, filter.categoryBits, filter.maskBits);
}

void MkWH00PData::AHP1(Entity* ent)
{
	std::cout << "Get spiked son" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 38;
	int hitboxX = 25;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -25 }, width, 70, 25, 22, 65, { (double)orientation_ * 0.2, 1000000 }, body, filter.categoryBits, filter.maskBits);
}

void MkWH00PData::ANK1(Entity* ent)
{
	std::cout << "Steppy" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 45;
	int hitboxX = 15;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -10 }, width, 45, 17, 4, 15, { (double)orientation_ * 0.05, -0.05 }, body, filter.categoryBits, filter.maskBits);
}

void MkWH00PData::ANK2(Entity* ent)
{
	std::cout << "STEPPY!!!" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	int width = 45;
	int hitboxX = 17;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX, -12 }, width, 49, 17, 10, 28, { (double)orientation_ * 0.5, 1 }, body, filter.categoryBits, filter.maskBits);
}

void MkWH00PData::AHK1(Entity* ent)
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

void MkWH00PData::GB(Entity* ent)
{
}