#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"
#include "PhysicsTransform.h"

//constructor
PlayerController::PlayerController(float jImpulse, double speed) : Component(ecs::PlayerController), transform_(nullptr), inputSt_(nullptr), jumpImpulse(jImpulse), movSpeed(speed)
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
	inputSt_ = entity_->getComponent<InputState>(ecs::InputState);
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
	if (inputSt_->getInput(10) && currState->canGuard())
	{
		if (currState->isCrouch()) uncrouch();
		else if (currState->isMoving())transform_->setSpeed(0, speed.getY());
		if (!currState->isGuarding()) currState->goGuardingTransition(6);
	}
	else if (inputSt_->getInput(2) && currState->canJump()) 
	{
		//force and where you use the fore
		transform_->getBody()->SetLinearDamping(0);//0 friction in the air
		transform_->getBody()->ApplyLinearImpulse(b2Vec2(0, jumpImpulse), transform_->getBody()->GetWorldCenter(), true);
		if (currState->isCrouch()) uncrouch();
		currState->goJumpingTrans(7);
		std::cout << "salto" << std::endl;
	}
	else if (inputSt_->getInput(3) && currState->canCrouch())
	{
		cout << "crouch" << endl;
		if (currState->isMoving()) transform_->setSpeed(0, speed.getY());
		crouch();
	}
	else if (currState->isAbletoMove() && inputSt_->getInput(0))
	{
		if(!wallLeft_) speed = Vector2D(-movSpeed, speed.getY());
		else {
			speed = Vector2D(0, speed.getY());
		}
		transform_->setSpeed(speed);
		if (currState->isGrounded()) currState->goMoving();
		else { currState->goJumping(); };
	}
	else if (currState->isAbletoMove() && inputSt_->getInput(1))
	{
		if (!wallRight_) speed = Vector2D(movSpeed, speed.getY());
		else {
			speed = Vector2D(0, speed.getY());
		}		
		transform_->setSpeed(speed);
		if (currState->isGrounded()) currState->goMoving();
		else { currState->goJumping(); };
	}

	//Si e�sa tecla no est� activa
	if(!inputSt_->getInput(0) && !inputSt_->getInput(1) && !inputSt_->getInput(2)){
		if (currState->isMoving() || currState->isJumping()) 
		{
			transform_->setSpeed(0, speed.getY());
			if (currState->isGrounded()) currState->goIdle();
			else { currState->goJumping(); };
		}	
	}
	if (!inputSt_->getInput(10)) {
		if (currState->isGuarding())
		{
			currState->goGuardingLeaving(14);
		}
	}
	if (!inputSt_->getInput(3)) {
		if (currState->isCrouch())
		{
			uncrouch();
		}
	}
}

//crouch
void PlayerController::crouch()
{
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goCrouch();

	//transform_->setHeight(transform_->getHeight() / 2);
	float height = transform_->getHeight();
	transform_->setColliderHeight(height * 0.6, Vector2D(0, height / 5));
	
	//transform_->setColliderWidth(transform_->getWidth() / 2);
	//double height = transform_->getHeight();
	//double width = transform_->getWidth();

	//transform_->setPosition(transform_->getPosition().getX() + width / 2, transform_->getPosition().getY() + height);

	//animaciones de agachar
}

//uncrouch
void PlayerController::uncrouch()
{
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goIdle();

	//double width = transform_->getWidth();

	//transform_->setPosition(transform_->getPosition().getX() + width / 2, transform_->getPosition().getY());
	//transform_->setHeight(transform_->getHeight());
	transform_->setColliderHeight(transform_->getHeight(), Vector2D(0, 0));
	//transform_->setColliderWidth(transform_->getWidth() / 2);

	//animaciones por defecto
}
