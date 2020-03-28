#pragma once
#include "Component.h"
#include "Transform.h"

using CallbackOnDrag = void(App * app);
using CallbackOnValueChanged = void(App * app, double value);

class Slider :
	public Component
{
public:
	//constructor
	Slider(double minValue, double maxValue, int steps = 10);
	Slider(double minValue, double maxValue, int steps, CallbackOnValueChanged* valueChanged, CallbackOnDrag* startDrag = nullptr, CallbackOnDrag endDrag = nullptr);
	
	//destructor
	virtual ~Slider();

	//set different parameters
	inline void setCallbackOnStartDrag(CallbackOnDrag* callback) {startDrag_ = callback;}
	inline void setCallbackOnEndDrag(CallbackOnDrag* callback) { endDrag_ = callback;}
	inline void setCallbackOnValueChanged(CallbackOnValueChanged* callback) { valueChanged_ = callback;}
	inline void setSteps(int steps) { steps_ = steps;}
	inline void setMinValue(int minValue) { minValue_ = minValue;}
	inline void setMaxValue(int maxValue) { maxValue_ = maxValue;}
	void setValue(double newValue);

	//methods overrided from Component
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;

	//different get 
	double getValue() { return value_; }
	double getMinValue() { return minValue_; }
	double getMaxValue() { return maxValue_; }
	int getSteps() { return steps_; }

	
protected:
	Transform* transform_=nullptr;

	CallbackOnDrag* startDrag_ = nullptr;
	CallbackOnDrag* endDrag_ = nullptr;
	CallbackOnValueChanged* valueChanged_ = nullptr;

	bool dragging_ = false;
	double minValue_, maxValue_, value_ = 0;
	int steps_=0; // if steps < 1, continuous
	
	bool isMouseOver();

	virtual void dragValue();
	virtual void setValueOnClick();
};