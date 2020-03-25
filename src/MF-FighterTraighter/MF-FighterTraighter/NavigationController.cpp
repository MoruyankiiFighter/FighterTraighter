#include "NavigationController.h"
#include "Button.h"

NavigationController::NavigationController(size_t sizeX, size_t sizeY) : Component(ecs::NavigationController), grid_(sizeX, sizeY), cursorPositionX_(), cursorPositionY_()
{
}

void NavigationController::init()
{
}

void NavigationController::handleInput()
{
	InputManager* mngr = app_->getInputManager();
	if (mngr->pressedUp() && cursorPositionY_ > 0) {
		--cursorPositionY_;
	}
	else if (mngr->pressedDown() && cursorPositionY_ < grid_.GetSizeY() - 1) {
		++cursorPositionY_;
	}
	if (mngr->pressedLeft() && cursorPositionX_ > 0) {
		--cursorPositionX_;
	}
	else if (mngr->pressedRight() && cursorPositionX_ < grid_.GetSizeX() - 1) {
		++cursorPositionX_;
	}
	Entity* ent = grid_.GetItem(cursorPositionX_, cursorPositionY_);
	ent->getComponent<Button>(ecs::Button)->setSelected(true);
}

void NavigationController::SetElementInPos(Entity* ent, size_t x, size_t y)
{
	grid_.SetItemInPos(ent, x, y);
}

Entity* NavigationController::GetElementInPos(size_t x, size_t y)
{
	return grid_.GetItem(x, y);
}
