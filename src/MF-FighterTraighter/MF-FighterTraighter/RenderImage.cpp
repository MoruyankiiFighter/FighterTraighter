#include "RenderImage.h"

void RenderImage::init()
{
	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
}

void RenderImage::render()
{
	//tex_->render(trans_->getPosition(), trans_->getWidth(), trans_->getHeight()); //Esto si la escala de transform es un multiplicador

	Vector2D pos = transform_->getPosition();
	SDL_Rect dest = SDL_Rect();
	dest.x = pos.getX();
	dest.y = pos.getY();
	dest.w = transform_->getWidth() * transform_->getScaleX();
	dest.h = transform_->getHeight() * transform_->getScaleY();
	//dest.x = pos.getX() - dest.w / 2;
	//dest.y = pos.getY() - dest.h / 2;
	texture_->render(dest);
	
	//tex_->render(SDL_Rect(pos.getX(), (double)pos.getY(), trans_->getWidth() * trans_->getWMult(), trans_->getHeight() * trans_->getHMult())); //Esto si transform tiene la escala directamente
}
