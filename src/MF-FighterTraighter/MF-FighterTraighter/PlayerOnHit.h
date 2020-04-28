#pragma once
#include "EntityData.h"
class PlayerOnHit : public EntityData
{
public:
	PlayerOnHit(Entity* e) : EntityData(e) {}
	virtual ~PlayerOnHit() {}
	virtual void onHit(b2Fixture* fixture) override;
};

