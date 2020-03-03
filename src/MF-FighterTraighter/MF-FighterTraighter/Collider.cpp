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
		//app_->getRenderer()
	}
	//pintar linea visual
	
}

Collider::~Collider()
{ //Empty
}

void Collider::update()
{
	
	pos_ = tr_->getPosition(); //update position from entity
	if (debug_) {
		std::cout << "pos collider: " << pos_.getX() << " x, " << pos_.getY() << " y." << endl;
	}
	//for debugging purpouses
}
