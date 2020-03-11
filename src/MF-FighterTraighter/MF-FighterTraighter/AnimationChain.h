#pragma once
#include "Move.h"

class AnimationChain
{
public:
	AnimationChain(vector<Move*> chain) : chain_(chain) {};
	~AnimationChain() {
		cout << "DESTRUYENDO ANIMATION CHAIN" << endl;
		//delete chain_;
	};
	bool update();
private:
	vector<Move*> chain_;
	int index_ = 0;
};

