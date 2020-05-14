#include "CharacterSelectionHandler.h"
#include "Entity.h"
#include "UITransform.h"
#include "Fight.h"

void CharacterSelectionHandler::init()
{
	ent = new Entity();
	ent->addComponent<Transform>(Vector2D(0, app_->getWindowManager()->getCurResolution().h/4), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h / 4,0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
}

void CharacterSelectionHandler::update()
{
	j1_ = log1->getComponent<CharacterSelectionLogic>(ecs::CharacterSelectionLogic)->getChosen();
	j2_ = log2->getComponent<CharacterSelectionLogic>(ecs::CharacterSelectionLogic)->getChosen();
}

void CharacterSelectionHandler::render()
{
	if (j1_ && j2_) {
		ent->render();
	}
}

void CharacterSelectionHandler::handleInput()
{
	if (j1_ && j2_) {
		app_->getStateMachine()->pushState(new Fight(app_));
	}
}


