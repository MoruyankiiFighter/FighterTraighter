#pragma once
#include "Component.h"
#include "Vector2D.h"
#include "AnimationChain.h"
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

public:
	//Control Keys
	SDL_Scancode leftKey_, righKey_, jumpKey_, crouchKey_, guardKey_,
				 highFistKey_, lowFistKey_, highKickKey_, lowKickKey_, ability1Key_, ability2Key_;
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
	int nMoves;
	vector<AttackCallbackData> atck_Data;
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
	//
};