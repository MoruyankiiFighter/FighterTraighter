#pragma once
#include "AnimationChain.h"

class AbilityFactory {
public:
	static AnimationChain* GiveMegatonGrip(Entity* e);

	static void MG1(Entity* ent);
	static void MG2(Entity* ent);

	static AnimationChain* Bullets(Entity* e);
	static void Bullet1(Entity* ent);

	static AnimationChain* SeismicShock(Entity* e);
	static void SeismicS1(Entity* e);
	static void SeismicS2(Entity* ent);
	static void createProyectile(Entity* ent, Vector2D pos, Vector2D speed, uint16 mask, GameState* currentState, App* app);
private: 
	AbilityFactory() {};
	~AbilityFactory() {};
};