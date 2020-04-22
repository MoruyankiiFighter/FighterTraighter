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
			leeKey = true;
			text_->setText("Press keyboard");

		}
	}
	if (app_->getInputManager()->Getinput() != "Return" && leeKey)
	{
		leeKey = false;
		if (clickCallback_)
		{
			clickCallback_(app_, index);
		}
		text_->setText(app_->getInputManager()->Getinput());

		state_ = Selected;
		entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(1, 0);
	}
}

void ButtonControl::render()
{

};

