#pragma once
#include "UserData.h"
#include "Entity.h"

class EntityData:  public UserData
{
public:
	EntityData(Entity* e) : entity_(e) {}
	//virtual void onHit() {
		//entity_->getApp()->getStateMachine()->getCurrentState()->getEntityManager().removeEntity(entity_);
	//}
	virtual ~EntityData() {
		if(entity_!=nullptr)
			entity_->getApp()->getStateMachine()->getCurrentState()->getEntityManager().removeEntity(entity_);

	}
	Entity* entity_ = nullptr;
};