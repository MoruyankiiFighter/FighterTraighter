#include "AbilityFactory.h"
#include "PhysicsTransform.h"
#include "MkWH00PData.h"
#include "Entity.h"
#include "Bullet.h"
#include "RenderImage.h"
#include "PlayerAttacks.h"
#include "BulletGravity.h"
#include "Fall_SpawnOnHit.h"
#include "DestroyAtTime.h"
#include "Health.h"
#include "VampiricDestroyAtTime.h"
#include "PlayerData.h"

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
	vecMov.push_back(new Move(80, nullptr, MGC, e));
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
	DestroyAtTime* dT = new DestroyAtTime(2, 7, 50, { (double)orientation_ * 0.5, 0.5 }, false, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent);
	instanceEntitywHitbox(ent, width, 150, pos, { 0, 0 }, mask, ent->getState(), ent->getApp(), texture, orientation_, dT);
	
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
	int id = ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber();
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
	//createProyectile(ent, width1, 150, pos1, { 0, 0 }, 27, 100, { (double)orientation_ * 7500, -5000 }, 15, mask, ent->getState(), ent->getApp(), texture1, orientation_, false);
	DestroyAtTime* dT = new DestroyAtTime(27, 15, 100, { (double)orientation_ * 40, -8 }, false, id, ent);
	instanceEntitywHitbox(ent, width1, 150, pos1, { 0,0 }, mask, ent->getState(), ent->getApp(), texture1, orientation_, dT);
	int width2 = 250;
	int projX2 = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (width2 / 2) + 150;
	if (orientation_ == -1) projX2 = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (width2 / 2) - 150;

	Vector2D pos2 = Vector2D(projX2, phtr->getPosition().getY() + 225);
	 dT = new DestroyAtTime(2, 12, 150, { (double)orientation_ * 30, -5 }, false, id, ent);
	//createProyectile(ent, width2, 180, pos2, { 0, 0 }, 2, 150, { (double)orientation_ * 5250, -4000 }, 12, mask, ent->getState(), ent->getApp(), texture2, orientation_, false);
	instanceEntitywHitbox(ent, width2, 180, pos2, { 0,0 }, mask, ent->getState(), ent->getApp(), texture1, orientation_, dT);

}

void AbilityFactory::MGC(Entity* ent)
{
	goOnCoolodwn(ent, 60*10);
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
	DestroyAtTime* dT = new DestroyAtTime(17, 50, 200, { (double)orientation_ * 5, 5 }, false, e->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), e);
	//createProyectile(e, width, 150, pos, { 0, 0 }, 17, 200, { (double)orientation_ * 5, 5 }, 50, mask, e->getState(), e->getApp(), texture, orientation_, false);
	instanceEntitywHitbox(e, width, 150, pos, { 0,0 }, mask, e->getState(), e->getApp(), texture, orientation_, dT);
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
	DestroyAtTime* dT = new DestroyAtTime(0, 250, 0, { 0,0 }, false, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent);
	//createProyectile(ent, width, 300, pos, { 0,-10 }, 0, 0, { 0,0 }, 250, ent->getState()->NONE, ent->getState(), ent->getApp(), texture, orientation_, false);
	instanceEntitywHitbox(ent, width, 300, pos, { 0,-10 }, ent->getState()->NONE, ent->getState(), ent->getApp(), texture, orientation_, dT);
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
	int orientation_ = otherPlayer->getComponent<PhysicsTransform>(ecs::Transform)->getOrientation();
	Vector2D pos = Vector2D(otherPos.getX() + otherWidth / 2, 0);//first rock

	double rocksSeparation = 240;
	Vector2D pos1 = Vector2D(pos.getX() + rocksSeparation, -320);//second rock
	Vector2D pos2 = Vector2D(pos.getX() - rocksSeparation, -640);//third rock
	//pos2 = Vector2D(otherPos.getX()-150, -320);

	int damage = 10;
	int hitstun = 9;
	Vector2D knockBack(5, 2);
	int time = 165;
	//bool destroyInContact = true;
	//bool multiHit = false;
	double width = 150;
	double height = 150;	
	bool guardBreaker = false;
	int id = ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber();
	Texture* texture = app->getAssetsManager()->getTexture(AssetsManager::Ss2);
	DestroyOnHit* dH = new DestroyOnHit(damage,time,hitstun, knockBack, guardBreaker, id, ent);
	DestroyOnHit* dH1 = new DestroyOnHit(damage, time, hitstun, knockBack, guardBreaker, id, ent);
	DestroyOnHit* dH2 = new DestroyOnHit(damage, time, hitstun, knockBack, guardBreaker, id, ent);

	
	/*createProyectile(ent, width, height, pos, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture, orientation_, destroyInContact);
	createProyectile(ent, width, height, pos1, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture, orientation_, destroyInContact);
	createProyectile(ent, width, height, pos2, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture, orientation_, destroyInContact);*/
	instanceEntitywHitbox(ent, width, height, pos, speed, mask, currentState, app, texture, orientation_, dH);
	instanceEntitywHitbox(ent, width, height, pos1, speed, mask, currentState, app, texture, orientation_, dH1);
	instanceEntitywHitbox(ent, width, height, pos2, speed, mask, currentState, app, texture, orientation_, dH2);

}

