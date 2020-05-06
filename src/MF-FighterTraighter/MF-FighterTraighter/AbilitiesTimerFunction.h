#pragma once
#include "Component.h"
#include "UITimer.h"
#include "Entity.h"

class AbilitiesTimerFunction:public Component
{
public:
	AbilitiesTimerFunction(HID* hid, UITimer* timer1, UITimer* timer2, Entity* pl) : Component(ecs::AbilitiesTimerFunction) {
		timer1_ = timer1;
		timer2_ = timer2;
		pl_ = pl;
	};
	~AbilitiesTimerFunction() {};
	void update() override;
	void updateTimerAb(int index, int time);
private:
	UITimer* timer1_;
	UITimer* timer2_;
	Entity* pl_;
};

