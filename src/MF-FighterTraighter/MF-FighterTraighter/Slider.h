#pragma once
#include "Component.h"
#include "Transform.h"

//using CallbackOnClick = void(App * app);
using CallbackOnStartDrag = void(App * app);
using CallbackOnEndDrag = void(App * app);
using CallbackOnValueChanged = void(App * app, double value);

class Slider :
	public Component
{
public:
	Slider(double minValue, double maxValue);
	Slider(double minValue, double maxValue, CallbackOnValueChanged* valueChanged, CallbackOnStartDrag* startDrag = nullptr, CallbackOnEndDrag endDrag = nullptr);

	inline void setCallbackOnStartDrag(CallbackOnStartDrag* callback) {
		startDrag_ = callback;
	}
	inline void setCallbackOnEndDrag(CallbackOnEndDrag* callback) {
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
	CallbackOnStartDrag* startDrag_ = nullptr;
	CallbackOnEndDrag* endDrag_ = nullptr;
	CallbackOnValueChanged* valueChanged_ = nullptr;

	void dragValue();
	bool isMouseOver();
};