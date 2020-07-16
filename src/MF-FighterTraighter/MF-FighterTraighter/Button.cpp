#include "Button.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"
#include "OptionsMenu.h"

void Button::init()
{
}

void Button::handleInput()
{
	if (Buttonstate_ == Selected) {
		HID* hid = nullptr;
		if (owner_ != GameManager::NoPlayer)
			hid = app_->getGameManager()->getPlayerInfo(owner_).hid;
		if (owner_ == GameManager::NoPlayer && app_->getInputManager()->pressedAccept() || hid && (hid->ButtonPressed(HID::RightPad_Down) || hid->ButtonPressed(HID::Select))) {
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
