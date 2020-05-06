#pragma once
#include "OnHit.h"
#include <iostream>
class PunchingBagOnHit : public OnHit
{
public:
	PunchingBagOnHit() : OnHit() {}
	~PunchingBagOnHit() {}
	void onHit(b2Fixture* fixture) override {
		std::cout << "Soy un saco" << std::endl;
	}
};

