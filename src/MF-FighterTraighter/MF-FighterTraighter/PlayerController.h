#pragma once
#include "Component.h"
#include "Transform.h"

class PlayerController :
	public Component
{
public:
	PlayerController(SDL_Scancode left, SDL_Scancode right);
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
	virtual ~PlayerController();
private:
	Transform* tr_;
	SDL_Scancode left_, right_;
	Vector2D dir_;
};