void AbilityFactory::SeismicSC(Entity* ent)
{
	goOnCoolodwn(ent, 10 * 60);
}

AnimationChain* AbilityFactory::GiveExplosiveWillpower(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(1, nullptr, EWC, e));
	vecMov.push_back(new Move(40, nullptr, EW1, e));
	//vecMov.push_back(new Move(10, nullptr, EW2, e));
	//vecMov.push_back(new Move(10, nullptr, EW3, e));
	vecMov.push_back(new Move(25, nullptr, nullptr, e));
	AnimationChain* ExplosiveWillpower = new AnimationChain(vecMov);
	return ExplosiveWillpower;
}

void AbilityFactory::EWC(Entity* ent)
{
	goOnCoolodwn(ent, 0 * 60);
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

#if _DEBUG
	std::cout << "No estoy explotando por dentro" << endl;
#endif
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = pT->getOrientation();
	Texture* tex = app->getAssetsManager()->getTexture(AssetsManager::Ew1);
	int damage = 10;
	int time = 25;
	int hitstun = 55;
	Vector2D knockback = { 10.0 * orientation_, -5.0 };
	bool guardBreaker = false;
	int id = ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber();
	DestroyAtTime* dT = new DestroyAtTime(damage, time, hitstun, knockback, guardBreaker, id, ent);
	//Palante
	int width1 = 100;
	int projX1 = pT->getPosition().getX() + (pT->getWidth() * 3 / 4) + (width1 / 2) - 80;
	if (orientation_ == -1) projX1 = pT->getPosition().getX() + (pT->getWidth() * 1 / 4) - (width1 / 2) + 80;
	Vector2D pos1 = Vector2D(projX1, pT->getPosition().getY() + (pT->getHeight() / 2));
	
	//createProyectile(ent, width1, 375, pos1, { 4.5 * orientation_, 0 }, 10, 55, { 10.0 * orientation_, -5.0 }, 25, mask, currentState, app, app->getAssetsManager()->getTexture(AssetsManager::Ew1), orientation_, false);
	instanceEntitywHitbox(ent, width1, 375, pos1, { 4.5 * orientation_, 0 }, mask, currentState, app, tex, orientation_, dT);
	//Patrás
	int width2 = 100;
	int projX2 = pT->getPosition().getX() + (pT->getWidth() * 1 / 4) - (width2 / 2) + 80;
	if (orientation_ == -1) projX2 = pT->getPosition().getX() + (pT->getWidth() * 3 / 4) + (width2 / 2) - 80;
	Vector2D pos2 = Vector2D(projX2, pT->getPosition().getY() + (pT->getHeight() / 2));
	knockback = { -10.0 * orientation_, -5.0 };
	dT = new DestroyAtTime(damage, time, hitstun, knockback, guardBreaker, id, ent);
	//createProyectile(ent, width2, 375, pos2, { -4.5 * orientation_, 0 }, 10, 55, { -10.0 * orientation_, -5.0 }, 25, mask, currentState, app, app->getAssetsManager()->getTexture(AssetsManager::Ew1), -orientation_, false);
	instanceEntitywHitbox(ent, width2, 375, pos2, { -4.5 * orientation_, 0 }, mask, currentState, app, tex, orientation_, dT);

	//Parriba
	/*int width3 = 160;
	int projX3 = pT->getPosition().getX() + (pT->getWidth() * 2 / 4);
	Vector2D pos3 = Vector2D(projX3, pT->getPosition().getY() + 75);
	createProyectile(ent, width3, 60, pos3, { 0, -5.0 }, 20, 55, { 0, -10.0}, 25, mask, currentState, app, app->getAssetsManager()->getTexture(AssetsManager::Player), false);*/
}

