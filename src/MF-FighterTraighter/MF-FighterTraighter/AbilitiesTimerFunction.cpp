#include "AbilitiesTimerFunction.h"
#include "PlayerAttacks.h"

void AbilitiesTimerFunction::update(){
	if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(0) > 0 && pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->isTimeActive(0)) {
		updateTimerAb(0, (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getTimeCool(0) / 60) * 1000);
		pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->activateTimer(0, false);
	}

	if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(1) > 0 && pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->isTimeActive(1)) {
		updateTimerAb(1, (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getTimeCool(1) / 60) * 1000);
		pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->activateTimer(1, false);
	}
}

void AbilitiesTimerFunction::updateTimerAb(int index, int time) {
	if (index == 0) {
		timer1_->resumeTimer(); timer1_->setInvisible(false); timer1_->setCountdown(time);
	}
	else if (index == 1) { timer2_->resumeTimer(); timer2_->setInvisible(false); timer2_->setCountdown(time); }
}

;