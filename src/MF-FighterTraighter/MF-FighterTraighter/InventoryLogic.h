#pragma once
#include "Component.h"
#include "NavigationController.h"
class InventoryLogic :
	public Component
{
public:
	InventoryLogic(NavigationController* nav, int player, UIElement* left, UIElement* right);

	void init() override;
	void update() override;
	void handleInput() override;
private:
	UIElement* left_;
	UIElement* right_;
	NavigationController* nav_;
	int player_;
	GameManager::AbilityID curr;
};

