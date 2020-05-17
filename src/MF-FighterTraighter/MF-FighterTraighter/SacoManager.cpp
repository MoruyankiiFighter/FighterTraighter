#include "SacoManager.h"
#include "LastHit_Wins.h"
#include "MoreDamage_Wins.h"
void SacoManager::init() {

	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);

	PunchingBagInteraction rndInter = (PunchingBagInteraction)app_->getRandGen()->nextInt(0,_last_interaction);
	
	switch (rndInter)
	{
	case LAST_HIT:
		transform_->resetUserData(new LastHit_Wins(entity_));
		break;
	case MORE_DAMAGE:
		transform_->resetUserData(new MoreDamage_Wins(entity_));	//este seria diferente
		break;
	default:
		break;
	}

	startTime_ = SDL_GetTicks();
}

//updates the punchingBag time limit
void SacoManager::update() {
	currTime_ = SDL_GetTicks() - startTime_;
	if (currTime_ > timeLimit_) { 
		std::cout << "Tiempo acabado" << endl; 
		int winner = (static_cast<PunchingBagOnHit*>(entity_->getComponent<PhysicsTransform>(ecs::Transform)->getUserData()))->timeout_Winner();
		app_->getGameManager()->trainingEnded(winner);
	}
}