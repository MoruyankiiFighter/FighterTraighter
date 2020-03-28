#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include <math.h>

class Jump : public Component
{
public:
	//constructor
	Jump(float jImpulse, SDL_Scancode jumpkey);
	//destructor
	virtual ~Jump() {};

	//methods overrided from Component
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
private:
	PhysicsTransform* physics_transform_ = nullptr;
	SDL_Scancode jumpKey_;
	float jumpImpulse = 0;
	bool onGround = true;
};
