#pragma once
#include "Component.h"
#include "PhysicsTransform.h"

class Crouch :
	public Component
{
public:
	Crouch(SDL_Scancode crouchk);
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
	void crouch();
	void uncrouch();
	//poder 
	//CanCrouch(){return  !cancrouched;};
	virtual ~Crouch();
private:
	//Transform* tr_;
	PhysicsTransform* tr_ = nullptr;
	SDL_Scancode crouchKey_;
	bool cancrouched=false;
};

