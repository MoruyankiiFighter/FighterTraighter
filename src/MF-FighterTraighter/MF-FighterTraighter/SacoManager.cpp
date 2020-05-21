#include "SacoManager.h"
#include "LastHit_Wins.h"
#include "MoreDamage_Wins.h"
#include "TrainingController.h"

void SacoManager::init() {

	transform_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);

	PunchingBagInteraction rndInter = (PunchingBagInteraction)app_->getRandGen()->nextInt(0,_last_interaction);
	PunchingBagOnHit* pb = nullptr;
	switch (rndInter)
	{
	case LAST_HIT:
		pb = new LastHit_Wins(entity_, "¡Da el ultimo golpe!");
		transform_->resetUserData(pb);
		infoText = "¡Da el ultimo golpe!";
		break;
	case MORE_DAMAGE:
		pb = new MoreDamage_Wins(entity_, "¡Daña el saco!");
		transform_->resetUserData(pb);	//este seria diferente
		infoText = "¡Daña el saco!";
		break;
	default:
		pb = nullptr;
		break;
	}

	//entity_->getState()->getEntityManager().getHandler(ecs::Controller)->getComponent<TrainingController>(ecs::TrainingController)->setIniText(pb->getInfoMessage());
	
}

//updates the punchingBag time limit
void SacoManager::update() {
	if (timerOn) {
		currTime_ = SDL_GetTicks() - startTime_;
		if (currTime_ > timeLimit_) {
			int winner = (static_cast<PunchingBagOnHit*>(entity_->getComponent<PhysicsTransform>(ecs::Transform)->getUserData()))->timeout_Winner();
			entity_->getState()->getEntityManager().getHandler(ecs::Controller)->getComponent<TrainingController>(ecs::TrainingController)->PlayerWins(winner);
		}
	}
}

void SacoManager::startTimer() {
	timerOn = true;
	startTime_ = SDL_GetTicks();
	//instanciar el timer en pantalla
	Entity* timer = state_->getEntityManager().addEntity();
	timer->addComponent<UITransform>(Vector2D(0, 120), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(200, 50), Vector2D(400, 100));
	timer->addComponent<TextComponent>("0000", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 45, TextComponent::Center);
	timer->addComponent<UITimer>(UITimer::Seconds)->setCountdown(timeLimit_);
}