#include "CharacterSelectionHandler.h"
#include "Entity.h"
#include "UITransform.h"
#include "Fight.h"

void CharacterSelectionHandler::init()
{
	ent = app_->getStateMachine()->getCurrentState()->getEntityManager().addEntity();
	ent->addComponent<Transform>(Vector2D(), Vector2D(), 500, 100, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
}

void CharacterSelectionHandler::update()
{
	j1_ = log1->getComponent<CharacterSelectionLogic>(ecs::CharacterSelectionLogic)->getChosen();
	j2_ = log2->getComponent<CharacterSelectionLogic>(ecs::CharacterSelectionLogic)->getChosen();

 	if (j1_ && j2_) {
		cout<<"A pegarse de ostias";
		ent->getComponent<RenderImage>(ecs::RenderImage)->setTexture((app_->getAssetsManager()->getTexture(AssetsManager::Player)));

	}
	else {
		ent->getComponent<RenderImage>(ecs::RenderImage)->setTexture(nullptr);

	}
}

void CharacterSelectionHandler::handleInput()
{
	if (j1_ && j2_) {
		if (app_->getGameManager()->getPlayerInfo(1).hid->ButtonPressed(HID::RightPad_Right) || app_->getGameManager()->getPlayerInfo(2).hid->ButtonPressed(HID::RightPad_Right)) {
			app_->getStateMachine()->pushState(new Fight(app_));
		}
	}

}
