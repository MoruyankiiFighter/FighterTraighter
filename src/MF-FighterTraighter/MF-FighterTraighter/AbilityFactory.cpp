#include "AbilityFactory.h"
#include "PhysicsTransform.h"

AnimationChain* AbilityFactory::GiveMegatonGrip(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(50, nullptr, MG1, e));
	vecMov.push_back(new Move(10, nullptr, MG1, e));
	vecMov.push_back(new Move(10, nullptr, MG1, e));
	vecMov.push_back(new Move(10, nullptr, MG1, e));
	vecMov.push_back(new Move(10, nullptr, MG1, e));
	vecMov.push_back(new Move(50, nullptr, MG2, e));
	vecMov.push_back(new Move(125, nullptr, nullptr, e));
	AnimationChain* MegatonGrip = new AnimationChain(vecMov);
	return MegatonGrip;
}

void AbilityFactory::MG1(Entity* ent)	//Golpes stuneantes
{
	std::cout << "RATATATA-" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 175;
	int hitboxX = 100;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-75 }, width, 150, 7, 2, 50, { (double)orientation_ * 0, 0 }, body, filter.categoryBits, filter.maskBits);
}

void AbilityFactory::MG2(Entity* ent)	//Finisher explosivo
{
	std::cout << "KABOOM" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width1 = 175;
	int hitboxX1 = 100;
	if (orientation_ == -1) hitboxX1 += width1;

	int width2 = 250;
	int hitboxX2 = 280;
	if (orientation_ == -1) hitboxX2 += width2;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX1,-85 }, width1, 175, 15, 27, 100, { (double)orientation_ * 500, 0 }, body, filter.categoryBits, filter.maskBits);
	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX2,-85 }, width2, 180, 12, 2, 150, { (double)orientation_ * 400, 0 }, body, filter.categoryBits, filter.maskBits);
}