void AbilityFactory::EW2(Entity* ent)
{
	///<bbgzccvfAFG
}

void AbilityFactory::EW3(Entity* ent)
{
}

AnimationChain* AbilityFactory::GiveAcidSplit(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(1, nullptr, ASC, e));
	vecMov.push_back(new Move(40, nullptr, AS1, e));
	//vecMov.push_back(new Move(10, nullptr, EW2, e));
	//vecMov.push_back(new Move(10, nullptr, EW3, e));
	//vecMov.push_back(new Move(25, nullptr, nullptr, e));
	AnimationChain* AcidSplit = new AnimationChain(vecMov);
	return AcidSplit;
}

void AbilityFactory::AS1(Entity* ent)
{
	Vector2D speed(10, 0);
	uint16 mask;
	//CollisionFilters
	App* app = ent->getApp();
	Entity* otherPlayer;
	GameState* currentState = app->getStateMachine()->getCurrentState();
	if (ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber() == 0) {
		otherPlayer = app->getStateMachine()->getCurrentState()->getEntityManager().getHandler(ecs::Player2);
		mask = currentState->PLAYER_2 | currentState->BOUNDARY;
	}
	else {
		otherPlayer = app->getStateMachine()->getCurrentState()->getEntityManager().getHandler(ecs::Player1);
		mask = currentState->PLAYER_1 | currentState->BOUNDARY;
	}
	PhysicsTransform* phTr = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = otherPlayer->getComponent<PhysicsTransform>(ecs::Transform)->getOrientation();
	Vector2D pos = Vector2D(phTr->getPosition().getX() + phTr->getWidth() / 2, phTr->getPosition().getY() + phTr->getHeight()/2);//first rock

	
	//pos2 = Vector2D(otherPos.getX()-150, -320);

	int damage = 10;
	int hitstun = 9;
	Vector2D knockBack(5, 2);
	int time = 165;
	//bool destroyInContact = false;
	double width = 150;
	double height = 150;
	bool gravity = true;
	bool multiHit = true;
	DestroyAtTime* dT = new DestroyAtTime(0.1, time, 0, Vector2D(0, 0), false, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent, multiHit);
	dT->enableMultiHit(5);
	Texture* spawntexture = app->getAssetsManager()->getTexture(AssetsManager::As2);
	Vector2D spawnEntSize(spawntexture->getWidth() * 3, spawntexture->getHeight());
	Fall_SpawnOnHit* fL = new Fall_SpawnOnHit(damage, time, hitstun, knockBack, false, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent, dT, spawntexture, spawnEntSize);	
	Texture* texture = app->getAssetsManager()->getTexture(AssetsManager::Ss2);
	instanceEntitywHitbox(ent, width, height, pos, speed, mask, currentState, app, texture, orientation_ ,fL, gravity);
	//createProyectile(ent, width, height, pos, speed, damage, hitstun, knockBack, time, mask, currentState, app, texture, orientation_, destroyInContact, gravity);
}

void AbilityFactory::ASC(Entity* ent)
{
	goOnCoolodwn(ent,60 * 5);
}

