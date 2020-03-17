#include "Jump.h"
#include "Entity.h"
#include "Vector2D.h"

//constructor
Jump::Jump(float jImpulse) : Component(ecs::Jump), jumpImpulse(jImpulse){}

//destructor, deletes the physics transform
Jump::~Jump()
{
	delete physics_transform_;
	physics_transform_ = nullptr;
}

//init where we get the physics transform component
void Jump::init()
{
	physics_transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

//handle input, we check the jump button (W) or the joysticks for moving the object
void Jump::handleInput()
{
	if (onGround &&( app_->getInputManager()->isKeyDown(SDL_SCANCODE_W) || app_->getInputManager()->getJoyY()==-1)) {
		physics_transform_->getBody()->ApplyLinearImpulse(b2Vec2(0,jumpImpulse),physics_transform_->getBody()->GetWorldCenter(),true);
		std::cout << "salto" << std::endl;
	}
	
}

//updates the speed of the object
void Jump::update()
{
	Vector2D speed = physics_transform_->getSpeed();
	onGround = abs(speed.getY()) <= 2;		//puedes saltar justo cuando empiezas a caer
}