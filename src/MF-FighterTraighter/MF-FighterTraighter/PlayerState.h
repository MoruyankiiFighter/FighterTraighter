#pragma once
#include "Component.h"

enum Status {
	Idle,
	Moving,
	JumpingTransition,
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
	GuardingTransition,
	Guarding,
	GuardingLeaving,
	Guardbreaking,
	Dead,
};

class  PlayerState : public Component
{
public:
	PlayerState() : Component(ecs::PlayerState), playerStatus_(Idle) {};
	~PlayerState() {};

	//POSITION CHECK
	bool isGrounded() { return playerStatus_ != Jumping && playerStatus_ != AttackingAir && playerStatus_ != HitAirborne && playerStatus_ != JumpingTransition; };

	//IDLE
	void goIdle() { playerStatus_ = Idle; };
	bool isIdle() { return playerStatus_ == Idle; };

	//MOVEMENT
	bool isMoving() { return playerStatus_ == Moving; };
	bool isAbletoMove() { return playerStatus_ == Idle || playerStatus_ == Moving || playerStatus_ == Jumping; };
	void goMoving() { playerStatus_ = Moving; };

	//CROUCHING
	void goCrouch() { playerStatus_ = Crouching; };
	bool canCrouch() { return playerStatus_ == Idle || playerStatus_ == Moving; };
	bool isCrouch() { return playerStatus_ == Crouching; };

	//ATTACKING
	bool isAttacking() { return playerStatus_ == Attacking || playerStatus_ == AttackingAir || playerStatus_ == AttackingCrouch; };
	bool isAbleToAttack() { return (playerStatus_ == Idle) || (playerStatus_ == Jumping) || (playerStatus_ == Crouching) || (playerStatus_ == Moving); }; //Y si te est�s moviendo? Deber�a pararte...
	void goAttack(){
		if (playerStatus_ == Jumping)  playerStatus_ = AttackingAir;
		else if (playerStatus_ == Crouching) playerStatus_ = AttackingCrouch;
		else playerStatus_ = Attacking;
	}

	//JUMPING
	void goJumping() { playerStatus_ = Jumping; };
	void goJumpingTrans( int frames ) { playerStatus_ = JumpingTransition; holdingFrames_ = frames; };
	bool isJumpingTrans() { return playerStatus_ == JumpingTransition; }
	bool isJumping() { return playerStatus_ == Jumping || playerStatus_ == AttackingAir; };
	bool canJump() { return playerStatus_ == Idle || playerStatus_ == Crouching || playerStatus_ == Moving; }

	//LANDING
	void goLanding(int frames) {
		playerStatus_ = Landing;
		holdingFrames_ = frames;
	}

	//GUARDING
	bool canGuard() {
		return playerStatus_ == Idle || playerStatus_ == Moving || playerStatus_ == Crouching;
	}
	void goGuarding() {
		playerStatus_ = Guarding;
	}
	void goGuardingTransition(int frames) {
		playerStatus_ = GuardingTransition;
		holdingFrames_ = frames;
	}
	void goGuardingLeaving(int frames) {
		playerStatus_ = GuardingLeaving;
		holdingFrames_ = frames;
	}
	bool isGuarding() {
		return playerStatus_ == Guarding;
	}
	bool isGuardingTransition() {
		return playerStatus_ == GuardingTransition;
	}
	bool isGuardingLeaving() {
		return playerStatus_ == GuardingLeaving;
	}

	//Update
	virtual void update() override {
		if (holdingFrames_ > 0) {
			holdingFrames_--;
		}else if (holdingFrames_ == 0) {
			holdingFrames_ = -1;
			if (isGuardingTransition()) goGuarding();
			else if (isGrounded() || isGuardingLeaving()) goIdle();
			else if (isJumpingTrans()) goJumping();
			else goJumping();
		}
	};

private:
	Status playerStatus_;
	int holdingFrames_ = -1;
};
