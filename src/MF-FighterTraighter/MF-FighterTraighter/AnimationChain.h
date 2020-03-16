#pragma once
#include "Move.h"

class AnimationChain
{
public:
	//constructor
	AnimationChain(vector<Move*> chain) : chain_(chain) {};
	//destructor
	~AnimationChain() {
		cout << "DESTRUYENDO ANIMATION CHAIN" << endl;
		//delete chain_;
	};

	bool update();
private:
	vector<Move*> chain_;
	int index_ = 0;
};

