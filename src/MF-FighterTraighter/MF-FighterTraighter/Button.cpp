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
	if (selected_) {
		InputManager* imngr = app_->getInputManager();
		if (imngr->pressedAccept()) {
			if (!pressed_) {
				pressed_ = true;
				if (clickCallback_) clickCallback_(app_);
			}
		}
		else if (pressed_) {
			pressed_ = false;
			if (stopClickCallback_) stopClickCallback_(app_);
		}
	}
}
