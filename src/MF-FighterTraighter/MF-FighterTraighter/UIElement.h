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

	UIElement() : Component(ecs::UIElement) {}

	virtual void Press() = 0;
	virtual void Select() = 0;
	virtual void Disable() = 0;
	virtual void Deselect() = 0;

	virtual ~UIElement() {}
protected:
	State Buttonstate_ = Normal;
};

