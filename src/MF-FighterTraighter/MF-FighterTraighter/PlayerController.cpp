#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"
#include "PhysicsTransform.h"

//constructor
PlayerController::PlayerController(SDL_Scancode left, SDL_Scancode right, SDL_Scancode block) : Component(ecs::PlayerController),
transform_(nullptr), left_(left), right_(right), block_(block)
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
	transform_->setPosition(transform_->getPosition() + transform_->getSpeed());
}

//handle input
void PlayerController::handleInput()
{
	Vector2D speed;
	speed = transform_->getSpeed();
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	if (currState->isAbletoMove() && (app_->getInputManager()->isKeyDown(left_) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) < 0)) {
		transform_->setSpeed(-10, speed.getY());
		if (currState->isGrounded()) currState->goMoving();
		else { currState->goJumping(); };
	}
	else if (currState->isAbletoMove() && (app_->getInputManager()->isKeyDown(right_) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) > 0.09))
	{
		transform_->setSpeed(10, speed.getY());
		if (currState->isGrounded()) currState->goMoving();
		else { currState->goJumping(); };
	}
	else if (app_->getInputManager()->isKeyDown(block_) && currState->canGuard())
	{
 		if (!currState->isGuarding()) currState->goGuardingTransition(10);
		transform_->setSpeed(0, speed.getY());
	}
	else {
		if (currState->isMoving()) {
			transform_->setSpeed(0, speed.getY());
			if (currState->isGrounded()) currState->goIdle();
			else { currState->goJumping(); };
		}
		else if (currState->isGuarding()) {
			currState->goGuardingLeaving(15);
		}
	}
}
