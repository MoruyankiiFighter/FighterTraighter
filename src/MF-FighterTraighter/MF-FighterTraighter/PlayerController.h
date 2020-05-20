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
	void canJump(bool jump) { canJump_ = jump; }
	double getMovSpeed() { return movSpeed; }
	inline void setDisabled(bool d) { disabled_ = d; }
private:
	HID* inputSt_ = nullptr;
	PhysicsTransform* transform_ = nullptr;
	float jumpImpulse = 0;
	double movSpeed = 1;
	double verticalDeadzone = 0.3;
	bool canJump_ = true;
	bool disabled_ = false;
};