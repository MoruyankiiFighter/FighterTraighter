#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include "InpuState.h"

class PlayerController :
	public Component
{
public:
	PlayerController(float jImpulse);
	virtual ~PlayerController();

	//methods overrided from Component
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
	void crouch();
	void uncrouch();
	float getJumpImpulse() { return jumpImpulse; }
	void wallLeft(bool collision) {
		wallLeft_ = collision;
	}
	void wallRight(bool collision) {
		wallRight_ = collision;
	}
private:
	InputState* inputSt_ = nullptr;
	PhysicsTransform* transform_ = nullptr;
	Vector2D dir_;
	bool wallLeft_=false, wallRight_ = false;
	float jumpImpulse = 0;
};