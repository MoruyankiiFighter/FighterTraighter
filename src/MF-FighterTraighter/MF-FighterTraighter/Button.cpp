#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"
#include "OptionsMenu.h"
#include "consts.h"

void Button::init()
{
	trans_ = entity_->getComponent<Transform>(ecs::Transform);
}

void Button::handleInput()
{
	InputManager* imngr = app_->getInputManager();
	if (imngr->isMouseButtonPressed(imngr->Left)) {
		if (imngr->mouseEvent()) { // if left mouse has just been clicked
			SDL_Point p = { imngr->getMousePosX(), imngr->getMousePosY() };
			Vector2D pos = trans_->getPosition();
			SDL_Rect destRect = { pos.getX(), pos.getY(), trans_->getWidth() * trans_->getWMult(), trans_->getHeight() * trans_->getHMult() };

			if (!pressed_ && SDL_PointInRect(&p, &destRect)) {
				pressed_ = true;
				if (clickCallback_) clickCallback_(app_);
			}
		}
	}
	else if (select && app_->getInputManager()->isControllerButtonPressed(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_BUTTON_A))
	{
		callbackbutton(app_);
	}

	else if (pressed_) {
		pressed_ = false;
		if (stopClickCallback_) stopClickCallback_(app_);
	}
}
