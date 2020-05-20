#include "InventoryHandler.h"
#include "Entity.h"
#include "UITransform.h"
#include "Fight.h"
#include "InventoryLogic.h"
void InventoryHandler::init()
{
	ent = new Entity();
	ent->addComponent<Transform>(Vector2D(0, app_->getWindowManager()->getCurResolution().h / 4), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h / 4, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Panel));
}

void InventoryHandler::update()
{
	pressed_1 = j1_->getComponent<InventoryLogic>(ecs::InventoryLogic)->getPressed();
	pressed_2 = j2_->getComponent<InventoryLogic>(ecs::InventoryLogic)->getPressed();
}

void InventoryHandler::render()
{
	if (pressed_1 && pressed_2) {
		cout << "aaa";
		ent->render();
	}
}

void InventoryHandler::handleInput()
{
	if (pressed_1 && pressed_2) {
		app_->getStateMachine()->pushState(new Fight(app_));
	}
}
