#pragma once
#include "Slider.h"
class VerticalSlider :
	public Slider
{
public:
	VerticalSlider(double minValue, double maxValue);
	VerticalSlider(double minValue, double maxValue, CallbackOnValueChanged* valueChanged, CallbackOnStartDrag* startDrag = nullptr, CallbackOnEndDrag endDrag = nullptr);

	virtual ~VerticalSlider();
protected:
	virtual void dragValue();
	virtual void setValueOnClick();
};

