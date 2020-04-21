#pragma once
#include "Component.h"
#include "Vector2D.h"
#include "AnimationChain.h"
#include "Ability.h"
#include "PhysicsTransform.h"
//Podemos tener todos los datos en un .json o un .txt
//Tener un método para parsear y rellenar el attackData

class PlayerData : public Component {

	//hacer luego getters y setters
public:
	//PlayerData() : Component(ecs::PlayerData) {}
	PlayerData(std::vector<SDL_Scancode> keys, double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, Vector2D speed, double ini_health, double attack, double defense, int playerNumber);
	virtual double* getWidth() {
		return width_;
	}
	virtual void setWidth(double* width) {
		 width_=width;
	}

	virtual double* getHeight() {
		return height_;
	}
	virtual void setHeight(double* height) {
		 height_= height;
	}

	virtual double* getRotation() {
		return rotation_;
	}
	virtual void setRotation(double* rotation) {
		 rotation_=rotation;
	}

	virtual double* getJumpImpulse() {
		return jump_impulse_;
	}
	virtual void setJumpImpulse(double* jump) {
		 jump_impulse_=jump;
	}

	virtual double* getHealth() {
		return health_;
	}
	virtual void setHealth(double* health) {
		 health_= health;
	}

	virtual double getAttack() {
		return attack_;
	}
	virtual void setAttack(double attack) {
		attack_ = attack;
	}

	virtual double geDefense() {
		return defense_;
	}
	virtual void setDefense(double defense) {
		defense_ = defense;
	}

	virtual Vector2D* getSpeed() {
		return speed_;
	}
	virtual void setSpeed(Vector2D* speed) {
		 speed_=speed;
	}

	virtual Vector2D getInitial_Position() {
		return initial_position_;
	}
	virtual void setInit_Position(Vector2D initial_position) {
		initial_position_ = initial_position;
	}

	virtual AnimationChain* getNormal_punch() {
		return normal_punch_;
	}
	virtual void setNormal_punch(AnimationChain* normal_punch) {
		normal_punch_ = normal_punch;
	}

	virtual AnimationChain* getHard_punch() {
		return hard_punch_;
	}
	virtual void setHard_punch(AnimationChain* hard_punch) {
		hard_punch_ = hard_punch;
	}

	virtual AnimationChain* getNormal_kick() {
		return normal_kick_;
	}
	virtual void setNormal_kick(AnimationChain* normal_kick) {
		normal_kick_ = normal_kick;
	}

	virtual AnimationChain* getHard_kick() {
		return hard_kick_;
	}
	virtual void setHard_kick(AnimationChain* hard_kick) {
		hard_kick_ = hard_kick;
	}

	
	virtual AnimationChain* air_normal_punch() {
		return air_normal_punch_;
	}
	virtual void setAir_normal_punch(AnimationChain* air_normal_punch) {
		air_normal_punch_ = air_normal_punch;
	}

	virtual AnimationChain* air_hard_punch() {
		return air_hard_punch_;
	}
	virtual void setAir_hard_punch(AnimationChain* air_hard_punch) {
		air_hard_punch_ = air_hard_punch;
	}

	virtual AnimationChain* air_normal_kick() {
		return air_normal_kick_;
	}
	virtual void setAir_normal_kick(AnimationChain* air_normal_kick) {
		air_normal_kick_ = air_normal_kick;
	}

	virtual AnimationChain* air_hard_kick() {
		return air_hard_kick_;
	}
	virtual void setAir_hard_kick(AnimationChain* air_hard_kick) {
		air_hard_kick_ = air_hard_kick;
	}

	virtual AnimationChain* guard_breaker() {
		return guard_breaker_;
	}
	virtual void setGuard_reaker(AnimationChain* guard_breaker) {
		guard_breaker_ = guard_breaker;
	}

	virtual Ability* ability_1() {
		return ability_1_;
	}
	virtual void setAbility1(Ability* ability_1) {
		ability_1_ = ability_1;
	}

	virtual Ability* ability_2() {
		return ability_2_;
	}
	virtual void setAbility2(Ability* ability_2) {
		ability_2_ = ability_2;
	}
	virtual int getPlayerNumber() {
		return playerNumber_;
	}
	virtual ~PlayerData() {}
	
protected:

	//NO ME GUSTA ASÍ PERO NO SÉ CÓMO HACERLO SI NO
	/*int width = 35;
	int hitboxX = 20;
	if (orientation_ == -1) hitboxX += width;

	ent->getApp()->getHitboxMng()->addHitbox({ (double)orientation_ * hitboxX,-75 }, width, 75, 20, 9, 42, { (double)orientation_ * 10, -50 }, pT->getBody(), pT->getCategory(), pT->getMask());*/
	struct CallbackData {
		Vector2D position,
			knockBack;
		int width,
			height,
			time,
			damage,
			hitstun;
	};
	//Control Keys
	SDL_Scancode leftKey_, righKey_, jumpKey_, crouchKey_, guardKey_,
				 normalPunchKey_, hardPunchKey_, normalKickKey_, hardKickKey_, ability1Key_, ability2Key_;
	//Player Features
	double* width_,
			*height_,
			*rotation_,
			*jump_impulse_,
			*health_;
	//Player Stats
	Vector2D initial_position_,
			 *speed_;
	double 	attack_,
			defense_;

	//Attacks
	//Normal Punch 
	AnimationChain* normal_punch_;
	//Hard Punch
	AnimationChain* hard_punch_;
	//Normal Kick
	AnimationChain* normal_kick_;
	//Hard Kick
	AnimationChain* hard_kick_;
	//Air Normal Punch 
	AnimationChain* air_normal_punch_;
	//Air Hard Punch 
	AnimationChain* air_hard_punch_;
	//Air Normal Kick
	AnimationChain* air_normal_kick_;
	//Air Hard Kick
	AnimationChain* air_hard_kick_;
	//Guard Breaker
	AnimationChain* guard_breaker_;

	//Abilities
	Ability* ability_1_;
	Ability* ability_2_;

	//To generate hitboxes easily
	PhysicsTransform* pT;
	b2Filter mask;

	// Either player 1 or 2 (0 or 1)
	int playerNumber_;
};