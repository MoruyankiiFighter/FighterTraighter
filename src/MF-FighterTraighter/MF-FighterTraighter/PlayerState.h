#pragma once
#include "Component.h"

enum Status {
	Idle,
	Jumping,
	Crouching,
	Attacking,
	AttackingAir,
	AttackingCrouch,
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

	void goIdle() { playerStatus_ = Status::Idle; };
	bool isIdle() { return playerStatus_ == Status::Idle; };

	bool isAbleToAttack() { return (playerStatus_ == Status::Idle) || (playerStatus_ == Status::Jumping) || (playerStatus_ == Status::Crouching); };
	void goAttack(){
		if (playerStatus_ == Jumping)  playerStatus_ = AttackingAir;
		else if (playerStatus_ == Crouching) playerStatus_ = AttackingCrouch;
		else playerStatus_ = Attacking;
	}

private:
	Status playerStatus_;
};
