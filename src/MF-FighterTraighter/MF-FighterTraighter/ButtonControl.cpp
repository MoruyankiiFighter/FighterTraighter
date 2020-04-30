#include "ButtonControl.h"
#include "Entity.h"
#include "Transform.h"
#include "PauseMenu.h"
#include "OptionsMenu.h"
#include "consts.h"

void ButtonControl::init()
{
	b = ini;
}

void ButtonControl::handleInput()
{
	InputManager* imngr = app_->getInputManager();
	
	switch (b)
	{
	case ButtonControl::ini:
		if (state_ == Selected) {

			if (imngr->isKeyDown(SDL_SCANCODE_RETURN) && control == 0) {
				Press();
				text_->setText("Press Key");

				b = pressEnter;
			}
			else if (imngr->isControllerButtonUp(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_A) && control == 1)
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
			b = ENTERUP;
		}
		
		break;
	case ButtonControl::pressA:
		if (!imngr->isControllerButtonPressed(InputManager::PLAYER1, SDL_CONTROLLER_BUTTON_A))
		{
			b = AUP;

		}
		break;
	case ButtonControl::AUP:
		if (imngr->axisEvent())
		{
			texto = imngr->lastAxisstring();

		}
		else if (imngr->controllerEvent() )
		{
			texto = imngr->lastButtonstring();
			
		}
		if (texto != "")
		{
			b = leeInput;

		}
		break;
	case ButtonControl::ENTERUP:
		if (imngr->keyboardEvent())
		{
			texto = imngr->lastKeystring();
			if (texto!="")
			{
				b = leeInput;

			}

		}
		break;
	case ButtonControl::leeInput:
		texto = "";
		b = ini;
		if (clickCallback_)
		{
			clickCallback_(app_, index, control);
		}
		state_ = Selected;
		entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(1, 0);
		break;
	}			
}

void ButtonControl::render()
{
	if (b==ini)
	{
		if (control == 0 )
		{
			text_->setText(SDL_GetScancodeName(app_->getInputManager()->ControlKeyboard()[index]));

		}
		else if(index>3)
		{
			text_->setText(app_->getInputManager()->ControlMando()[index-4]);
		}
	}
	
};

