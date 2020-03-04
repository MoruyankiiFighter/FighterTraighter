#include "Jump.h"
#include "Entity.h"
#include "Vector2D.h"


Jump::Jump(float jImpulse) : Component(ecs::Jump), jumpImpulse(jImpulse), pTR_(nullptr) {}


void Jump::init()
{
	pTR_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void Jump::handleInput()
{
	if (onGround && app_->getInputManager()->isKeyDown(SDL_SCANCODE_W)) {
		//pTR_->setSpeed(0, 5);
		Vector2D x = pTR_->getPosition();
		std::cout<< x.getY();
		pTR_->ApplyLinearImpulse(0, jumpImpulse);
		std::cout << "salto" << std::endl;
	}
}

void Jump::update()
{
	Vector2D velocity = pTR_->getSpeed();
	onGround = abs(velocity.getY()) <= 2;		//puedes saltar justo cuando empiezas a caer
}