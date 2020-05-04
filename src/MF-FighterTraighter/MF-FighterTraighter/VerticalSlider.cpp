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
	if (state_ == Selected) {
		if (app_->getInputManager()->pressedUp()) {
			if (steps_ > 1) {
				setValue(value_ + (maxValue_ - minValue_) / steps_);
			}
			else {
				setValue(value_ + 1);
			}
		}
		else if (app_->getInputManager()->pressedDown()) {
			if (steps_ > 1) {
				setValue(value_ - (maxValue_ - minValue_) / steps_);
			}
			else {
				setValue(value_ - 1);
			}
		}
	}
}
