#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"
#include "OptionsMenu.h"
#include "consts.h"

void Button::init()
{
}

void Button::handleInput()
{
	if (Buttonstate_ == Selected) {
		InputManager* imngr = app_->getInputManager();
		if (imngr->pressedAccept()) {
			Press();
		}
	}
	else if (Buttonstate_ == Pressed) {
		Buttonstate_ = Selected;
		entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(1, 0);
		if (stopClickCallback_) stopClickCallback_(app_);
	}
}

void Button::render()
{

}
