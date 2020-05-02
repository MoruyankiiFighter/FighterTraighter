#include "AbilityFactory.h"
#include "PhysicsTransform.h"
#include "MkWH00PData.h"
#include "Entity.h"
#include "Bullet.h"
#include "RenderImage.h"
#include "PlayerAttacks.h"
//#include "playerinfo"


AnimationChain* AbilityFactory::GiveAbility(GameManager::AbilityID id, Entity* e) {
	return abilities_map[id](e);
}
AnimationChain* AbilityFactory::GiveMegatonGrip(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(50, nullptr, MG1, e));
	vecMov.push_back(new Move(10, nullptr, MG1, e));
	vecMov.push_back(new Move(10, nullptr, MG1, e));
	vecMov.push_back(new Move(10, nullptr, MG1, e));
	vecMov.push_back(new Move(10, nullptr, MG1, e));
	vecMov.push_back(new Move(50, nullptr, MG2, e));
	vecMov.push_back(new Move(100, nullptr, MGC, e));
	AnimationChain* MegatonGrip = new AnimationChain(vecMov);
	return MegatonGrip;
}

void AbilityFactory::MG1(Entity* ent)	//Golpes stuneantes
{
	std::cout << "RATATATA-" << endl;

	GameState* currentState = ent->getApp()->getStateMachine()->getCurrentState();
	Texture* texture = ent->getApp()->getAssetsManager()->getTexture(AssetsManager::Mg1);
	PhysicsTransform* phtr = ent->getComponent<PhysicsTransform>(ecs::Transform);

	uint16 mask;
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();


	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0) {
		mask = currentState->PLAYER_2;
	}
	else {
		mask = currentState->PLAYER_1;
	}

	////NO ME GUSTA AS� PERO NO S� C�MO HACERLO SI NO
	int width = 175;
	int projX = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (width / 2);
	if (orientation_ == -1) projX = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (width / 2);

	Vector2D pos = Vector2D(projX, phtr->getPosition().getY() + 225);
	createProyectile(ent, width, 150, pos, { 0, 0 }, 2, 50, { (double)orientation_ * 5, 5 }, 7, mask, ent->getState(), ent->getApp(), texture, false);
}

void AbilityFactory::MG2(Entity* ent)	//Finisher explosivo
{
	std::cout << "KABOOM" << endl;
	//b2Body* body = ent->getComponent<PhysicsTransform>(ecs::Transform)->getBody();//{ 200,0 }, 50, 50, 10, 50, { 0,0 }
	//b2Filter filter = body->GetFixtureList()->GetFilterData();

	GameState* currentState = ent->getApp()->getStateMachine()->getCurrentState();
	Texture* texture1 = ent->getApp()->getAssetsManager()->getTexture(AssetsManager::Mg21);
	Texture* texture2 = ent->getApp()->getAssetsManager()->getTexture(AssetsManager::Mg22);
	PhysicsTransform* phtr = ent->getComponent<PhysicsTransform>(ecs::Transform);

	uint16 mask;
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0) {
		mask = currentState->PLAYER_2;
	}
	else {
		mask = currentState->PLAYER_1;
	}

	//NO ME GUSTA AS� PERO NO S� C�MO HACERLO SI NO
	int width1 = 150;
	int projX1 = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (width1 / 2);
	if (orientation_ == -1) projX1 = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (width1 / 2);

	Vector2D pos1 = Vector2D(projX1, phtr->getPosition().getY() + 225);
	createProyectile(ent, width1, 150, pos1, { 0, 0 }, 27, 100, { (double)orientation_ * 7500, -5000 }, 15, mask, ent->getState(), ent->getApp(), texture1, false);

	int width2 = 250;
	int projX2 = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (width2 / 2) + 150;
	if (orientation_ == -1) projX2 = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (width2 / 2) - 150;

	Vector2D pos2 = Vector2D(projX2, phtr->getPosition().getY() + 225);
	createProyectile(ent, width2, 180, pos2, { 0, 0 }, 2, 150, { (double)orientation_ * 5250, -4000 }, 12, mask, ent->getState(), ent->getApp(), texture2, false);

	//ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX1,-85 }, width1, 175, 15, 27, 100, { (double)orientation_ * 7500, -5000 }, body, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent, filter.categoryBits, filter.maskBits);
	//ent->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX2,-85 }, width2, 180, 12, 2, 150, { (double)orientation_ * 5250, -4000 }, body, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent, filter.categoryBits, filter.maskBits);
}

void AbilityFactory::MGC(Entity* ent)
{
	goOnCoolodwn(ent, 600);
}

