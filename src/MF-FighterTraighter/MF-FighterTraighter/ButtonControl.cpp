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
	InputManager* imngr = app_->getInputManager();
	string texto;
	if (!leeKey)
	{
		if (state_ == Selected) {

			if (imngr->pressedAccept()) {
				Press();
				leeKey = true;
				text_->setText("Press");
			}
		}
	}
	else if (leeKey)
	{
	
		if (!arriba)
		{
		 arriba=imngr->isKeyUp(SDL_GetScancodeFromName("Return")) && imngr->isControllerButtonUp(InputManager::PLAYER1,SDL_CONTROLLER_BUTTON_A);

		}
		else if (arriba)
		{
			
			if (imngr->axisEvent() && control ==1)
			{
				texto = imngr->lastAxisstring();

			}
			else if (imngr->controllerEvent()&& control ==1)
			{
				texto = imngr->lastButtonstring();


			}
			else if (imngr->keyboardEvent() && control ==0)
			{
				texto = imngr->lastKeystring();
			}

			if (texto != "" )
			{
				text_->setText(texto);
				leeKey = false;
				arriba = false;
				if (clickCallback_)
				{
					clickCallback_(app_, index, control);
				}
				state_ = Selected;
				entity_->getComponent<RenderImage>(ecs::RenderImage)->setFrame(1, 0);
			}

		}
	}
}

void ButtonControl::render()
{

};

