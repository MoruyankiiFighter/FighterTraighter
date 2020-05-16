#include "AIController.h"
#include "AILogic.h"

AIController::~AIController()
{
}

void AIController::init()
{
	CharacterController::init();
	logic = entity_->getComponent<AILogic>(ecs::AILogic);
}

void AIController::handleInput()
{
	Vector2D speed(transform_->getSpeed());
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	InputManager* input = app_->getInputManager();
	/*
	if (inputSt_->AxisInput(HID::LTrigger) > 0)
	{
		TryGuarding(currState, speed);
	}
	else if ((inputSt_->ButtonDown(HID::LeftPad_Up) || inputSt_->AxisInput(HID::LJoyY) < -verticalDeadzone))
	{
		TryJumping(currState);
	}
	else if ((inputSt_->ButtonDown(HID::LeftPad_Down) || inputSt_->AxisInput(HID::LJoyY) > verticalDeadzone))
	{
		TryCrouching(currState, speed);
	}*/
	if (logic->getMovingState() == AILogic::movingLeft)
	{
		TryMovingLeft(currState, speed);
	}
	else if (logic->getMovingState() == AILogic::movingRight)
	{
		TryMovingRight(currState, speed);
	}

	// If these keys aren't active
	if (logic->getMovingState() == AILogic::idle) {
		TryStopMoving(currState, speed);
	}
	/*if (!inputSt_->AxisInput(HID::LTrigger) > 0) {
		TryStopGuarding(currState);
	}
	if (!(inputSt_->ButtonDown(HID::LeftPad_Down) || inputSt_->AxisInput(HID::LJoyY) > 0)) {
		TryStopCrouch(currState);
	}*/
}
