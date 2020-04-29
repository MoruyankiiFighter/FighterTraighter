#include "RenderAnimation.h"
#include "Entity.h"

void RenderAnimation::init()
{
	tr_ = entity_->getComponent<Transform>(ecs::Transform);
}

void RenderAnimation::update()
{
	++framesSinceLastFrame_;
	if (framesSinceLastFrame_ == frameDuration_) {
		framesSinceLastFrame_ = 0;
		++curFrame_;
		if (curFrame_ >= tex_->getCols()) {
			curFrame_ = 0;
		}
	}
}

void RenderAnimation::render()
{
	SDL_Rect dest;
	dest.x = tr_->getPosition().getX();
	dest.y = tr_->getPosition().getY();
	dest.w = tr_->getWidth() * tr_->getWMult();
	dest.h = tr_->getHeight() * tr_->getHMult();
	tex_->render(dest, 0, curFrame_);
}
