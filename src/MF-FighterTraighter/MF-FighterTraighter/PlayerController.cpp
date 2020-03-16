#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"

PlayerController::PlayerController() : Component(ecs::PlayerController), transform_(nullptr)
{
}

void PlayerController::init()
{
	transform_ = entity_->getComponent<Transform>(ecs::Transform);
}

void PlayerController::handleInput()
{
	Vector2D speed;
	speed = transform_->getSpeed();
	if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_LEFT) || app_->getInputManager()->getJoyX() == -1) {
		transform_->setSpeed(-10, speed.getY());
	}
	else if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_RIGHT) || app_->getInputManager()->getJoyX() == 1) {
				transform_->setSpeed(10, speed.getY());
	}
	else transform_->setSpeed(0, speed.getY());
}

void PlayerController::update()
{
	transform_->setPosition(transform_->getPosition() + transform_->getSpeed());
}

PlayerController::~PlayerController()
{
	
}
