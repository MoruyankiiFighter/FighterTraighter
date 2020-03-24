#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"

Crouch::Crouch() : Component(ecs::Crouch), physics_transform_(nullptr)
{
	crouched = true;
}

void Crouch::init()
{
	physics_transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void Crouch::handleInput()
{
	if ((app_->getInputManager()->isKeyDown(SDL_SCANCODE_S)|| app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.1) && crouched) {
		cout << "crouch"<< endl;
		crouch();
	}
	
	if(app_->getInputManager()->isKeyUp(SDL_SCANCODE_S) && app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < 0.09)
	{
		if (!crouched)
		{
			uncrouch();
			cout << "uncrouch" << endl;


		}
	}
	
	
}

void Crouch::update()
{
	//tr_->setPosition(tr_->getPosition() + tr_->getSpeed());
}
void Crouch::crouch()
{
	crouched = false;
	physics_transform_->setPosition(physics_transform_->getPosition() + Vector2D(0,  physics_transform_->getHeight()));

	physics_transform_->setHeight(physics_transform_->getHeight() / 2);
	//animaciones de agachar
}void Crouch::uncrouch()
{
	crouched = true;
	physics_transform_->setHeight(physics_transform_->getHeight() * 2);

	physics_transform_->setPosition(physics_transform_->getPosition() + Vector2D(0, physics_transform_->getHeight())*(-1));
	//animaciones por defecto
}





Crouch::~Crouch()
{
}
