#include "InventoryLogic.h"
#include "Entity.h"
#include "UITransform.h"
InventoryLogic::InventoryLogic(NavigationController* nav, int player, RenderImage* left, RenderImage* right):
	Component(ecs::InventoryLogic), nav_(nav), player_(player), left_(left), right_(right)
{
}

void InventoryLogic::init()
{
	pressed = false;
	ent = new Entity();
	ent->addComponent<Transform>(Vector2D(), Vector2D(), 100, 100, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::SelectionSquare));

}

void InventoryLogic::update()
{
	if (!pressed) {
		if (nav_->GetPosY() == 0) {
			if (app_->getGameManager()->getPlayerInfo(player_).abilities.size() > nav_->GetPosX()) { //revisar esta comprobacion
				curr = app_->getGameManager()->getPlayerInfo(player_).abilities[nav_->GetPosX()]; //0 a 5
			}
		}
		else if (nav_->GetPosY() == 1) {

			if (app_->getGameManager()->getPlayerInfo(player_).abilities.size() > 5+ nav_->GetPosX()) {//revisar esta comprobacion
				curr = app_->getGameManager()->getPlayerInfo(player_).abilities[(nav_->GetPosX() + 5)]; //5 a 10
			}
		}

		ent->getComponent<Transform>(ecs::Transform)->setPosition
		(nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())->getEntity()->getComponent<UITransform>(ecs::Transform)->getPosition());
		//cout << ent->getComponent<Transform>(ecs::Transform)->getPosition().getX()<<endl;
	}
}

void InventoryLogic::render()
{
	if (!pressed&& nav_->GetPosY()<2) {
		ent->render();
	}
}

void InventoryLogic::handleInput()
{
	ab1_index = app_->getGameManager()->getPlayerInfo(player_).ability1Index;
	ab2_index = app_->getGameManager()->getPlayerInfo(player_).ability2Index;
	if (nav_->GetPosY() != 2) {
		if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::LeftBumper) &&  ab2_index != curr && !pressed) {
			app_->getGameManager()->setFirstHab(curr, player_);

			cout << "hab1 equipada ";
			if (left_ != nullptr) {
				left_->setTexture(app_->getAssetsManager()->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(2).abilities[ab1_index] + 1)));
			}
		}
		if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightBumper) && ab1_index != curr && !pressed) {
			app_->getGameManager()->setSecondHab(curr, player_);
			cout << "hab2 equipada ";
			if (right_ != nullptr) {
				right_->setTexture(app_->getAssetsManager()->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(2).abilities[ab2_index] + 1)));
			}
					
		}
	}
	else 
	{
		if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Down) && !pressed) {
			pressed = true;
			cout << "waiting for fight";
		}
		
		else if (pressed && app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Right)) {
			pressed = false;
			cout << "Canceled";
		}
	}
}
