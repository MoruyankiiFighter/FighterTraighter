#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"

//coonstructor 
Crouch::Crouch(SDL_Scancode crouchk) : Component(ecs::Crouch), physics_transform_(nullptr), crouchKey_(crouchk)
{

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
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	Transform* tr = entity_->getComponent<Transform>(ecs::Transform);

	if ((app_->getInputManager()->isKeyDown(crouchKey_)|| app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.1) && 
		currState->canCrouch()) {
		cout << "crouch"<< endl;
		if (currState->isMoving()) tr->setSpeed(0, tr->getSpeed().getY());
		crouch();
	}

	if (app_->getInputManager()->isKeyUp(crouchKey_) && app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < 0.09)
	{
		if (currState->isCrouch())
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
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goCrouch();
	
	physics_transform_->setHeight(physics_transform_->getHeight() / 2);
	double height = physics_transform_->getHeight();
	double width = physics_transform_->getWidth();

	physics_transform_->setPosition(physics_transform_->getPosition().getX() + width / 2, physics_transform_->getPosition().getY() + height);

	//animaciones de agachar
}

//uncrouch
void Crouch::uncrouch()
{
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goIdle();

	double width = physics_transform_->getWidth();

	physics_transform_->setPosition(physics_transform_->getPosition().getX() + width / 2, physics_transform_->getPosition().getY());
	physics_transform_->setHeight(physics_transform_->getHeight() * 2);

	//animaciones por defecto
}
