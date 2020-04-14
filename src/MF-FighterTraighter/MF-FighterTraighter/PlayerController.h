#pragma once
#include "Component.h"
#include "PhysicsTransform.h"

class PlayerController :
	public Component
{
public:
	PlayerController(SDL_Scancode left, SDL_Scancode right, SDL_Scancode block, 
		float jImpulse, SDL_Scancode jumpkey,
		SDL_Scancode crouchk);
	virtual ~PlayerController();

	//methods overrided from Component
	void init() override;
	void handleInput() override; // separate into two?
	void update() override;
	void crouch();
	void uncrouch();
	float getJumpImpulse() { return jumpImpulse; }
	void wallLeft(bool collision) {
		wallLeft_ = collision;
	}
	void wallRight(bool collision) {
		wallRight_ = collision;
	}
private:
	PhysicsTransform* transform_ = nullptr;
	SDL_Scancode left_, right_, block_;
	Vector2D dir_;
	bool wallLeft_=false, wallRight_ = false;
	SDL_Scancode jumpKey_;
	float jumpImpulse = 0;

	SDL_Scancode crouchKey_;
};