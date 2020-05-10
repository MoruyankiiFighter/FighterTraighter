#include "AbilitiesTimerFunction.h"
#include "PlayerAttacks.h"

void AbilitiesTimerFunction::update(){
	if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(0) <= 0) {
		updateTimerAb(0, 10000);
	}
	if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(1) <= 0) {
		updateTimerAb(1, 17000);
	}
}

void AbilitiesTimerFunction::updateTimerAb(int index, int time) {
	if (index == 0) { timer1_->resumeTimer(); timer1_->setInvisible(false); timer1_->setCountdown(time); }
	else if (index == 1) { timer2_->resumeTimer(); timer2_->setInvisible(false); timer2_->setCountdown(time); }
};