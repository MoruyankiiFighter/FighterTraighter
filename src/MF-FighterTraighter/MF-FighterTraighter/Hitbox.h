#pragma once
#include "Vector2D.h"
#include "Box2D/Box2D.h" 
struct hitbox 
{
public:
	int damage_ = -1,
		time_ = -1;
	Vector2D knockBack_; //Assuming looking to the right
};

