#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
#include "HID.h"
#include "CharacterController.h"
class PlayerState;

class PlayerController :
	public CharacterController
{
public:
	PlayerController(HID* hid, float jImpulse, double speed);
	virtual ~PlayerController();

	void handleInput() override;


	void jump() override;
	float getJumpImpulse() { return jumpImpulse; }
	double getMovSpeed() { return movSpeed; }	
private:
	HID* inputSt_ = nullptr;
	double verticalDeadzone = 0.3;
};