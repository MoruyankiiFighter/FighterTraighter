#include "AbilityFactory.h"
#include "PhysicsTransform.h"
#include "MkWH00PData.h"
#include "Entity.h"
#include "Bullet.h"
#include "RenderImage.h"
//#include "playerinfo"
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
//ability that kick the floor and moments later 3 rocks fall on top of the other player
AnimationChain* AbilityFactory::SeismicShock(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(35, nullptr, SeismicS1, e));//the kick
	//Entity* e = state->getEntityManager().addEntity();
	vecMov.push_back(new Move(50, nullptr, SeismicS2, e));//the rocks

	AnimationChain* Bullet = new AnimationChain(vecMov);
	return Bullet;
}
//the attack to the floor
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

}
//3 rocks
void AbilityFactory::SeismicS2(Entity* ent)
{
	Vector2D speed(0, 7);
	uint16 mask;
	//CollisionFilters
	App* app = ent->getApp();
	Entity* otherPlayer;
	GameState* currentState = app->getStateMachine()->getCurrentState();
	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0) {
		otherPlayer=app->getGameManager()->getPlayerInfo(2).entity;
		mask = currentState->PLAYER_2;
	}
	else {
		otherPlayer = app->getGameManager()->getPlayerInfo(1).entity;
		mask = currentState->PLAYER_1;
	}
	double otherWidth=otherPlayer->getComponent<PhysicsTransform>(ecs::Transform)->getWidth();
	Vector2D otherPos = otherPlayer->getComponent<PhysicsTransform>(ecs::Transform)->getPosition();
	Vector2D pos = Vector2D(otherPos.getX()+ otherWidth/2,0);//first rock
	Vector2D pos1;//second rock
	Vector2D pos2;//third rock
	int windowWidth = app->getWindowManager()->getCurResolution().w;
	double rocksSeparation = 150;
	if (pos.getX() + rocksSeparation >= (double)windowWidth)  pos1 = {(double) windowWidth, -160 };
	else pos1 = { pos.getX() + rocksSeparation, -320 };

	if (pos.getX() - rocksSeparation <= 0)  pos2 = { 0, -160 };
	else pos2 = { pos.getX() - rocksSeparation, -320 };
	//pos2 = Vector2D(otherPos.getX()-150, -320);
	int damage = 10;
	int hitstun = 0;
	Vector2D knockBack(5, 2);
	int time = 1000;
	bool destroyInContact = true;
	double width = 150;
	double height = 150;
	Texture* texture=app->getAssetsManager()->getTexture(AssetsManager::Player);
	createProyectile(ent, width,height,pos, speed, damage,hitstun,knockBack,time,mask,currentState,app,texture,destroyInContact);
	createProyectile(ent, width, height, pos1, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture,destroyInContact);
	createProyectile(ent, width, height, pos2, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture,destroyInContact);

}

void AbilityFactory::createProyectile(Entity* ent, double width, double height,Vector2D pos, Vector2D speed, int damage,
	int hitstun, Vector2D knockBack, int time, uint16 mask, GameState* currentState, App* app, Texture* texture,bool destroyInContact) {
	
	//App* app = ent->getApp();
	//PhysicsTransform* phTr = ent->getComponent<PhysicsTransform>(ecs::Transform);
	Entity* e = ent->getApp()->getStateMachine()->getCurrentState()->getEntityManager().addEntity();
	e->addComponent<PhysicsTransform>(pos, speed, width, height, 0, currentState->getb2World(),
		currentState->BULLET, mask, 1);
	e->addComponent<RenderImage>(texture);
	e->addComponent<Bullet>(currentState, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), speed, damage, hitstun, knockBack, time, destroyInContact);

}