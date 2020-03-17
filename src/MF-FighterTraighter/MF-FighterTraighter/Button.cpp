#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"

//init where get the transform from the entity
void Button::init()
{
	trans_ = entity_->getComponent<Transform>(ecs::Transform);
}

//handle the input of the mouse
void Button::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(app_->getInputManager()->Left)) {
		cout << "click";
		SDL_Point p = { app_->getInputManager()->getMousePosX(),app_->getInputManager()->getMousePosY() };

		Vector2D pos = trans_->getPosition();
		SDL_Rect destRect = { pos.getX(), pos.getY(), trans_->getWidth() * trans_->getScaleX(), trans_->getHeight() * trans_->getScaleY() };

		if (SDL_PointInRect(&p, &destRect)) {
			//cout << "arcade";
			callbackbutton(app_);
		}
	}

}
