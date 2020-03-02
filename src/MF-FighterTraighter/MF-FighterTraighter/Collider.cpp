#include "Collider.h"

Collider::Collider(Entity* e) :
	Component(ecs::Collider), 
	en_(e)	
{	
}


void Collider::init()
{
	tr_ = en_->getComponent<Transform>(ecs::Transform);
}

void Collider::update()
{
	pos_ = tr_->getPosition();
	/*enum posicion{stand,onAir,crouch};
	switch (posicion)
	{
	case stand:
		//dar tamaño
		break;
	case onAir:
		//dar tamaño
		break;
	case crouch:
		//dar tamaño
		break;
	default:
		break;
	}
	//actualizar posicion del collider*/
	
	
}

void Collider::render()
{
	//pintar linea visual
}

Collider::~Collider()
{

}