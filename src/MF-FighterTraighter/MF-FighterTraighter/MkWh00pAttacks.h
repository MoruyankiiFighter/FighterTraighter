#pragma once
#include <vector>
#include "AnimationChain.h"

//Al parecer a esto no le da la gana funcionar as� que genial

namespace Mk {
	std::vector<Move*> vecNormalPunch = { new Move(25, nullptr), new Move(100, nullptr) }; //Ser�a el incio que crea la hitbox y el golpe
	AnimationChain* normalPunch = new AnimationChain(vecNormalPunch);
};