#pragma once
#include "OnHit.h"
#include <iostream>

class FloorOnHit : public OnHit
{
public:
	FloorOnHit() : OnHit() {}
	~FloorOnHit() {}
	void onHit(b2Fixture* fixture) override {
		std::cout << "Soy suelo" << std::endl;
	}
};
