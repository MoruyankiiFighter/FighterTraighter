#pragma once
#include "AnimationChain.h"

class AbilityFactory {
public:
	static AnimationChain* GiveMegatonGrip(Entity* e);

	static void MG1(Entity* ent);
	static void MG2(Entity* ent);
private: 
	AbilityFactory() {};
	~AbilityFactory() {};
};