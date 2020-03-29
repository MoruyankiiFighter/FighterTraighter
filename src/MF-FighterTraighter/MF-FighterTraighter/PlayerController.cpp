#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"

//constructor
PlayerController::PlayerController(SDL_Scancode left, SDL_Scancode right) : Component(ecs::PlayerController),
transform_(nullptr), left_(left), right_(right)
{
}

//destructor
PlayerController::~PlayerController()
{
}

//init
void PlayerController::init()
{
	Vector2D speed;
	speed = tr_->getSpeed();
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	if (currState->isAbletoMove()) {
		if (app_->getInputManager()->isKeyDown(left_) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) < 0) {
			tr_->setSpeed(-10, speed.getY());
			if (currState->isGrounded()) currState->goMoving();
			else { currState->goJumping(); };
		}
		else if (app_->getInputManager()->isKeyDown(right_) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) > 0.09)
		{
			tr_->setSpeed(10, speed.getY());
			if (currState->isGrounded()) currState->goMoving();
			else { currState->goJumping(); };
		}
		else {
			tr_->setSpeed(0, speed.getY());
			if (currState->isGrounded()) currState->goIdle();
			else { currState->goJumping(); };
		}
	}
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
	if (app_->getInputManager()->isKeyDown(left_) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) < 0) {
		transform_->setSpeed(-10, speed.getY());
	}
	else if (app_->getInputManager()->isKeyDown(right_) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) > 0.09)
	{
		transform_->setSpeed(10, speed.getY());
	}
	else transform_->setSpeed(0, speed.getY());
}
