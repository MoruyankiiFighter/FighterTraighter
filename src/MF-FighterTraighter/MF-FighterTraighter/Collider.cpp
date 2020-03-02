#include "Collider.h"

Collider::Collider(Entity* e) :
	Component(ecs::Collider), 
	en_(e)	
{	
}

void Collider::init()
{
	tr_ = en_->getComponent<Transform>(ecs::Transform);
	text_ = new Texture(app_->getRenderer(), filePath.c_str(), 1, 1);
}

/*void Collider::update()
{
	pos_ = tr_->getPosition();
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
	//actualizar posicion del collider
	
	
}*/

void Collider::render()
{
	//pintar linea visual
}

void Collider::update()
{
	//tr_ = en_ ->getComponent<Transform>(ecs::Transform);
	pos_ = en_ ->getComponent<Transform>(ecs::Transform)->getPosition();
	cout << "collider actualiza pos_" << endl;
}

Collider::~Collider()
{
}