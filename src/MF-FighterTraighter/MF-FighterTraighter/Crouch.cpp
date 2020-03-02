#include  "Crouch.h"
#include "Entity.h"
#include "Vector2D.h"

Crouch::Crouch() : Component(ecs::PlayerController), tr_(nullptr)
{
	can = true;
}

void Crouch::init()
{
	tr_ = entity_->getComponent<Transform>(ecs::Transform);
}

void Crouch::handleInput()
{
	if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_S) && CanCrouch()) {
		crouch();
	}
	else if(app_->getInputManager()->isKeyUp(SDL_SCANCODE_S))
	{
		uncrouch();
	}
	
	
}

void Crouch::update()
{
	//tr_->setPosition(tr_->getPosition() + tr_->getSpeed());
}
void Crouch::crouch()
{
	can = false;

	tr_->setHeight(tr_->getHeight() / 2);
	tr_->setPosition(tr_->getPosition() + Vector2D(0,tr_->getHeight()));
	//animaciones de agachar
}void Crouch::uncrouch()
{
	can = true;
	tr_->setPosition(tr_->getPosition() + Vector2D(0, tr_->getHeight())*(-1));
	//animaciones por defecto
}
bool Crouch::CanCrouch()
{

	/*if (true)
	{

	}*/
	//if para comprobar todo lo que necesita para saber si puede agacharse o no 
	return can;
	//animaciones por defecto
}




Crouch::~Crouch()
{
}
