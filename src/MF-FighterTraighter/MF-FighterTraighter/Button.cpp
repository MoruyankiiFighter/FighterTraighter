#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"
#include "OptionsMenu.h"
#include "consts.h"

void Button::init()
{
	transform_ = entity_->getComponent<Transform>(ecs::Transform);
}

void Button::handleInput()
{
	if (selected_) {
		InputManager* imngr = app_->getInputManager();
		if (imngr->pressedAccept()) {
			if (!pressed_) {
				pressed_ = true;
				entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(2, 0);
				if (clickCallback_) clickCallback_(app_);
			}
		}
		else if (pressed_) {
			pressed_ = false;
			entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(0, 0);
			if (stopClickCallback_) stopClickCallback_(app_);
		}
	}
}
