#include "Collider.h"

Collider::Collider(Entity* e) :
	Component(ecs::Collider), 
	en_(e)	
{	
	
}

void Collider::init()
{
	
	//tr_ = en_->getComponent<Transform>(ecs::Transform);
	tex_= new Texture(en_->getApp()->getRenderer(), filePath.c_str(), 1, 1);
	
	//tex_ = new Texture(app_->getRenderer(), filePath.c_str(), 1, 1);
}

void Collider::render()
{
	/*if (debug_) {
		tex_->render(tr_->getPosition(), tr_->getWidth(), tr_->getHeight());
	}*/
	//pintar linea visual
	ri_->render();
}

Collider::~Collider()
{
}

void Collider::update()
{
	
	pos_ = en_ ->getComponent<Transform>(ecs::Transform)->getPosition();
	
}
