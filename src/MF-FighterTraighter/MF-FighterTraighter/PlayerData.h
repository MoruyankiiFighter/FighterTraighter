#pragma once
#include "Component.h"
#include "Vector2D.h"
#include "AnimationChain.h"
#include "Ability.h"
#include "PhysicsTransform.h"
//Podemos tener todos los datos en un .json o un .txt
//Tener un m�todo para parsear y rellenar el attackData

class PlayerData : public Component {

	//hacer luego getters y setters
public:
	//PlayerData() : Component(ecs::PlayerData) {}
	PlayerData(std::vector<SDL_Scancode> keys, double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, Vector2D* speed, double ini_health, double attack, double defense);
	virtual double* getWidth() {
		return width_;
	}
	virtual double* getWidth() {
		return width_;
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
	virtual double* getRotation() {
		return rotation_;
	}
	virtual double* getJumpImpulse() {
		return jump_impulse_;
	}
	virtual double* getJumpImpulse() {
		return jump_impulse_;
	}
	virtual double* getHealth() {
		return health_;
	}
	virtual void setHealth(double* health) {
		 health_= health;
	}
	virtual Vector2D* getSpeed() {
		return speed_;
	}
	virtual Vector2D* getSpeed() {
		return speed_;
	}
	virtual ~PlayerData() {}
	
protected:
	//Control Keys
	SDL_Scancode leftKey_, righKey_, jumpKey_, crouchKey_, guardKey_,
				 normalPunchKey_, hardPunchKey_, normalKickKey_, hardKickKey_, ability1Key_, ability2Key_;
	//Player Features
	double *width_,
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
	AnimationChain* guard_breaker;

	//Abilities
	Ability* ability_1;
	Ability* ability_2;
};