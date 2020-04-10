#include "AbilityFactory.h"
#include "PhysicsTransform.h"

AnimationChain* AbilityFactory::GiveMegatonGrip(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(35, nullptr, MG1, e));
	vecMov.push_back(new Move(7, nullptr, MG1, e));
	vecMov.push_back(new Move(7, nullptr, MG1, e));
	vecMov.push_back(new Move(7, nullptr, MG1, e));
	vecMov.push_back(new Move(7, nullptr, MG1, e));
	vecMov.push_back(new Move(35, nullptr, MG2, e));
	vecMov.push_back(new Move(125, nullptr, nullptr, e));
	AnimationChain* MegatonGrip = new AnimationChain(vecMov);
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



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-85 }, width, 150, 17, 15, 55, { (double)orientation_ * 4, 125 }, body, filter.categoryBits, filter.maskBits);
}

void AbilityFactory::MG2(Entity* ent)	//Finisher explosivo
{
	std::cout << "KABOOM" << endl;
	b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	b2Filter filter = body->GetFixtureList()->GetFilterData();
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	int width = 175;
	int hitboxX = 100;
	if (orientation_ == -1) hitboxX += width;



	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-85 }, width, 150, 17, 15, 55, { (double)orientation_ * 4, 125 }, body, filter.categoryBits, filter.maskBits);
}
