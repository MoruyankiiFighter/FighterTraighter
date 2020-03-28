#pragma once
#include "Slider.h"
class VerticalSlider :
	public Slider
{
public:
	//constructor
	VerticalSlider(double minValue, double maxValue);
	VerticalSlider(double minValue, double maxValue, int steps, CallbackOnValueChanged* valueChanged, CallbackOnDrag* startDrag = nullptr, CallbackOnDrag endDrag = nullptr);
	//destructor
	virtual ~VerticalSlider();
protected:
	virtual void dragValue();
	virtual void setValueOnClick();
};

