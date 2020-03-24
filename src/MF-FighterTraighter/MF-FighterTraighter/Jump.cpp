#include "Jump.h"
#include "Entity.h"
#include "Vector2D.h"


Jump::Jump(float jImpulse) : Component(ecs::Jump), jumpImpulse(jImpulse), physics_transform(nullptr) {}


void Jump::init()
{
	physics_transform = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void Jump::handleInput()
{
	if (onGround &&( app_->getInputManager()->isKeyDown(SDL_SCANCODE_W)|| app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.9 )) {
		//pTR_->setSpeed(0, 5);
		//force and where you use the fore
		physics_transform->getBody()->ApplyLinearImpulse(b2Vec2(0,jumpImpulse),physics_transform->getBody()->GetWorldCenter(),true);
		std::cout << "salto" << std::endl;
	}
	
}

void Jump::update()
{
	Vector2D velocity = physics_transform->getSpeed();
	onGround = abs(velocity.getY()) <= 2;		//puedes saltar justo cuando empiezas a caer
}