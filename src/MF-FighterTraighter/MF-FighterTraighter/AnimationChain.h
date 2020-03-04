#pragma once
#include "Move.h"

class AnimationChain
{
	AnimationChain(vector<Move> chain) : chain_(chain) {};
	~AnimationChain() {};
	void update();
private:
	vector<Move> chain_;
	int index_ = 0;
};