AnimationChain* AbilityFactory::GiveShrugOff(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(15, nullptr, SO1, e));
	vecMov.push_back(new Move(35, nullptr, SOC, e));
	AnimationChain* ShrugOff = new AnimationChain(vecMov);
	return ShrugOff;
}

void AbilityFactory::SO1(Entity* ent)
{
#if _DEBUG
	std::cout << "Guess I won't die" << endl;
#endif
	ent->getComponent<Health>(ecs::Health)->setMultiplier(0, false);

	App* app = ent->getApp();
	PhysicsTransform* phTr = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = ent->getComponent<PhysicsTransform>(ecs::Transform)->getOrientation();

	int width = 250;
	int projX = phTr->getPosition().getX() + (phTr->getWidth() * 1 / 4) + (phTr->getWidth() / 4);
	if (orientation_ == -1) projX = phTr->getPosition().getX() + (phTr->getWidth() * 3 / 4) - (phTr->getWidth() / 4);
	Vector2D pos = Vector2D(projX, phTr->getPosition().getY() + (phTr->getHeight() / 2));

	DestroyAtTime* dT = new DestroyAtTime(0, 35, 0, { 0,0 }, false, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent);
	instanceEntitywHitbox(ent, width, 250, pos, { 0, 0 }, ent->getState()->NONE, ent->getState(), ent->getApp(), app->getAssetsManager()->getTexture(AssetsManager::So1), orientation_, dT);

	//createProyectile(ent, width, 250, pos, { 0, 0 }, 0, 0, { 0, 0 }, 35, app->getStateMachine()->getCurrentState()->NONE, 
		//app->getStateMachine()->getCurrentState(), app, app->getAssetsManager()->getTexture(AssetsManager::So1), orientation_);
}

void AbilityFactory::SOC(Entity* ent)
{
	goOnCoolodwn(ent, 60 * 6.5);
}

AnimationChain* AbilityFactory::GiveMorePower(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(15, nullptr, MP1, e));
	vecMov.push_back(new Move(35, nullptr, MPC, e));
	AnimationChain* MorePower = new AnimationChain(vecMov);
	return MorePower;
}

void AbilityFactory::MP1(Entity* ent)
{
#if _DEBUG
	std::cout << "Guess YOU'll die" << endl;
#endif
	ent->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->setMultiplier(2, false);

	App* app = ent->getApp();
	PhysicsTransform* phTr = ent->getComponent<PhysicsTransform>(ecs::Transform);
	int orientation_ = ent->getComponent<PhysicsTransform>(ecs::Transform)->getOrientation();

	int width = 250;
	int projX = phTr->getPosition().getX() + (phTr->getWidth() * 1 / 4) + (phTr->getWidth() / 4);
	if (orientation_ == -1) projX = phTr->getPosition().getX() + (phTr->getWidth() * 3 / 4) - (phTr->getWidth() / 4);
	Vector2D pos = Vector2D(projX, phTr->getPosition().getY() + (phTr->getHeight() / 2));
	DestroyAtTime* dT = new DestroyAtTime(0, 35, 0, { 0,0 }, false, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent);
	instanceEntitywHitbox(ent, width, 250, pos, { 0, 0 }, ent->getState()->NONE, ent->getState(), ent->getApp(), app->getAssetsManager()->getTexture(AssetsManager::Mp1), orientation_, dT);

}

void AbilityFactory::MPC(Entity* ent)
{
	goOnCoolodwn(ent, 60 * 6.5);
}

AnimationChain* AbilityFactory::GiveHookshot(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(25, nullptr, HS1, e));
	vecMov.push_back(new Move(25, nullptr, HSC, e));
	AnimationChain* Hookshot = new AnimationChain(vecMov);
	return Hookshot;
}

