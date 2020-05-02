#pragma once
#include "AnimationChain.h"
#include "GameManager.h"
#include <functional>
#include <map>
class AbilityFactory {
public:
	static AnimationChain* GiveAbility(GameManager::AbilityID id, Entity* e);

	//Megaton Grip
	static AnimationChain* GiveMegatonGrip(Entity* e);

	static void MG1(Entity* ent);
	static void MG2(Entity* ent);
	static void MGC(Entity* ent);

	//Seismic Shock
	static AnimationChain* GiveSeismicShock(Entity* e);

	static void SeismicS1(Entity* e);	//kick
	static void SeismicS2(Entity* ent);	//rock going up
	static void SeismicS3(Entity* ent);	//punches going down
	static void SeismicSC(Entity* ent);	//go cd

	//Explosive Willpower
	static AnimationChain* GiveExplosiveWillpower(Entity* e);

	static void EWC(Entity* ent);
	static void EW1(Entity* ent);
	static void EW2(Entity* ent);
	static void EW3(Entity* ent);

	//Whatever the rest of this is
	//static AnimationChain* Bullets(Entity* e);
	//static void Bullet1(Entity* ent);

	//GameState* state, uint16 playerNumber,Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact = false
	static void createProyectile(Entity* ent, double width, double height, Vector2D pos, Vector2D speed, int damage,int hitstun,
		Vector2D knockBack, int time, uint16 mask, GameState* currentState, App* app, Texture* texture,bool destroyInContact = false);

private: 
	AbilityFactory() {};
	~AbilityFactory() {};
	static void goOnCoolodwn(Entity* e, int cool);
	static std::map<GameManager::AbilityID, std::function<AnimationChain* (Entity*)>> abilities_map;
};