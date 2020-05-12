#include "CharacterSelectionHandler.h"
#include "Entity.h"
#include "UITransform.h"
#include "Fight.h"
void CharacterSelectionHandler::init()
{
}

void CharacterSelectionHandler::update()
{
	Entity* e;
	e->addComponent<UITransform>(Vector2D(), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2), Vector2D(), app_->getWindowManager()->getCurResolution().w / 4, app_->getWindowManager()->getCurResolution().h / 5);
	e->addComponent<TextComponent>("GO TO FIGHT", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 120, TextComponent::TextAlignment::Center);
	if (j1_ && j2_) {
	}
	else{
		if (e != nullptr) {
			state_->getEntityManager().removeEntity(e);
		}
	}
}

void CharacterSelectionHandler::handleInput()
{
	if ((app_->getGameManager()->getPlayerInfo(1).hid->ButtonPressed(HID::RightPad_Down) || app_->getGameManager()->getPlayerInfo(2).hid->ButtonPressed(HID::RightPad_Down))&&(j1_&&j2_)) {
		app_->getStateMachine()->pushState(new Fight(app_));
	}
}