void AbilityFactory::HS1(Entity* ent)
{
#if _DEBUG
	std::cout << "Sweet sweet lollypopping" << endl;
#endif
	GameState* currentState = ent->getApp()->getStateMachine()->getCurrentState();
	Texture* texture = ent->getApp()->getAssetsManager()->getTexture(AssetsManager::Hs1);
	PhysicsTransform* phtr = ent->getComponent<PhysicsTransform>(ecs::Transform);

	uint16 mask;
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();
	int orX, desX;

	PlayerData* pD = ent->getComponent<PlayerData>(ecs::PlayerData);
	orX = phtr->getPosition().getX() + (phtr->getWidth() / 2);
	if (pD->getPlayerNumber() == 0) {
		mask = currentState->PLAYER_2 | currentState->P_BAG;
		PhysicsTransform* otherPlayer = currentState->getEntityManager().getHandler(ecs::Player2)->getComponent<PhysicsTransform>(ecs::Transform);
		desX = otherPlayer->getPosition().getX() + (otherPlayer->getWidth() / 2);
	}
	else {
		mask = currentState->PLAYER_1 | currentState->P_BAG;
		PhysicsTransform* otherPlayer = currentState->getEntityManager().getHandler(ecs::Player1)->getComponent<PhysicsTransform>(ecs::Transform);
		desX = otherPlayer->getPosition().getX() + (otherPlayer->getWidth() / 2);
	}

	int width = 145;
	int projX = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (width / 2);
	if (orientation_ == -1) projX = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (width / 2);

	Vector2D pos = Vector2D(projX, phtr->getPosition().getY() + 300);

	DestroyOnHit* dT = new DestroyOnHit(3, 60, 40, { (double)orientation_ * (orX - desX) * 0.055, 0 }, false, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent);

	AbilityFactory::instanceEntitywHitbox(ent, width, 145, pos, { (double)orientation_ * 9, 0 }, mask, ent->getState(), ent->getApp(), texture, orientation_, dT);
}

void AbilityFactory::HSC(Entity* ent)
{
	goOnCoolodwn(ent, 60 * 12);
}

AnimationChain* AbilityFactory::GiveDash(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(0, nullptr, Dash, e));
	vecMov.push_back(new Move( 0, nullptr, DashC, e));
	AnimationChain* Dash = new AnimationChain(vecMov);
	return Dash;
}

void AbilityFactory::Dash(Entity* ent)
{
	PlayerData* pD= ent->getComponent<PlayerData>(ecs::PlayerData);
	PhysicsTransform* pT = ent->getComponent<PhysicsTransform>(ecs::Transform);
	Vector2D knockBack;
	HID* inputSt_ = ent->getApp()->getGameManager()->getPlayerInfo(pD->getPlayerNumber()+1).hid;
	 
	if (inputSt_->ButtonDown(HID::LeftPad_Left) || inputSt_->AxisInput(HID::LJoyX) < 0) {
		knockBack = Vector2D{ -50, 0 };
	}
	else if ((inputSt_->ButtonDown(HID::LeftPad_Right) || inputSt_->AxisInput(HID::LJoyX) > 0)) {
		knockBack = Vector2D{ 50, 0 };

	}
	else {
		if (pT->getOrientation() == 1) {
			knockBack =Vector2D { 50, 0 };
		}
		else {
			knockBack = Vector2D{ -50, 0 };
		}
	}
	pT->getBody()->ApplyLinearImpulse(b2Vec2(knockBack.getX(), knockBack.getY()), pT->getBody()->GetWorldCenter(), true);

}

void AbilityFactory::DashC(Entity* ent)
{
	goOnCoolodwn(ent, 60 * 8);
}

AnimationChain* AbilityFactory::GiveVampiricStrike(Entity* e)
{
	std::vector<Move*> vecMov;
	vecMov.push_back(new Move(20, nullptr, VS1, e));
	vecMov.push_back(new Move(20, nullptr, VSC, e));
	AnimationChain* VamoiricStrike = new AnimationChain(vecMov);
	return VamoiricStrike;
}

