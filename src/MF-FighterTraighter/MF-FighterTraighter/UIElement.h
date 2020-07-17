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

	UIElement(GameManager::PlayerID owner = GameManager::NoPlayer) : Component(ecs::UIElement), owner_(owner) {}

	virtual void Press() {};
	virtual void Select() {};
	virtual void Disable() {};
	virtual void Deselect() {};

	Entity* getEntity() { return this->entity_; }
	inline virtual void setOwner(GameManager::PlayerID owner) { owner_ = owner; }

	virtual ~UIElement() {}
protected:
	State Buttonstate_ = Normal;
	GameManager::PlayerID owner_;
};

