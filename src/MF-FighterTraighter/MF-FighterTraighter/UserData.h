#pragma once
//A class to handle bodies / fixtures userData with inheritance
#include "Box2D/Box2D.h"
class UserData
{
public:
	virtual ~UserData() {}
	virtual void onHit(b2Fixture* other) {}
};

