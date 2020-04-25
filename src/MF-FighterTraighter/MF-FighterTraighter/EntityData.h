#pragma once
#include "UserData.h"
#include "Entity.h"

class EntityData: virtual public UserData
{
public:
	EntityData(Entity* e) : entity_(e) {}
	//virtual void onHit() {}
	Entity* entity_ = nullptr;
};