#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include "HID.h"

class PlayerController :
	public Component
{
public:
	PlayerController(HID* hid, float jImpulse, double speed);
	virtual ~PlayerController();

	//methods overrided from Component
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
	void crouch();
	void uncrouch();
	void jump();
	float getJumpImpulse() { return jumpImpulse; }
	double getMovSpeed() { return movSpeed; }
	void wallLeft(bool collision) {
		wallLeft_ = collision;
	}
	void wallRight(bool collision) {
		wallRight_ = collision;
	}
	
private:
	HID* inputSt_ = nullptr;
	PhysicsTransform* transform_ = nullptr;
	bool wallLeft_=false, wallRight_ = false;
	float jumpImpulse = 0;
	double movSpeed = 1;
	double verticalDeadzone = 0.3;
};