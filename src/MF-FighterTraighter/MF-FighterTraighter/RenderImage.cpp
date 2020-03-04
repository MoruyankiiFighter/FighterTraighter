#include "RenderImage.h"

void RenderImage::render()
{
	//tex_->render(trans_->getPosition(), trans_->getWidth(), trans_->getHeight()); //Esto si la escala de transform es un multiplicador

	Vector2D pos = trans_->getPosition();
	SDL_Rect dest = SDL_Rect();
	dest.x = pos.getX();
	dest.y = pos.getY();
	dest.w = trans_->getWidth() * trans_->getWMult();
	dest.h = trans_->getHeight() * trans_->getHMult();

	tex_->render(dest);
	
	//tex_->render(SDL_Rect(pos.getX(), (double)pos.getY(), trans_->getWidth() * trans_->getWMult(), trans_->getHeight() * trans_->getHMult())); //Esto si transform tiene la escala directamente
}
