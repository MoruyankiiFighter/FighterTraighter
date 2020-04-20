#include "SacoTimer.h"

void SacoTimer::update() {
	currTime_ = SDL_GetTicks() - startTime_;
	if (currTime_ > timeLimit_) { 
		std::cout << "Tiempo acabado" << endl; 
		//llamar al metodo dame habilidades
		player->addAbilityInventory("Counter");
		player->addAbilityInventory("Shell Power");
	}
}
