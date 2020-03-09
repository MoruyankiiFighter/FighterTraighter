#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"

Crouch::Crouch() : Component(ecs::PlayerController), tr_(nullptr)
{
	cancrouched = true;
}

void Crouch::init()
{
	tr_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
	initialHeight = tr_->getHeight();
}

void Crouch::handleInput()
{
	if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_S) && cancrouched) {
		crouch();
	}
	
	if(app_->getInputManager()->isKeyUp(SDL_SCANCODE_S))
	{
		if (!cancrouched)
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
	cancrouched = false;
	pos = tr_->getPosition();
	pos.setY(pos.getY() + tr_->getHeight()-10);
	tr_->setHeight(tr_->getHeight()/2.0);

	tr_->setPosition(pos.getX(), pos.getY());
	
}

	
	//animaciones de agachar
void Crouch::uncrouch()
{
	cancrouched = true;
	tr_->setPosition(pos.getX(), pos.getY() - tr_->getHeight()/2.0);

	tr_->setHeight(initialHeight);

	

	
	//animaciones por defecto
}





Crouch::~Crouch()
{
}
