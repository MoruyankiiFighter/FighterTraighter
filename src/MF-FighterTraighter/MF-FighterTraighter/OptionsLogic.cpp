#include "OptionsLogic.h"
#include "Entity.h"
#include "AudioOptionsLogic.h"
#include "GraphicsOptionsLogic.h"
#include "ControlsOptionsLogic.h"

void OptionsLogic::init()
{
	grLogic = entity_->getComponent<GraphicsOptionsLogic>(ecs::GraphicsOptionsLogic);
	auLogic = entity_->getComponent<AudioOptionsLogic>(ecs::AudioOptionsLogic);
	coLogic = entity_->getComponent<ControlsOptionsLogic>(ecs::ControlsOptionsLogic);

	grLogic->setEnabled(false);
	auLogic->setEnabled(false);
	coLogic->setEnabled(false);
}

void OptionsLogic::handleInput()
{
	if (app_->getInputManager()->pressedAccept() && mainNavEnabled) {
		if (mainNav->GetSelectedElement() == graphicsButton)
		{
			grLogic->setEnabled(true);
			auLogic->setEnabled(false);
			coLogic->setEnabled(false);
			
		}
		else if (mainNav->GetSelectedElement() == audioButton) 
		{
			grLogic->setEnabled(false);
			auLogic->setEnabled(true);
			coLogic->setEnabled(false);
		}
		else if (mainNav->GetSelectedElement() == controlsButton) 
		{
			grLogic->setEnabled(false);
			auLogic->setEnabled(false);
			coLogic->setEnabled(true);
		}
		mainNav->setEnabled(false);
		mainNavEnabled = false;
	}
	else if (app_->getInputManager()->pressedStart() && !mainNavEnabled) {
		mainNav->setEnabled(true);
		mainNav->ChangeSelectedItem(mainNav->GetPosX(), mainNav->GetPosY());
		grLogic->setEnabled(false);
		auLogic->setEnabled(false);
		coLogic->setEnabled(false);
		mainNavEnabled = true;
	}
}
