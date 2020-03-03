#include "Collider.h"

Collider::Collider() :
	Component(ecs::Collider)
{	//Empty
	
}

void Collider::init()
{
	tr_ = entity_->getComponent<Transform>(ecs::Transform); 
	// get entity transform
	tex_ = new Texture(entity_->getApp()->getRenderer(), filePath.c_str(), 1, 1);	
	// creates new texture whith Greenbox file path
}

void Collider::render()
{
	if (debug_) {
		//tex_->render(/*falta SDL_Rect*/);
	}
	//pintar linea visual
	
}

Collider::~Collider()
{ //Empty
}

void Collider::update()
{
	
	pos_ = tr_->getPosition(); //update position from entity
	
}
