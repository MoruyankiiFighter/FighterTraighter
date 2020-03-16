#include "VerticalSlider.h"

VerticalSlider::VerticalSlider(double minValue, double maxValue): Slider(minValue, maxValue)
{
}

VerticalSlider::VerticalSlider(double minValue, double maxValue, CallbackOnValueChanged* valueChanged, CallbackOnStartDrag* startDrag, CallbackOnEndDrag endDrag)
	: Slider(minValue, maxValue, valueChanged, startDrag, endDrag)
{
}

VerticalSlider::~VerticalSlider()
{
}

void VerticalSlider::dragValue()
{
	InputManager* input = app_->getInputManager();
	Vector2D mouseMovement = input->getMouseMovement();
	if (mouseMovement.getY() != 0) {
		setValue(value_ + mouseMovement.getY() / tr_->getHeight() * (maxValue_ - minValue_));
	}
}

void VerticalSlider::setValueOnClick()
{
	value_ = (app_->getInputManager()->getMousePosY() - tr_->getPosition().getY()) / tr_->getHeight() * (maxValue_ - minValue_);
}
