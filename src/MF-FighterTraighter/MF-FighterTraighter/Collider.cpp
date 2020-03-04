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
	Vector2D pos = tr_->getPosition();
	double rot = tr_->getRotation();
	SDL_Rect dest = SDL_Rect();
	dest.x = pos.getX();
	dest.y = pos.getY();
	dest.w = tr_->getWidth();
	dest.h = tr_->getHeight();
	//tex_->render(dest, rot);	
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

