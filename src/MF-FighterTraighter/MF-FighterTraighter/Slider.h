#pragma once
#include "Component.h"
#include "Transform.h"

using CallbackOnDrag = void(App * app);
using CallbackOnValueChanged = void(App * app, double value);

class Slider :
	public Component
{
public:
	Slider(double minValue, double maxValue, int steps = 10);
	Slider(double minValue, double maxValue, int steps, CallbackOnValueChanged* valueChanged, CallbackOnDrag* startDrag = nullptr, CallbackOnDrag endDrag = nullptr);

	inline void setCallbackOnStartDrag(CallbackOnDrag* callback) {
		startDrag_ = callback;
	}
	inline void setCallbackOnEndDrag(CallbackOnDrag* callback) {
		endDrag_ = callback;
	}
	inline void setCallbackOnValueChanged(CallbackOnValueChanged* callback) {
		valueChanged_ = callback;
	}

	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;

	void setValue(double newValue);

	virtual ~Slider();
protected:
	Transform* tr_;
	bool dragging_ = false;
	double value_ = 0;
	double minValue_, maxValue_;
	int steps_; // if steps < 1, continuous
	CallbackOnDrag* startDrag_ = nullptr;
	CallbackOnDrag* endDrag_ = nullptr;
	CallbackOnValueChanged* valueChanged_ = nullptr;

	virtual void dragValue();
	bool isMouseOver();
	virtual void setValueOnClick();
};