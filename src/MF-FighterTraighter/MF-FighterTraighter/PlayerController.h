#pragma once
#include "Component.h"
#include "Transform.h"

class PlayerController :
	public Component
{
public:
	PlayerController();
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
	virtual ~PlayerController();
private:
	Transform* tr_;

	Vector2D dir_;
};

