#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"
#include "PhysicsTransform.h"

//constructor
PlayerController::PlayerController(HID* hid, float jImpulse, double speed) : Component(ecs::PlayerController), transform_(nullptr), inputSt_(hid), jumpImpulse(jImpulse), movSpeed(speed)
{
}

//destructor
PlayerController::~PlayerController()
{
}

//init
void PlayerController::init()
{
	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

//update
void PlayerController::update()
{
}

//handle input
void PlayerController::handleInput()
{
	Vector2D speed(transform_->getSpeed());
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	InputManager* input = app_->getInputManager();
	if (inputSt_->AxisInput(HID::LTrigger) > 0 && currState->canGuard())
	{
		if (currState->isCrouch()) 
			uncrouch();
		else if (currState->isMoving())	
			transform_->setSpeed(0, speed.getY());
		if (!currState->isGuarding()) 
			currState->goGuardingTransition(6);
	}
	else if ((inputSt_->ButtonDown(HID::LeftPad_Up) || inputSt_->AxisInput(HID::LJoyY) < -verticalDeadzone) && currState->canJump())
	{
		jump();
#ifdef _DEBUG
		std::cout << "salto" << std::endl;
#endif
	}
	else if ((inputSt_->ButtonDown(HID::LeftPad_Down) || inputSt_->AxisInput(HID::LJoyY) > verticalDeadzone) && currState->canCrouch())
	{

		if (currState->isMoving())
			transform_->setSpeed(0, speed.getY());
		crouch();
	}
	else if (currState->isAbletoMove() && (inputSt_->ButtonDown(HID::LeftPad_Left) || inputSt_->AxisInput(HID::LJoyX) < 0))
	{
		speed = Vector2D(-movSpeed, speed.getY());
		transform_->setSpeed(speed);
		if (currState->isGrounded()) 
			currState->goMoving();
		else 
			currState->goJumping();
	}
	else if (currState->isAbletoMove() && (inputSt_->ButtonDown(HID::LeftPad_Right) || inputSt_->AxisInput(HID::LJoyX) > 0))
	{
		speed = Vector2D(movSpeed, speed.getY());
		transform_->setSpeed(speed);
		if (currState->isGrounded()) 
			currState->goMoving();
		else
			currState->goJumping();
	}

	// If these keys aren't active
	if (!(inputSt_->ButtonDown(HID::LeftPad_Left) || inputSt_->AxisInput(HID::LJoyX) < 0) &&
		!(inputSt_->ButtonDown(HID::LeftPad_Right) || inputSt_->AxisInput(HID::LJoyX) > 0) &&
		!(inputSt_->ButtonDown(HID::LeftPad_Up) || inputSt_->AxisInput(HID::LJoyY) < 0)) {
		if (currState->isMoving())
		{
			transform_->setSpeed(0, speed.getY());
			if (currState->isGrounded()) currState->goIdle();
			else { currState->goJumping(); };
		}
	}
	if (!inputSt_->AxisInput(HID::LTrigger) > 0) {
		if (currState->isGuarding())
			currState->goGuardingLeaving(14);
	}
	if (!(inputSt_->ButtonDown(HID::LeftPad_Down) || inputSt_->AxisInput(HID::LJoyY) > 0)) {
		if (currState->isCrouch())
			uncrouch();
	}
}

//crouch
void PlayerController::crouch()
{
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goCrouch();

	float height = transform_->getHeight();
	transform_->setColliderHeight(height * 0.6, Vector2D(0, height / 5));
}

//uncrouch
void PlayerController::uncrouch()
{
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goIdle();	
	transform_->setColliderHeight(transform_->getHeight(), Vector2D(0, 0));
}

//Jump depending on the player input
void PlayerController::jump(){
	//uncrouch if the player is crouching and go to the jump transition state
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	if (currState->isCrouch())
		uncrouch();
	currState->goJumpingTrans(7);
	//control the x speed of the jump with the input 
	if (inputSt_->ButtonDown(HID::LeftPad_Left) || inputSt_->AxisInput(HID::LJoyX) < 0)
		transform_->setSpeed(Vector2D(-movSpeed, transform_->getSpeed().getY()));

	else if ((inputSt_->ButtonDown(HID::LeftPad_Right) || inputSt_->AxisInput(HID::LJoyX) > 0))
		transform_->setSpeed(Vector2D(movSpeed, transform_->getSpeed().getY()));
	transform_->getBody()->SetLinearDamping(0);//0 friction in the air
	transform_->getBody()->ApplyLinearImpulse(b2Vec2(0, jumpImpulse), transform_->getBody()->GetWorldCenter(), true);
}