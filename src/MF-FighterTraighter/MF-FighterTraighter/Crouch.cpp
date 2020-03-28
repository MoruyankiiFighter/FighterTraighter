#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"

//coonstructor 
Crouch::Crouch(SDL_Scancode crouchk) : Component(ecs::Crouch), physics_transform_(nullptr), crouchKey_(crouchk)
{
	cancrouched = true;
}

//destructor
Crouch::~Crouch()
{
}
//init where set physics_transform_ to the PhysicsTransform to the entity
void Crouch::init()
{
	physics_transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

//handle input
void Crouch::handleInput()
{
	if ((app_->getInputManager()->isKeyDown(crouchKey_) || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.1) && cancrouched) {
		cout << "crouch" << endl;
		crouch();
	}

	if (app_->getInputManager()->isKeyUp(crouchKey_) && app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < 0.09)
	{
		if (!cancrouched)
		{
			uncrouch();
			cout << "uncrouch" << endl;
		}
	}
}

//update
void Crouch::update()
{
	//tr_->setPosition(tr_->getPosition() + tr_->getSpeed());
}

//crouch
void Crouch::crouch()
{
	cancrouched = false;

	physics_transform_->setHeight(physics_transform_->getHeight() / 2);
	double height = physics_transform_->getHeight();
	double width = physics_transform_->getWidth();

	physics_transform_->setPosition(physics_transform_->getPosition().getX() + width / 2, physics_transform_->getPosition().getY() + height);

	//animaciones de agachar
}

//uncrouch
void Crouch::uncrouch()
{
	cancrouched = true;
	double width = physics_transform_->getWidth();

	physics_transform_->setPosition(physics_transform_->getPosition().getX() + width / 2, physics_transform_->getPosition().getY());
	physics_transform_->setHeight(physics_transform_->getHeight() * 2);

	//animaciones por defecto
}
