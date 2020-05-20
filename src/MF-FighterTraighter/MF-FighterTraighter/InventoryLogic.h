#pragma once
#include "Component.h"
#include "NavigationController.h"
#include "RenderImage.h"
class InventoryLogic :
	public Component
{
public:
	InventoryLogic(NavigationController* nav, int player, RenderImage* left, RenderImage* right);

	void init() override;
	void update() override;
	void handleInput() override;

	inline bool getPressed() { return pressed; }
private:
	RenderImage* left_;
	RenderImage* right_;
	NavigationController* nav_;
	int player_;
	GameManager::AbilityID curr;
	bool pressed = false;
};