void AbilityFactory::VS1(Entity* ent)
{
#if _DEBUG
	std::cout << "HA HA HA HO" << endl;
#endif
	GameState* currentState = ent->getApp()->getStateMachine()->getCurrentState();
	Texture* texture = ent->getApp()->getAssetsManager()->getTexture(AssetsManager::Vs1);
	PhysicsTransform* phtr = ent->getComponent<PhysicsTransform>(ecs::Transform);

	uint16 mask;
	int orientation_ = ent->getComponent<Transform>(ecs::Transform)->getOrientation();

	PlayerData* pD = ent->getComponent<PlayerData>(ecs::PlayerData);
	if (pD->getPlayerNumber() == 0) {
		mask = currentState->PLAYER_2 | currentState->P_BAG;
	}
	else {
		mask = currentState->PLAYER_1 | currentState->P_BAG;
	}

	int width = 200;
	int projX = phtr->getPosition().getX() + (phtr->getWidth() * 3 / 4) + (width / 2) - 85;
	if (orientation_ == -1) projX = phtr->getPosition().getX() + (phtr->getWidth() * 1 / 4) - (width / 2) + 85;

	Vector2D pos = Vector2D(projX, phtr->getPosition().getY() + 240);

	VampiricDestroyAtTime* dT = new VampiricDestroyAtTime(5, 20, 30, { (double)orientation_ * 5, -1.3 }, false, ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), ent, 0.4);

	AbilityFactory::instanceEntitywHitbox(ent, width, 145, pos, { 0, 0 }, mask, ent->getState(), ent->getApp(), texture, orientation_, dT);
}

void AbilityFactory::VSC(Entity* ent)
{
	goOnCoolodwn(ent, 60 * 8);
}



Entity* AbilityFactory::instanceEntitywHitbox(Entity* ent, double width, double height, Vector2D pos, Vector2D speed, uint16 mask, GameState* currentState, App* app, Texture* texture, int orientation, HitboxData* uData, bool gravity) {
	double windowWidth = app->getWindowManager()->getCurResolution().w;
	if (pos.getX() >= windowWidth)  
		pos.setX(windowWidth);
	else if (pos.getX() <= 0)  
		pos.setX(0);
	Entity* e = ent->getApp()->getStateMachine()->getCurrentState()->getEntityManager().addEntity();
	e->addComponent<PhysicsTransform>(pos, speed, width, height, 0, currentState->getb2World(),
		currentState->BULLET, mask, 1)->setOrientation(orientation);

	
	e->addComponent<RenderImage>(texture);

	//int damage, int time, int hitstun, Vector2D knockback, bool guardbreaker, int id, Entity* e, bool destroyInContact = false
	if (gravity)
		e->addComponent<BulletGravity>(ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), uData, speed);
	else
		e->addComponent<Bullet>(ent->getComponent<PlayerData>(ecs::PlayerData)->getPlayerNumber(), uData,speed);
	uData->entity_ = e;//change to the new entity 
	return e;
}


void AbilityFactory::goOnCoolodwn(Entity* e, int cool)
{
	PlayerAttacks* pl = e->getComponent<PlayerAttacks>(ecs::PlayerAttacks);
	pl->goOnCooldown(pl->getAbilityIndex(), cool);	
}

std::map<GameManager::AbilityID, std::function<AnimationChain * (Entity*)>> AbilityFactory::abilities_map = {
	{GameManager::AbilityID::SeismicShock, AbilityFactory::GiveSeismicShock},
	{GameManager::AbilityID::MegatonGrip, AbilityFactory::GiveMegatonGrip},
	{GameManager::AbilityID::ExplosiveWillpower, AbilityFactory::GiveExplosiveWillpower},
	{GameManager::AbilityID::AcidSplit, AbilityFactory::GiveAcidSplit},
	{GameManager::AbilityID::ShrugOff, AbilityFactory::GiveShrugOff},
	{GameManager::AbilityID::MorePower, AbilityFactory::GiveMorePower},
	{GameManager::AbilityID::Hookshot, AbilityFactory::GiveHookshot},
	{GameManager::AbilityID::Dash, AbilityFactory::GiveDash},
	{GameManager::AbilityID::VampiricStrike, AbilityFactory::GiveVampiricStrike},

};