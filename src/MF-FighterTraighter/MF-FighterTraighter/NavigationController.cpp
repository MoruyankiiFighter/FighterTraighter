#include "NavigationController.h"
#include "Button.h"
#include "GameManager.h"

NavigationController::NavigationController(size_t sizeX, size_t sizeY, GameManager::PlayerID owner) : Component(ecs::NavigationController), grid_(sizeX, sizeY), cursorPositionX_(), cursorPositionY_(), owner_(owner)
{
}

void NavigationController::init()
{
}

void NavigationController::handleInput()
{
	if (enabled_) {
		InputManager* mngr = app_->getInputManager();
		HID* hid = nullptr;
		if (owner_ != GameManager::NoPlayer)
			hid = app_->getGameManager()->getPlayerInfo(owner_).hid;
		int newX = cursorPositionX_, newY = cursorPositionY_;
		int temp;
		if ((owner_ == GameManager::NoPlayer && mngr->pressedUp() ||
			hid && (hid->ButtonPressed(HID::LeftPad_Up) ||
			((hid->AxisChanged(HID::LJoyY)) && hid->AxisInput(HID::LJoyY) < 0)))
			&& cursorPositionY_ > 0 && (temp = findInRowFrom(--newY)) != -1)
		{
			newX = temp;
		}
		else if ((owner_ == GameManager::NoPlayer && mngr->pressedDown() ||
			hid && (hid->ButtonPressed(HID::LeftPad_Down) ||
			((hid->AxisChanged(HID::LJoyY)) && hid->AxisInput(HID::LJoyY) > 0)))
			&& cursorPositionY_ < grid_.GetSizeY() - 1 && (temp = findInRowFrom(++newY)) != -1)
		{
			newX = temp;
		}
		else if ((owner_ == GameManager::NoPlayer && mngr->pressedLeft() ||
			hid && (hid->ButtonPressed(HID::LeftPad_Left) ||
			((hid->AxisChanged(HID::LJoyX)) && hid->AxisInput(HID::LJoyX) < 0)))
			&& cursorPositionX_ > 0 && (temp = findInColFrom(--newX)) != -1)
		{
			newY = temp;
		}
		else if ((owner_ == GameManager::NoPlayer && mngr->pressedRight() ||
			hid && (hid->ButtonPressed(HID::LeftPad_Right) ||
			((hid->AxisChanged(HID::LJoyX)) && hid->AxisInput(HID::LJoyX) > 0)))
			&& cursorPositionX_ < grid_.GetSizeX() - 1 && (temp = findInColFrom(++newX)) != -1)
		{
			newY = temp;
		}

		if (newX != cursorPositionX_ || newY != cursorPositionY_) // If the cursor moved
		{
			ChangeSelectedItem(newX, newY);
			entity_->getApp()->getAudioMngr()->playSFX(entity_->getApp()->getAssetsManager()->getSFX(AssetsManager::BOTON), false);
		}
	}
}

void NavigationController::ChangeSelectedItem(int x, int y)
{
	UIElement* ent = grid_.GetItem(cursorPositionX_, cursorPositionY_);
	ent->Deselect();
	ent = grid_.GetItem(x, y);
	ent->Select();
	cursorPositionX_ = x;
	cursorPositionY_ = y;
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

int NavigationController::findInRowFrom(int y)
{
	int i = cursorPositionX_;
	while (i >= 0 && grid_.GetItem(i, y) == nullptr) {
		--i;
	}
	if (i < 0 && cursorPositionX_ + 1 < grid_.GetSizeX()) {
		i = cursorPositionX_ + 1;
		while (i < grid_.GetSizeX() && grid_.GetItem(i, y) == nullptr) {
			++i;
		}
	}
	if (i == grid_.GetSizeX()) return -1;
	return i;
}

int NavigationController::findInColFrom(int x)
{
	int i = cursorPositionY_;
	while (i >= 0 && grid_.GetItem(x, i) == nullptr) {
		--i;
	}
	if (i < 0 && x + 1 < grid_.GetSizeY()) {
		i = cursorPositionY_ + 1;
		while (i < grid_.GetSizeY() && grid_.GetItem(x, i) == nullptr) {
			++i;
		}
	}
	if (i == grid_.GetSizeY()) return -1;
	return i;
}
