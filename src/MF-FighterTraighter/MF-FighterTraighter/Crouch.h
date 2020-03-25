#pragma once
#include "Component.h"
#include "PhysicsTransform.h"

class Crouch :
	public Component
{
public:
	//constructor
	Crouch();
	//destructor
	virtual ~Crouch();
	
	//methods overrided from component
	void init() override;
	void handleInput() override; // separate into two?

	//methods for crouching and uncrouching
	void crouch();
	void uncrouch();
private:

	PhysicsTransform* physics_transform_ = nullptr;
	bool crouched=false;
};

