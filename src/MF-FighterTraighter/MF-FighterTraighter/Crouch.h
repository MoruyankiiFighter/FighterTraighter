#pragma once
#include "Component.h"
#include "PhysicsTransform.h"

class Crouch :
	public Component
{
public:
	Crouch(SDL_Scancode crouchk);
	virtual ~Crouch();

	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
	void crouch();
	void uncrouch();
	//poder 
	//CanCrouch(){return  !cancrouched;};
private:
	//Transform* tr_;
	PhysicsTransform* physics_transform_ = nullptr;
	SDL_Scancode crouchKey_;
};

