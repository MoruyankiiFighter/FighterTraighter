#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include <math.h>

class Jump : public Component
{
public:
	//constructor
	Jump(float jImpulse);
	//destructor
	virtual ~Jump() {};
	
	//methods overrided from component
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
private:
	PhysicsTransform* physics_transform = nullptr;
	float jumpImpulse = 0;
	bool onGround = true;
};

