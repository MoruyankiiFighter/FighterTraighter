#pragma once
#include "Component.h"
#include "Health.h"
#include "PlayerData.h"

class SacoFunction: public Component
{
public:
	SacoFunction(Entity* saco) : Component(ecs::SacoFunction) { entity_ = saco;};
	~SacoFunction() {};
	virtual void update() override;
private:
	PlayerData* player;
};

