#pragma once
#include "Component.h"
#include <iostream>
class PunchingBagCollision : public Component
{
public:
	PunchingBagCollision() : Component(ecs::PunchingBagCollision) {}
	~PunchingBagCollision() {}
	void OnCollision() {
		std::cout << "soy un saco" << std::endl;
	}
};

