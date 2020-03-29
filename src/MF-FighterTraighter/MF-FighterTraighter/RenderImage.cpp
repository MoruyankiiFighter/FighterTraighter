#include "RenderImage.h"

RenderImage::~RenderImage()
{
	transform_ = nullptr;
	texture_ = nullptr;
}

//set the transform to the entity transform
void RenderImage::init()
{
	transform_ = entity_->getComponent<Transform>(ecs::Transform);
}

//render the image
void RenderImage::render()
{
	Vector2D pos = transform_->getPosition();
	SDL_Rect dest = SDL_Rect();
	dest.x = pos.getX();
	dest.y = pos.getY();
	dest.w = trans_->getWidth() * trans_->getWMult();
	dest.h = trans_->getHeight() * trans_->getHMult();
	//dest.x = pos.getX() - dest.w / 2;
	//dest.y = pos.getY() - dest.h / 2;
	tex_->render(dest, curY, curX);
	
}
