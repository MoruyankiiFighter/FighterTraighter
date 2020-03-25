#include "Jump.h"
#include "Entity.h"
#include "Vector2D.h"


Jump::Jump(float jImpulse, SDL_Scancode jumpkey) : Component(ecs::Jump), jumpImpulse(jImpulse), pTR_(nullptr), jumpKey_(jumpkey) {}


void Jump::init()
{
	pTR_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void Jump::handleInput()
{
	if (onGround &&( app_->getInputManager()->isKeyDown(jumpKey_)|| app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.9 )) {
		//pTR_->setSpeed(0, 5);
		//force and where you use the fore
		pTR_->getBody()->ApplyLinearImpulse(b2Vec2(0,jumpImpulse),pTR_->getBody()->GetWorldCenter(),true);
		std::cout << "salto" << std::endl;
	}
	
}

void Jump::update()
{
	Vector2D velocity = pTR_->getSpeed();
	onGround = abs(velocity.getY()) <= 2;		//puedes saltar justo cuando empiezas a caer
}