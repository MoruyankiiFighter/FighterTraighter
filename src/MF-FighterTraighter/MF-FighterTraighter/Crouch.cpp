#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"

Crouch::Crouch() : Component(ecs::Crouch), tr_(nullptr)
{
	cancrouched = true;
}

void Crouch::init()
{
	tr_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
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
	tr_->setPosition(tr_->getPosition() + Vector2D(0,  tr_->getHeight()));

	tr_->setHeight(tr_->getHeight() / 2);
	//animaciones de agachar
}void Crouch::uncrouch()
{
	cancrouched = true;
	tr_->setHeight(tr_->getHeight() * 2);

	tr_->setPosition(tr_->getPosition() + Vector2D(0, tr_->getHeight())*(-1));
	//animaciones por defecto
}





Crouch::~Crouch()
{
}
