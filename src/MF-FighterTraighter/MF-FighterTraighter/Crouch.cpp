#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"

Crouch::Crouch() : Component(ecs::Crouch), physics_transform_(nullptr)
{
	crouched = true;
}

Crouch::~Crouch()
{
}

void Crouch::init()
{
	physics_transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void Crouch::handleInput()
{
	if ((app_->getInputManager()->isKeyDown(SDL_SCANCODE_DOWN) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.1) && crouched) {
		cout << "crouch" << endl;
		crouch();
	}

	if (app_->getInputManager()->isKeyUp(SDL_SCANCODE_DOWN) && app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < 0.09)
	{
		if (!crouched)
		{
			uncrouch();
			cout << "uncrouch" << endl;


		}
	}
}

void Crouch::crouch()
{
	crouched = false;

	physics_transform_->setHeight(physics_transform_->getHeight() / 2);
	double height = physics_transform_->getHeight();
	double width = physics_transform_->getWidth();

	physics_transform_->setPosition(physics_transform_->getPosition().getX() + width / 2, physics_transform_->getPosition().getY() + height);

	//animaciones de agachar
}void Crouch::uncrouch()
{
	crouched = true;
	double width = physics_transform_->getWidth();

	physics_transform_->setPosition(physics_transform_->getPosition().getX() + width / 2, physics_transform_->getPosition().getY());
	physics_transform_->setHeight(physics_transform_->getHeight() * 2);

	//animaciones por defecto
}
