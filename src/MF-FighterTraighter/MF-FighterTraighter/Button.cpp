#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"

void Button::init()
{
	trans_ = entity_->getComponent<Transform>(ecs::Transform);
}

void Button::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(app_->getInputManager()->Left)) {
		cout << "click";
		SDL_Point p = { app_->getInputManager()->getMousePosX(),app_->getInputManager()->getMousePosY() };

		Vector2D pos = trans_->getPosition();
		SDL_Rect destRect = { pos.getX(), pos.getY(), trans_->getWidth() * trans_->getWMult(), trans_->getHeight() * trans_->getHMult() };

		if (SDL_PointInRect(&p, &destRect)) {
			//cout << "arcade";
			callbackbutton(app_);
		}
	}

}
