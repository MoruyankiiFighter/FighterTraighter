#include "VerticalSlider.h"

VerticalSlider::VerticalSlider(double minValue, double maxValue): Slider(minValue, maxValue)
{
}

VerticalSlider::VerticalSlider(double minValue, double maxValue, int steps, CallbackOnValueChanged* valueChanged, CallbackOnDrag* startDrag, CallbackOnDrag endDrag)
	: Slider(minValue, maxValue, steps, valueChanged, startDrag, endDrag)
{
}

VerticalSlider::~VerticalSlider()
{
}

void VerticalSlider::dragValue()
{
	InputManager* input = app_->getInputManager();
	Vector2D mouseMovement = input->getMouseMovement();
	Vector2D mousePos = input->getMousePos();
	if (mouseMovement.getY() != 0 && mousePos.getY() >= tr_->getPosition().getY() && mousePos.getY() <= tr_->getPosition().getY() + tr_->getHeight() * tr_->getHMult()) {
		setValueOnClick();
	}
}

void VerticalSlider::setValueOnClick()
{
	double a = (value_ + app_->getInputManager()->getMousePosY() - tr_->getPosition().getY()) / tr_->getHeight() * tr_->getHMult() * (maxValue_ - minValue_) + minValue_;
	setValue(a);
}
