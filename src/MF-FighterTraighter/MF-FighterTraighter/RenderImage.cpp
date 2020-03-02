#include "RenderImage.h"

void RenderImage::render()
{
	texture_->render(getDestRect());
}

SDL_Rect RenderImage::getDestRect()
{
	SDL_Rect dest = SDL_Rect();
	Vector2D pos = trans_->getPosition();
	dest.x = pos.getX();
	dest.y = pos.getY();
	dest.w = trans_->getWidth() * trans_->getWMult();
	dest.h = trans_->getHeight() * trans_->getHMult();

	return dest;
}
