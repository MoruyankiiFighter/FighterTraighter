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
		pTR_->ApplyLinearImpulse(0, jumpImpulse);
	}
}

void Jump::update()
{
	Vector2D velocity = pTR_->getSpeed();
	onGround = velocity.getY() <= 0.001;
}