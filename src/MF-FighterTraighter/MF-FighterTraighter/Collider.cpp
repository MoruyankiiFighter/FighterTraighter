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
