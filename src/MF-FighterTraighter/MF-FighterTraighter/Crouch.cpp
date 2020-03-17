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
	if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_S) && crouched) {
		crouch();
	}
	
	if(app_->getInputManager()->isKeyUp(SDL_SCANCODE_S))
	{
		if (!crouched)
		{
			uncrouch();

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
