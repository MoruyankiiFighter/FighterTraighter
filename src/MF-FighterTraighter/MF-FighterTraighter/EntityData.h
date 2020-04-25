#pragma once
#include "UserData.h"
#include "Entity.h"

struct EntityData: UserData
{
public:
	EntityData(Entity* e) : entity_(e) {}
	//virtual void onHit() {}
	Entity* entity_ = nullptr;
};