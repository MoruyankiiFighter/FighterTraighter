#pragma once
#include "Component.h"
#include "PhysicsTransform.h"

class Crouch :
	public Component
{
public:
	Crouch();
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
	void crouch();
	void uncrouch();
	//poder 
	//CanCrouch(){return  !crouched;};
	virtual ~Crouch();
private:
	//Transform* tr_;
	PhysicsTransform* tr_ = nullptr;

	bool crouched=false;
	Vector2D dir_;
};

