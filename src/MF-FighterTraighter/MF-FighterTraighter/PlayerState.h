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
	PlayerState(int orient ) : Component(ecs::PlayerState), orientation_(orient), playerStatus_(Status::Idle) {};
	~PlayerState() {};

	void goIdle() { playerStatus_ == Status::Idle; };
	bool isIdle() { return playerStatus_ == Status::Idle; };
private:
	int orientation_; //1 for right, -1 for left
	Status playerStatus_;
};
