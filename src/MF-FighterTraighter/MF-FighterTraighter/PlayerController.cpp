#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"

PlayerController::PlayerController(SDL_Scancode left, SDL_Scancode right) : Component(ecs::PlayerController), 
	tr_(nullptr), left_(left), right_(right)
{
}

void PlayerController::init()
{
	tr_ = entity_->getComponent<Transform>(ecs::Transform);
}

void PlayerController::handleInput()
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

void PlayerController::update()
{
	tr_->setPosition(tr_->getPosition() + tr_->getSpeed());
}

PlayerController::~PlayerController()
{
	
}
