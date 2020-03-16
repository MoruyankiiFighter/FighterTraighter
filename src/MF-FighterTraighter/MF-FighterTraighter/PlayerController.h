#pragma once
#include "Component.h"
#include "Transform.h"

class PlayerController :
	public Component
{
public:
	PlayerController();
	virtual ~PlayerController();

	// methods overrided from component
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
private:
	Transform* transform_=nullptr;

	Vector2D direction_ = {NULL,NULL};
};

