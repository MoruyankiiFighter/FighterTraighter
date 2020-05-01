#pragma once
#include "Component.h"
#include "UITimer.h"
#include "Entity.h"
#include "PlayerAttacks.h"

class AbilitiesTimerFunction:public Component
{
public:
	AbilitiesTimerFunction(UITimer* timer1, UITimer* timer2, Entity* pl) : Component(ecs::AbilitiesTimerFunction) {
		timer1_ = timer1;
		timer2_ = timer2;
		pl_ = pl;
	};
	~AbilitiesTimerFunction() {};
	void update() override {
		if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(0) == 0) {
			updateTimerAb(0, 6000);
		}
		else if (pl_->getComponent<PlayerAttacks>(ecs::PlayerAttacks)->getAbilityCooldown(1) == 0) {
			updateTimerAb(1, 6000);
		}
	}
	void updateTimerAb(int index, int time) {
		if (index == 0) { timer1_->setCountdown(time); }
		else if (index == 1) { timer2_->setCountdown(time); }
	};
private:
	UITimer* timer1_;
	UITimer* timer2_;
	Entity* pl_;
};

