#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"

Crouch::Crouch(SDL_Scancode crouchk) : Component(ecs::Crouch), tr_(nullptr), crouchKey_(crouchk)
{

}

void Crouch::init()
{
	tr_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

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
	
	if(app_->getInputManager()->isKeyUp(crouchKey_) && app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < 0.09)
	{
		if (currState->isCrouch())
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
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goCrouch();
	
	tr_->setHeight(tr_->getHeight() / 2);
	double height = tr_->getHeight();
	double width = tr_->getWidth();

	tr_->setPosition(tr_->getPosition().getX()+width/2, tr_->getPosition().getY() + height);

	//animaciones de agachar
}void Crouch::uncrouch()
{
	entity_->getComponent<PlayerState>(ecs::PlayerState)->goIdle();

	double width = tr_->getWidth();

	tr_->setPosition(tr_->getPosition().getX() + width / 2, tr_->getPosition().getY() );
	tr_->setHeight(tr_->getHeight() * 2);

	//animaciones por defecto
}





Crouch::~Crouch()
{
}
