#include "AbilityFactory.h"
#include "PhysicsTransform.h"
#include "MkWH00PData.h"
#include "Entity.h"
#include "Bullet.h"
#include "RenderImage.h"
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

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX,-75 }, width, 150, 7, 2, 50,
		{ (double)orientation_ * 0, 0 }, body, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), filter.categoryBits, filter.maskBits);
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

	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX1,-85 }, width1, 175, 15, 27, 100, { (double)orientation_ * 500, 0 }, body, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), filter.categoryBits, filter.maskBits);
	ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX2,-85 }, width2, 180, 12, 2, 150, { (double)orientation_ * 400, 0 }, body, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), filter.categoryBits, filter.maskBits);
}


AnimationChain* AbilityFactory::Bullets(Entity* e)
{
	std::vector<Move*> vecMov;
	//Entity* e = state->getEntityManager().addEntity();
	Vector2D speed = { 10000, 0 };
	vecMov.push_back(new Move(50, nullptr, Bullet1, e));
	
	AnimationChain* Bullet = new AnimationChain(vecMov);
	return Bullet;
}

void AbilityFactory::Bullet1(Entity* ent)	//Golpes stuneantes
{
	//CollisionFilters
	App* app = ent->getApp();
	GameState* currentState = app->getStateMachine()->getCurrentState();
	uint16 mask;
	Entity* e = ent->getApp()->getStateMachine()->getCurrentState()->getEntityManager().addEntity();
	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0)  mask = currentState->PLAYER_2;
	else   mask = currentState->PLAYER_1;

	PhysicsTransform* phTr = ent->getComponent<PhysicsTransform>(ecs::Transform);
	Vector2D pos =  Vector2D(phTr->getPosition().getX()+ phTr->getWidth(), phTr->getPosition().getY()+phTr->getHeight()/2) ;
	//Bullet(GameState* state, uint16 playerNumber,Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact = false);
	e->addComponent<PhysicsTransform>(pos, Vector2D(0, 0), 80,20, 0, currentState->getb2World(),
		currentState->BULLET, mask, 1);
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::Player));
	e->addComponent<Bullet>(currentState, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), Vector2D(10000, 0), 10, 0, Vector2D(50, 50), 1000, true);
}

AnimationChain* AbilityFactory::SeismicShock(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(35, nullptr, SeismicS1, e));
	//Entity* e = state->getEntityManager().addEntity();
	vecMov.push_back(new Move(50, nullptr, SeismicS2, e));

	AnimationChain* Bullet = new AnimationChain(vecMov);
	return Bullet;
}

void AbilityFactory::SeismicS1(Entity* e) {
	

	std::cout << "Falcon stomp" << endl;
	PhysicsTransform* pT = e->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width1 = 120;
	int hitboxX1 = 130;
	if (orientation_ == -1) hitboxX1 += width1;
	int width2 = 600;
	int hitboxX2 = 0;
	if (orientation_ == -1) hitboxX2 += width2;



	e->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX1, 105 }, width1, 150, 17, 17, 50, { (double)orientation_ * 5, -100 }, pT->getBody(), e->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());
	std::cout << "Brrrrrjrnkrrbr" << endl;
	//e->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX2, 220 }, width2, 50, 20, 5, 40, { (double)orientation_ * 500, -150 }, pT->getBody(), e->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), pT->getCategory(), pT->getMask());

}

void AbilityFactory::SeismicS2(Entity* ent)
{
	Vector2D speed(0, 150);
	uint16 mask;
	//CollisionFilters
	App* app = ent->getApp();
	GameState* currentState = app->getStateMachine()->getCurrentState();
	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0)  mask = currentState->PLAYER_2;
	else   mask = currentState->PLAYER_1;
	
	Vector2D pos = Vector2D(900,0);
	Vector2D pos1 = Vector2D(1100,-100);
	Vector2D pos2 = Vector2D(1300, -130);
	createProyectile(ent, pos, speed, mask,currentState,app);
	createProyectile(ent, pos2, speed, mask, currentState, app);

	createProyectile(ent, pos1, speed, mask, currentState, app);

	//Bullet(GameState* state, uint16 playerNumber,Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact = false);
}

void AbilityFactory::createProyectile(Entity* ent, Vector2D pos,Vector2D speed, uint16 mask, GameState* currentState,App* app) {
	
	//App* app = ent->getApp();
	PhysicsTransform* phTr = ent->getComponent<PhysicsTransform>(ecs::Transform);
	Entity* e = ent->getApp()->getStateMachine()->getCurrentState()->getEntityManager().addEntity();
	e->addComponent<PhysicsTransform>(pos, speed, 150, 150, 0, currentState->getb2World(),
		currentState->BULLET, mask, 1);
	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::Player));
	e->addComponent<Bullet>(currentState, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), speed, 10, 0, Vector2D(50, 50), 1000, true);

}