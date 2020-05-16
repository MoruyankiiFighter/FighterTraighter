#include "SacoManager.h"
#include "PunchingBagOnHit.h"

void SacoManager::init() {

	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);

	startTime_ = SDL_GetTicks();

	PunchingBagInteraction rndInter = (PunchingBagInteraction)app_->getRandGen()->nextInt(0,_last_interaction);
	
	switch (rndInter)
	{
	case LAST_HIT:
		transform_->resetUserData(new PunchingBagOnHit(entity_));
		break;
	case MORE_DAMAGE:
		transform_->resetUserData(new PunchingBagOnHit(entity_));	//este seria diferente
		break;
	default:
		break;
	}
}

//updates the punchingBag time limit
void SacoManager::update() {
	currTime_ = SDL_GetTicks() - startTime_;
	if (currTime_ > timeLimit_) { 
		std::cout << "Tiempo acabado" << endl; 
		app_->getGameManager()->trainingEnded(0);
	}
}