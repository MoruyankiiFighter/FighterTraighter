#pragma once
#include "OnHit.h"
#include <iostream>

class FloorOnHit : public OnHit
{
public:
	FloorOnHit() : OnHit() {}
	~FloorOnHit() {}
	void onHit(b2Fixture* fixture, b2Fixture* mainfixture) override {
		std::cout << "Soy suelo" << std::endl;
	}
};
