#include "AbilitiesTimerFunction.h"
#include "PlayerAttacks.h"

//void AbilitiesTimerFunction::init()
//{
//	timeab0 = pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(0);
//	timeab1 = pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(0);
//}

void AbilitiesTimerFunction::update(){
	/*if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(0) <= 0) {
		updateTimerAb(0, 10000);
	}
	if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(1) <= 0) {
		updateTimerAb(1, 17000);
	}*/
	//int auxtimeab0 = pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(0);
	if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(0) > 0) {
		updateTimerAb(0, pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getTimeCool() * 10);
	}

	//int auxtimeab1 = pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(1);

	if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(1) <= 0) {
		updateTimerAb(1, timeab1 * 10);
	}
	
	
}

void AbilitiesTimerFunction::updateTimerAb(int index, int time) {
	if (index == 0) { 
		timer1_->resumeTimer(); timer1_->setCountdown(time); timer1_->setInvisible(false);  }
	else if (index == 1) { timer2_->resumeTimer(); timer2_->setInvisible(false); timer2_->setCountdown(time); }
}
void AbilitiesTimerFunction::setTimeAb(int ind, int cool)
{
	if (ind == 0) timeab0 = cool;
	else if (ind == 1) timeab1 = cool;
}
;