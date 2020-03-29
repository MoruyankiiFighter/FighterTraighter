#pragma once
#include "Component.h"
#include "Transform.h"

class PlayerController :
	public Component
{
public:
	PlayerController(SDL_Scancode left, SDL_Scancode right);
	virtual ~PlayerController();

	//methods overrided from Component
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
private:
	Transform* transform_=nullptr;
	SDL_Scancode left_, right_;
	Vector2D dir_;
};