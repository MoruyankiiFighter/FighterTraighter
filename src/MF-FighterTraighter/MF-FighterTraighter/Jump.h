#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include <math.h>

class Jump : public Component
{
public:
	Jump(float jImpulse, SDL_Scancode jumpkey);
	virtual ~Jump() {};
	void init() override;
	void handleInput() override; // separate into two?
private:
	PhysicsTransform* pTR_ = nullptr;
	SDL_Scancode jumpKey_;
	float jumpImpulse = 0;
};

