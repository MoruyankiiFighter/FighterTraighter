#include "InventoryLogic.h"

InventoryLogic::InventoryLogic(NavigationController* nav, int player, UIElement* left, UIElement* right): 
	Component(ecs::InventoryLogic), nav_(nav), player_(player), left_(left), right_(right)
{
}

void InventoryLogic::init()
{
	
}

void InventoryLogic::update()
{

}

void InventoryLogic::handleInput()
{
	if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Right)) {
		app_->getGameManager()->setFirstHab(curr, player_);
	}
	if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Left)) {
		app_->getGameManager()->setSecondHab(curr, player_);
	}
}