AnimationChain* AbilityFactory::GiveSeismicShock(Entity* e) //ability that kick the floor and moments later 3 rocks fall on top of the other player
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(35, nullptr, SeismicS1, e));	//the kick
	vecMov.push_back(new Move(20, nullptr, SeismicS2, e));	//the rocks going up
	vecMov.push_back(new Move(0, nullptr, SeismicSC, e));	//the cooldown
	vecMov.push_back(new Move(90, nullptr, SeismicS3, e));	//the punches going down

	AnimationChain* SeismicShock = new AnimationChain(vecMov);
	return SeismicShock;
}

void AbilityFactory::SeismicS1(Entity* e)	//the attack to the floor
{
	std::cout << "Heave to!" << endl;
	Texture* texture = e->getApp()->getAssetsManager()->getTexture(AssetsManager::Ss1);
	PhysicsTransform* phtr = e->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = phtr->getOrientation();

	App* app = e->getApp();
	Entity* otherPlayer;
	GameState* currentState = app->getStateMachine()->getCurrentState();
	uint16 mask;
	if (e->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0) {
		otherPlayer = app->getStateMachine()->getCurrentState()->getEntityManager().getHandler(ecs::Player2);
		mask = currentState->PLAYER_2;
	}
	else {
		otherPlayer = app->getStateMachine()->getCurrentState()->getEntityManager().getHandler(ecs::Player1);
		mask = currentState->PLAYER_1;
	}

	int width = 120;
	int projX = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (width / 2);
	if (orientation_ == -1) projX = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (width / 2);

	//e->getApp()->getStateMachine()->getCurrentState()->addHitbox({ (double)orientation_ * hitboxX, 105 }, width, 150, 17, 17, 50, { (double)orientation_ * 5, -100 }, pT->getBody(), e->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), e, pT->getCategory(), pT->getMask());
	Vector2D pos = Vector2D(projX, phtr->getPosition().getY() + phtr->getHeight() + -75);
	createProyectile(e, width, 150, pos, { 0, 0 }, 17, 200, { (double)orientation_ * 5, 5 }, 50, mask, e->getState(), e->getApp(), texture, false);
}

void AbilityFactory::SeismicS2(Entity* ent)	//Big rock upwards
{
	std::cout << "Rise up gamers" << endl;
	Texture* texture = ent->getApp()->getAssetsManager()->getTexture(AssetsManager::Ss2);
	PhysicsTransform* phtr = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = phtr->getOrientation();

	int width = 300;
	int projX = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (width / 2) + 60;
	if (orientation_ == -1) projX = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (width / 2) - 60;

	Vector2D pos = Vector2D(projX, phtr->getPosition().getY() + phtr->getHeight() + 150);
	createProyectile(ent, width, 300, pos, { 0,-10 }, 0, 0, { 0,0 }, 250, ent->getState()->NONE, ent->getState(), ent->getApp(), texture, false);
}

void AbilityFactory::SeismicS3(Entity* ent)	//3 rocks
{
	std::cout << "Meatballs" << endl;
	Vector2D speed(0, 7);
	uint16 mask;
	//CollisionFilters
	App* app = ent->getApp();
	Entity* otherPlayer;
	GameState* currentState = app->getStateMachine()->getCurrentState();
	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0) {
		otherPlayer = app->getStateMachine()->getCurrentState()->getEntityManager().getHandler(ecs::Player2);
		mask = currentState->PLAYER_2;
	}
	else {
		otherPlayer = app->getStateMachine()->getCurrentState()->getEntityManager().getHandler(ecs::Player1);
		mask = currentState->PLAYER_1;
	}
	double otherWidth = otherPlayer->getComponent<PhysicsTransform>(ecs::Transform)->getWidth();
	Vector2D otherPos = otherPlayer->getComponent<PhysicsTransform>(ecs::Transform)->getPosition();
	Vector2D pos = Vector2D(otherPos.getX() + otherWidth / 2, 0);//first rock

	double rocksSeparation = 240;
	Vector2D pos1 = Vector2D(pos.getX() + rocksSeparation, -320);//second rock
	Vector2D pos2 = Vector2D(pos.getX() - rocksSeparation, -640);//third rock
	//pos2 = Vector2D(otherPos.getX()-150, -320);

	int damage = 10;
	int hitstun = 9;
	Vector2D knockBack(5, 2);
	int time = 165;
	bool destroyInContact = true;
	double width = 150;
	double height = 150;

	Texture* texture = app->getAssetsManager()->getTexture(AssetsManager::Ss2);
	createProyectile(ent, width, height, pos, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture, destroyInContact);
	createProyectile(ent, width, height, pos1, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture, destroyInContact);
	createProyectile(ent, width, height, pos2, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture, destroyInContact);
}

void AbilityFactory::SeismicSC(Entity* ent)
{
	goOnCoolodwn(ent, 17 * 60);
}

