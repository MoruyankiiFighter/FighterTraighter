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
	virtual ~Jump();

	//methods of overrided from component
	
	void init() override;
	void handleInput() override; 
	void update() override;

private:

	PhysicsTransform* physics_transform_ = nullptr;
	float jumpImpulse = 0;
	bool onGround = true;
};

