#pragma once
#include "Component.h"
class OnHit : public Component
{
public:
	OnHit() : Component(ecs::OnHit) {}
	~OnHit() {}
	virtual void onHit() {}	//redefine in every entity that use this component
};