AnimationChain* AbilityFactory::GiveExplosiveWillpower(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(1, nullptr, EWC, e));
	vecMov.push_back(new Move(10, nullptr, EW1, e));
	vecMov.push_back(new Move(10, nullptr, EW2, e));
	vecMov.push_back(new Move(10, nullptr, EW3, e));
	vecMov.push_back(new Move(10, nullptr, nullptr, e));
	AnimationChain* MegatonGrip = new AnimationChain(vecMov);
	return MegatonGrip;
}

void AbilityFactory::EWC(Entity* ent)
{
	goOnCoolodwn(ent, 7 * 60);
}

void AbilityFactory::EW1(Entity* ent)
{
	App* app = ent->getApp();
	Entity* otherPlayer;
	GameState* currentState = app->getStateMachine()->getCurrentState();
	uint16 mask;

	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0) {
		otherPlayer = app->getStateMachine()->getCurrentState()->getEntityManager().getHandler(ecs::Player2);
		mask = currentState->PLAYER_2;
	}
	else {
		otherPlayer = app->getStateMachine()->getCurrentState()->getEntityManager().getHandler(ecs::Player1);
		mask = currentState->PLAYER_1;
	}

	std::cout << "Falcon stomp" << endl;
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();

	int width1 = 175;
	int hitboxX1 = 100;
	if (orientation_ == -1) hitboxX1 += width1;
	createProyectile(ent, width1, 100, { 100, 100 }, { 0, 0 }, 100, 55, {0, 0}, 15, mask, currentState, app, app->getAssetsManager()->getTexture(AssetsManager::Player), true);
}

void AbilityFactory::EW2(Entity* ent)
{
}

void AbilityFactory::EW3(Entity* ent)
{
}

////no se usa
//AnimationChain* AbilityFactory::Bullets(Entity* e)
//{
//	std::vector<Move*> vecMov;
//	//Entity* e = state->getEntityManager().addEntity();
//	Vector2D speed = { 10000, 0 };
//	vecMov.push_back(new Move(50, nullptr, Bullet1, e));
//
//	AnimationChain* Bullet = new AnimationChain(vecMov);
//	return Bullet;
//}
//
////no se usa
//void AbilityFactory::Bullet1(Entity* ent)	//Golpes stuneantes
//{
//	//CollisionFilters
//	App* app = ent->getApp();
//	GameState* currentState = app->getStateMachine()->getCurrentState();
//	uint16 mask;
//	Entity* e = ent->getApp()->getStateMachine()->getCurrentState()->getEntityManager().addEntity();
//	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0)  mask = currentState->PLAYER_2;
//	else   mask = currentState->PLAYER_1;
//
//	PhysicsTransform* phTr = ent->getComponent<PhysicsTransform>(ecs::Transform);
//	Vector2D pos = Vector2D(phTr->getPosition().getX() + phTr->getWidth(), phTr->getPosition().getY() + phTr->getHeight() / 2);
//	//Bullet(GameState* state, uint16 playerNumber,Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact = false);
//	e->addComponent<PhysicsTransform>(pos, Vector2D(0, 0), 80, 20, 0, currentState->getb2World(),
//		currentState->BULLET, mask, 1);
//	e->addComponent<RenderImage>(app->getAssetsManager()->getTexture(AssetsManager::Player));
//	e->addComponent<Bullet>(ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), Vector2D(10000, 0), 10, 0, Vector2D(50, 50), 1000, true);
//}

void AbilityFactory::createProyectile(Entity* ent, double width, double height,Vector2D pos, Vector2D speed, int damage,
	int hitstun, Vector2D knockBack, int time, uint16 mask, GameState* currentState, App* app, Texture* texture,bool destroyInContact) {
	double windowWidth = app->getWindowManager()->getCurResolution().w;
	if (pos.getX() >= windowWidth)  pos.setX(windowWidth);
	else if (pos.getX() <= 0)  pos.setX(0);
	//App* app = ent->getApp();
	//PhysicsTransform* phTr = ent->getComponent<PhysicsTransform>(ecs::Transform);
	Entity* e = ent->getApp()->getStateMachine()->getCurrentState()->getEntityManager().addEntity();
	e->addComponent<PhysicsTransform>(pos, speed, width, height, 0, currentState->getb2World(),
		currentState->BULLET, mask, 1);
	e->addComponent<RenderImage>(texture);
	e->addComponent<Bullet>(ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), speed, damage, hitstun, knockBack, time, destroyInContact);

}

void AbilityFactory::goOnCoolodwn(Entity* e, int cool)
{
	PlayerAttacks* pl = e->getComponent<PlayerAttacks>(ecs::PlayerAttacks);
	pl->goOnCooldown(pl->getAbilityIndex(), cool);
}

std::map<GameManager::AbilityID, std::function<AnimationChain * (Entity*)>> AbilityFactory::abilities_map = {
	{GameManager::AbilityID::SeismicShock, AbilityFactory::GiveSeismicShock},
	{GameManager::AbilityID::MegatonGrip, AbilityFactory::GiveMegatonGrip}
};