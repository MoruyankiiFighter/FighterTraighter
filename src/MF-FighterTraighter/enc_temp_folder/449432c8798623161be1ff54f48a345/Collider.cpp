#include "Collider.h"

Collider::Collider(Entity* e) :
	Component(ecs::Collider), 
	en_(e)	
{	
	
}

void Collider::init()
{
<<<<<<< HEAD
	
	//tr_ = en_->getComponent<Transform>(ecs::Transform);
	tex_= new Texture(en_->getApp()->getRenderer(), filePath.c_str(), 1, 1);
	
	//tex_ = new Texture(app_->getRenderer(), filePath.c_str(), 1, 1);
=======
	tr_ = en_->getComponent<Transform>(ecs::Transform);
	tex_ = new Texture(en_->getApp()->getRenderer(), filePath.c_str(), 1, 1);
	tex_->render(tr_->getPosition(), tr_->getWidth(), tr_->getHeight());
	//Entity* col_ = new Entity(); // Until we have factories
	//col_->setApp(app_);
	//col_->addComponent<RenderImage>(tex_);
	
>>>>>>> 17b7639f88461f65fe0cc84b18f136a1bb894617
}

void Collider::render()
{
<<<<<<< HEAD
	/*if (debug_) {
		tex_->render(tr_->getPosition(), tr_->getWidth(), tr_->getHeight());
	}*/
	//pintar linea visual
	ri_->render();
=======
	//if (debug_) {
	//	tex_->render(tr_->getPosition(), tr_->getWidth(), tr_->getHeight());
	//}
	////pintar linea visual

>>>>>>> 17b7639f88461f65fe0cc84b18f136a1bb894617
}

Collider::~Collider()
{
}

void Collider::update()
{
	
	pos_ = en_ ->getComponent<Transform>(ecs::Transform)->getPosition();
	
}
