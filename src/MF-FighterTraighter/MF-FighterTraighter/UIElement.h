#pragma once
#include "Component.h"
#include "WindowManager.h"
#include "Vector2D.h"

class UIElement :
	public Component
{
public:
	enum State
	{
		Normal,
		Selected,
		Pressed,
		Disabled
	};

	UIElement(HID* owner = nullptr) : Component(ecs::UIElement), owner_(owner) {}

	virtual void Press() = 0;
	virtual void Select() = 0;
	virtual void Disable() = 0;
	virtual void Deselect() = 0;

	inline virtual void setOwner(HID* owner) { owner_ = owner; }

	virtual ~UIElement() {}
protected:
	State Buttonstate_ = Normal;
	HID* owner_;
};

