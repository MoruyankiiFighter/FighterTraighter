#pragma once
#include "Component.h"
#include "Transform.h"

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
	bool CanCrouch();
	
	virtual ~Crouch();
private:
	Transform* tr_;
	bool can;
	Vector2D dir_;
};

