#include "NavigationController.h"
#include "Button.h"

NavigationController::NavigationController(size_t sizeX, size_t sizeY, HID* owner) : Component(ecs::NavigationController), grid_(sizeX, sizeY), cursorPositionX_(), cursorPositionY_(), owner_(owner)
{
}

void NavigationController::init()
{
}

void NavigationController::handleInput()
{
	InputManager* mngr = app_->getInputManager();
	int oldX = cursorPositionX_, oldY = cursorPositionY_;
	int temp;


		if ((!owner_ && mngr->pressedUp() || owner_ && owner_->ButtonPressed(HID::LeftPad_Up)) && cursorPositionY_ > 0 && (temp = findInRowFrom(cursorPositionY_ - 1)) != -1)
		{
			cursorPositionY_ = temp;
		}
		else if ((!owner_ && mngr->pressedDown() || owner_ && owner_->ButtonPressed(HID::LeftPad_Down)) && cursorPositionY_ < grid_.GetSizeY() - 1 && (temp = findInRowFrom(cursorPositionY_ + 1)) != -1) {
			cursorPositionY_ = temp;
		}
		if ((!owner_ && mngr->pressedLeft() || owner_ && owner_->ButtonPressed(HID::LeftPad_Left)) && cursorPositionX_ > 0 && (temp = findInColFrom(cursorPositionX_ - 1)) != -1) {
			cursorPositionX_ = temp;
		}
		else if ((!owner_ && mngr->pressedRight() || owner_ && owner_->ButtonPressed(HID::LeftPad_Right)) && cursorPositionX_ < grid_.GetSizeX() - 1 && (temp = findInColFrom(cursorPositionX_ + 1)) != -1) {
			cursorPositionX_ = temp;
		}

		if (cursorPositionX_ != oldX || cursorPositionY_ != oldY) // If the cursor moved
		{
			UIElement* ent = grid_.GetItem(oldX, oldY);
			ent->Deselect();
			ent = grid_.GetItem(cursorPositionX_, cursorPositionY_);
			ent->Select();
		}
	
	
}

void NavigationController::SetElementInPos(UIElement* ent, size_t x, size_t y)
{
	grid_.SetItemInPos(ent, x, y);
	if (!selectedFirst_) {
		cursorPositionX_ = x;
		cursorPositionY_ = y;
		ent->Select();
		selectedFirst_ = true;
	}
}

UIElement* NavigationController::GetElementInPos(size_t x, size_t y)
{
	return grid_.GetItem(x, y);
}

// Does not work properly
int NavigationController::findInRowFrom(int y)
{
	int i = y;
	while (i >= 0 && grid_.GetItem(cursorPositionX_, y) == nullptr) {
		--i;
	}
	if (i < 0 && y + 1 < grid_.GetSizeY()) {
		i = y + 1;
		while (i < grid_.GetSizeY() && grid_.GetItem(cursorPositionX_, y) == nullptr) {
			++i;
		}
	}
	if (i == grid_.GetSizeY()) return -1;
	return i;
}

// Does not work properly
int NavigationController::findInColFrom(int x)
{
	int i = x;
	while (i >= 0 && grid_.GetItem(x, cursorPositionY_) == nullptr) {
		--i;
	}
	if (i < 0 && x + 1 < grid_.GetSizeX()) {
		i = x + 1;
		while (i < grid_.GetSizeX() && grid_.GetItem(x, cursorPositionY_) == nullptr) {
			++i;
		}
	}
	if (i == grid_.GetSizeX()) return -1;
	return i;
}
