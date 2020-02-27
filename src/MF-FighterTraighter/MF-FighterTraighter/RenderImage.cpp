#include "RenderImage.h"
#include "RenderImage.h"

void RenderImage::render()
{
	tex_->render(trans_->getPosition(), trans_->getWidth(), trans_->getHeight()); //Esto si la escala de transform es un multiplicador

	/*Vector2D pos = trans_->getPosition();
	tex_->render({ pos.getX(), pos.getY(), trans_->getWidth(), trans_->getHeight() }); //Esto si transform tiene la escala directamente*/
}
