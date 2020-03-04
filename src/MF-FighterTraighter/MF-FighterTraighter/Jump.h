#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include <math.h>

class Jump : public Component
{
public:
	Jump(float jImpulse);
	virtual ~Jump() {};
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
private:
	PhysicsTransform* pTR_ = nullptr;
	float jumpImpulse = 0;
	bool onGround = true;
};

