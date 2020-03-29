#include "Jump.h"
#include "Entity.h"
#include "Vector2D.h"
#include "PlayerState.h"
#include "Crouch.h"


Jump::Jump(float jImpulse, SDL_Scancode jumpkey) : Component(ecs::Jump), jumpImpulse(jImpulse), physics_transform_(nullptr), jumpKey_(jumpkey) {}


void Jump::init()
{
	physics_transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void Jump::handleInput()
{
	PlayerState* currState = entity_->getComponent<PlayerState>(ecs::PlayerState);
	if ((app_->getInputManager()->isKeyDown(jumpKey_)|| app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.9)
		&& currState->canJump()) {
		//pTR_->setSpeed(0, 5);
		//force and where you use the fore
		pTR_->getBody()->ApplyLinearImpulse(b2Vec2(0,jumpImpulse),pTR_->getBody()->GetWorldCenter(),true);
		if (currState->isCrouch()) entity_->getComponent<Crouch>(ecs::Crouch)->uncrouch();
		currState->goJumpingTrans();
		std::cout << "salto" << std::endl;
	}
	
}