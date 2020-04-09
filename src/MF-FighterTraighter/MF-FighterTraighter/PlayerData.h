#pragma once
#include "Component.h"
#include "Vector2D.h"
#include "AnimationChain.h"
#include "Ability.h"
//Podemos tener todos los datos en un .json o un .txt
//Tener un método para parsear y rellenar el attackData

struct AttackCallbackData {
	Vector2D pos_,
			 knockback;
	int width_,
		height,
		lifeTime_,
		damage_,
		hitstunTime_;
};
class PlayerData : public Component {

	//hacer luego getters y setters
public:
	PlayerData() : Component(ecs::PlayerData) {}
	PlayerData(std::vector<SDL_Scancode> keys, double width, double height, double rotation, double jump_impulse, Vector2D ini_pos, Vector2D speed, double ini_health, double attack, double defense);

	virtual ~PlayerData() {}

protected:
	//Control Keys
	SDL_Scancode leftKey_, righKey_, jumpKey_, crouchKey_, guardKey_,
				 normalPunchKey_, hardPunchKey_, normalKickKey_, hardKickKey_, ability1Key_, ability2Key_;
	//Player Features
	double  width_,
			height_,
			rotation_,
			jump_impulse_;
	//Player Stats
	Vector2D initial_position_,
			 speed_;
	double  initial_health_,
			attack_,
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