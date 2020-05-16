#include "SacoTimer.h"

void SacoTimer::init() {
	startTime_ = SDL_GetTicks();
}

//updates the punchingBag time limit
void SacoTimer::update() {
	currTime_ = SDL_GetTicks() - startTime_;
	if (currTime_ > timeLimit_) 
		std::cout << "Tiempo acabado" << endl;
}