#pragma once
#include "Component.h"
#include "Transform.h"

class PlayerController :
	public Component
{
public:
	//constructor
	PlayerController();
	//destructor
	virtual ~PlayerController();
	
	//methods overrided from Component
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
private:
	Transform* physics_transform;

	Vector2D dir_;
};

