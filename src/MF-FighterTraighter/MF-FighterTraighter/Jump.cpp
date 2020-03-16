#include "Jump.h"
#include "Entity.h"
#include "Vector2D.h"


Jump::Jump(float jImpulse) : Component(ecs::Jump), jumpImpulse(jImpulse){}

Jump::~Jump()
{
	delete physics_transform_;
	physics_transform_ = nullptr;
}


void Jump::init()
{
	physics_transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void Jump::handleInput()
{
	if (onGround &&( app_->getInputManager()->isKeyDown(SDL_SCANCODE_W) || app_->getInputManager()->getJoyY()==-1)) {
		physics_transform_->getBody()->ApplyLinearImpulse(b2Vec2(0,jumpImpulse),physics_transform_->getBody()->GetWorldCenter(),true);
		std::cout << "salto" << std::endl;
	}
	
}

void Jump::update()
{
	Vector2D speed = physics_transform_->getSpeed();
	onGround = abs(speed.getY()) <= 2;		//puedes saltar justo cuando empiezas a caer
}