#include "Collider.h"

Collider::Collider(Entity* e)
{

}

void Collider::update()
{
	pos_ = entity_->getComponent<Transform>(ecs::Transform)->getPosition();
	/*enum posicion{stand,onAir,crouch};
	switch (posicion)
	{
	case stand:
		//dar tama�o
		break;
	case onAir:
		//dar tama�o
		break;
	case crouch:
		//dar tama�o
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
