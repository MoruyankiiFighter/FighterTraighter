#pragma once
#include "Component.h"

enum Status {
	Idle,
	Jumping,
	Crouching,
	Attacking,
	AttackingAir,
	Hit,
	HitAirborne,
	Landing,
	//HitLading,
	//KnockedTheFuckDown,
	Stunned,
	Guarding,
	Guardbreaking,
	Dead,
};

class  PlayerState : public Component
{
public:
	PlayerState() : Component(ecs::PlayerState), playerStatus_(Status::Idle) {};
	~PlayerState() {};

	void goIdle() { playerStatus_ == Status::Idle; };
	bool isIdle() { return playerStatus_ == Status::Idle; };
private:
	Status playerStatus_;
};
