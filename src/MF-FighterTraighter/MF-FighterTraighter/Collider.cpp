#include "Collider.h"

Collider::Collider(Entity* e) : Component(ecs::Collider),en_(e)
{
	// La entidad a la que sea añadido debe tener el componente transform tb
	tr_ = en_->getComponent<Transform>(ecs::Transform);
	pos_ = en_->getComponent<Transform>(ecs::Transform)->getPosition();

}

/*void Collider::update()
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
	//actualizar posicion del collider
	
	
}

void Collider::render()
{
	//pintar linea visual
}*/

Collider::~Collider()
{
}

void Collider::update()
{
	//tr_ = en_ ->getComponent<Transform>(ecs::Transform);
	pos_ = en_ ->getComponent<Transform>(ecs::Transform)->getPosition();
	cout << "collider actualiza pos_" << endl;
}
