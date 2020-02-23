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
	if (InputManager::instance()->isKeyDown(SDL_SCANCODE_A)) {
		tr_->setSpeed(-1, 0);
	}
	else if (InputManager::instance()->isKeyDown(SDL_SCANCODE_D)) {
		tr_->setSpeed(11, 0);
	}
	else tr_->setSpeed(0, 0);
}

void PlayerController::update()
{
	tr_->setPosition(tr_->getPosition() + tr_->getSpeed());
}

PlayerController::~PlayerController()
{
}
