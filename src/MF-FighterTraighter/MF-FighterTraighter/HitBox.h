#pragma once
#include "Component.h"
class Hitbox : public Component
{
public:
	Hitbox(Vector2D pos, Vector2D vel, int width, int height, int numFrames);
	~Hitbox() {}
private:
	int pos_;
};

