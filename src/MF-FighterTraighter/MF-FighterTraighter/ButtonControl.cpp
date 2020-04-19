#include "ButtonControl.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"
#include "OptionsMenu.h"
#include "consts.h"

void ButtonControl::init()
{
}

void ButtonControl::handleInput()
{
	if (state_ == Selected) {
		InputManager* imngr = app_->getInputManager();
		if (imngr->pressedAccept()) {
			Press();
		}
	}
	else if (state_ == Pressed) {
		state_ = Selected;
		entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(1, 0);
		if (stopClickCallback_) stopClickCallback_(app_);
	}
}

void ButtonControl::render()
{

}
