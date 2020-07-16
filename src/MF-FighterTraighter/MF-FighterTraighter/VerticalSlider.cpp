#include "VerticalSlider.h"

VerticalSlider::VerticalSlider(double minValue, double maxValue): Slider(minValue, maxValue)
{
}

VerticalSlider::VerticalSlider(double minValue, double maxValue, int steps, CallbackOnValueChanged* valueChanged)
	: Slider(minValue, maxValue, steps, valueChanged)
{
}

VerticalSlider::~VerticalSlider()
{
}

void VerticalSlider::handleInput()
{
	if (Buttonstate_ == Selected) {
		HID* hid = nullptr;
		if (owner_ != GameManager::NoPlayer)
			hid = app_->getGameManager()->getPlayerInfo(owner_).hid;
		if (owner_ == GameManager::NoPlayer && app_->getInputManager()->pressedUp() || hid && hid->ButtonPressed(HID::LeftPad_Up)) {
			if (steps_ > 1) {
				setValue(value_ + (maxValue_ - minValue_) / steps_);
			}
			else {
				setValue(value_ + 1);
			}
		}
		else if (owner_ == GameManager::NoPlayer && app_->getInputManager()->pressedDown() || hid && hid->ButtonPressed(HID::LeftPad_Down)) {
			if (steps_ > 1) {
				setValue(value_ - (maxValue_ - minValue_) / steps_);
			}
			else {
				setValue(value_ - 1);
			}
		}
	}
}
