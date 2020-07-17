#include "ButtonControl.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"
#include "OptionsMenu.h"
#include "KeyboardHID.h"
#include "GamepadHID.h"

void ButtonControl::init()
{
	b = ini;
}

void ButtonControl::handleInput()
{
	InputManager* imngr = app_->getInputManager();
	HID* hid = app_->getGameManager()->getPlayerInfo(owner_).hid;
	if (enabled) {
		switch (b) {
		case ButtonControl::ini:
			if (Buttonstate_ == Selected) {
				if (dynamic_cast<KeyboardHID*>(hid) && imngr->KeyPressed(SDL_SCANCODE_RETURN)) {
					Press();
					text_->setText("Press Key");
					b = pressEnter;
				}
				else if (dynamic_cast<GamepadHID*>(hid) && imngr->isControllerButtonPressed(0, SDL_CONTROLLER_BUTTON_A))
				{
					Press();
					text_->setText("Press Button");
					b = pressA;
				}
			}
			break;
		case ButtonControl::pressEnter:
			if (imngr->isKeyUp(SDL_GetScancodeFromName("Return")))
			{
				imngr->readKey();
				b = ENTERUP;
			}

			break;
		case ButtonControl::pressA:
			if (imngr->isControllerButtonUp(0, SDL_CONTROLLER_BUTTON_A))
			{
				imngr->readKey();
				b = AUP;
			}
			break;
		case ButtonControl::AUP:
			texto = imngr->lastcontrol();
			if (texto != "")
			{
				b = leeInput;
			}
			break;
		case ButtonControl::ENTERUP:
			if (imngr->keyboardEvent())
			{
				texto = SDL_GetScancodeName(imngr->lastKey());
				if (texto != "") {
					b = leeInput;
				}
			}
			break;
		case ButtonControl::leeInput:
			texto = "";
			b = ini;
			if (clickCallback_) {
				clickCallback_(app_, index, owner_);
			}
			Buttonstate_ = Selected;
			entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(1, 0);
			imngr->stopreadKey();
			break;
		}
	}
	else if (b != ini) {
		imngr->stopreadKey();
		b = ini;
	}
}

void ButtonControl::render()
{
	if (enabled) {
		HID* hid = app_->getGameManager()->getPlayerInfo(owner_).hid;

		if (b == ini)
		{
			if (dynamic_cast<KeyboardHID*>(hid))
			{
				text_->setText(SDL_GetScancodeName(static_cast<KeyboardHID*>(hid)->getkeys().at(index)));

			}
			else if(dynamic_cast<GamepadHID*>(hid))
			{
				text_->setText(static_cast<GamepadHID*>(hid)->getControl().at(index));
			}
		}
	}
	else {
		text_->setText("");
	}
};
