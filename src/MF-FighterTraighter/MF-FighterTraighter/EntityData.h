#pragma once
#include "UserData.h"
#include "Entity.h"

class EntityData:  public UserData
{
public:
	EntityData(Entity* e) : entity_(e) {}
	virtual void onHit(b2Fixture* other) {	//esto hay que cambiarlo de sitio (DestroyOnHit) para que no sea el comportamiento normal
		//entity_->getApp()->getStateMachine()->getCurrentState()->getEntityManager().removeEntity(entity_);
	}
	virtual ~EntityData() {}
	Entity* entity_ = nullptr;
};