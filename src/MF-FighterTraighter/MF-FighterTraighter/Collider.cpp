#include "Collider.h"

Collider::Collider(Entity* e) :
	Component(ecs::Collider), 
	en_(e)	
{	
}

void Collider::init()
{
	
	//tr_ = en_->getComponent<Transform>(ecs::Transform);
	
}

void Collider::render()
{
	if (debug) {
		tex->render(tr_->getPosition(), tr_->getWidth(), tr_->getHeight());
	}
	//pintar linea visual
}

Collider::~Collider()
{
}

void Collider::update()
{
	//tr_ = en_ ->getComponent<Transform>(ecs::Transform);
	pos_ = en_ ->getComponent<Transform>(ecs::Transform)->getPosition();
	cout << "collider actualiza pos_" << endl;
}

