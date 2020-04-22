#pragma once
#include "AnimationChain.h"

class AbilityFactory {
public:
	static AnimationChain* GiveMegatonGrip(Entity* e);

	static void MG1(Entity* ent);
	static void MG2(Entity* ent);

	static AnimationChain* Bullets(Entity* e);
	//Bullet(GameState* state, uint16 playerNumber, Vector2D speed, int damage, int hitstun, Vector2D knockBack, int time, bool destroyInContact = false);

	static void Bullet1(Entity* ent);
	//static void MG2(Entity* ent);
private: 
	AbilityFactory() {};
	~AbilityFactory() {};
};