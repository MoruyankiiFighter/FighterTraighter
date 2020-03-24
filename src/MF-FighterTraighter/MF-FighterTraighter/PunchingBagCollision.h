#pragma once
#include "Component.h"
#include <iostream>
class PunchingBagCollision : public Component
{
public:
	//constructor
	PunchingBagCollision() : Component(ecs::PunchingBagCollision) {}
	//destructor
	~PunchingBagCollision() {}

	//on collision
	void OnCollision() {std::cout << "soy un saco" << std::endl;}
};

