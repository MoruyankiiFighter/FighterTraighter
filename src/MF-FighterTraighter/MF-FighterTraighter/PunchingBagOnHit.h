#pragma once
#include "OnHit.h"
#include <iostream>
class PunchingBagOnHit : public OnHit
{
public:
	PunchingBagOnHit() : OnHit() {}
	~PunchingBagOnHit() {}
	void onHit() override {
		std::cout << "Soy un saco" << std::endl;
	}
};

