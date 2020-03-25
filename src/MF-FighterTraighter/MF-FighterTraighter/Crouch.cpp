#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"

Crouch::Crouch(SDL_Scancode crouchk) : Component(ecs::Crouch), tr_(nullptr), crouchKey_(crouchk)
{
	cancrouched = true;
}

void Crouch::init()
{
	tr_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void Crouch::handleInput()
{
	if ((app_->getInputManager()->isKeyDown(crouchKey_)|| app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.1) && cancrouched) {
		cout << "crouch"<< endl;
		crouch();
	}
	
	if(app_->getInputManager()->isKeyUp(crouchKey_) && app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < 0.09)
	{
		if (!cancrouched)
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
	cancrouched = false;
	
	tr_->setHeight(tr_->getHeight() / 2);
	double height = tr_->getHeight();
	double width = tr_->getWidth();

	tr_->setPosition(tr_->getPosition().getX()+width/2, tr_->getPosition().getY() + height);

	//animaciones de agachar
}void Crouch::uncrouch()
{
	cancrouched = true;
	double width = tr_->getWidth();

	tr_->setPosition(tr_->getPosition().getX() + width / 2, tr_->getPosition().getY() );
	tr_->setHeight(tr_->getHeight() * 2);

	//animaciones por defecto
}





Crouch::~Crouch()
{
}
