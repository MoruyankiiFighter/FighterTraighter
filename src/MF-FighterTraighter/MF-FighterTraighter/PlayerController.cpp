#include "PlayerController.h"
#include "Entity.h"
#include "Vector2D.h"

PlayerController::PlayerController() : Component(ecs::PlayerController), physics_transform(nullptr)
{
}

void PlayerController::init()
{
	physics_transform = entity_->getComponent<Transform>(ecs::Transform);
}

void PlayerController::handleInput()
{
	Vector2D speed;
	speed = physics_transform->getSpeed();
	if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_LEFT)|| app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX)<0) {
		physics_transform->setSpeed(-10, speed.getY());
	}
	else if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_RIGHT) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTX) >0.09 )
	{
				physics_transform->setSpeed(10, speed.getY());
	}
	else physics_transform->setSpeed(0, speed.getY());
}

void PlayerController::update()
{
	physics_transform->setPosition(physics_transform->getPosition() + physics_transform->getSpeed());
}

PlayerController::~PlayerController()
{
	
}
