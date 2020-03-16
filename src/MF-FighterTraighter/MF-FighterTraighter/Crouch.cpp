#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"

Crouch::Crouch() : Component(ecs::PlayerController), tr_(nullptr)
{
	canCrouch = true;
	crouchPercent = 4;
}

void Crouch::init()
{
	tr_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	initialHeight = tr_->getHeight();
}

void Crouch::handleInput()
{
	if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_S) && canCrouch) {
		crouch();
	}
	
	if(app_->getInputManager()->isKeyUp(SDL_SCANCODE_S))
	{
		if (!canCrouch)
		{
			uncrouch();

		}
	}
	
	
}

void Crouch::update()
{
	pos.setX(tr_->getX());
	pos.setY(tr_->getY());
}

void Crouch::crouch()
{
	canCrouch = false;
	
	tr_->setHeight(tr_->getHeight() / crouchPercent);
	pos.setY(pos.getY() + (crouchPercent - 1) * tr_->getHeight());

	tr_->setPosition(pos.getX() , pos.getY());

	//NECESARIO COOLDOWN
}


//animaciones de agachar
void Crouch::uncrouch()
{
	canCrouch = true;

	pos.setY(pos.getY() - crouchPercent  * tr_->getHeight());

	tr_->setPosition(pos.getX(), pos.getY());
	tr_->setHeight(initialHeight);


	




	//animaciones por defecto
}





Crouch::~Crouch()
{
}
