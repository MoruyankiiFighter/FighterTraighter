#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"

PlayerController::PlayerController() : Component(ecs::PlayerController), tr_(nullptr)
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
	if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_LEFT)) {
		tr_->setSpeed(-10, speed.getY());
	}
	else if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		tr_->setSpeed(10, speed.getY());
	}
	
	else tr_->setSpeed(0, speed.getY());
}

void PlayerController::update()
{
	tr_->setPosition(tr_->getPosition() + tr_->getSpeed());
}

PlayerController::~PlayerController()
{
	
}
