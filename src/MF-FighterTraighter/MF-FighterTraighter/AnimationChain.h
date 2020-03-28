#pragma once
#include "Move.h"

class AnimationChain
{
public:
	AnimationChain(vector<Move*> chain) : chain_(chain) {};
	~AnimationChain() {
		cout << "DESTRUYENDO ANIMATION CHAIN" << endl;
		for (int i = 0; i < chain_.size(); i++) {
			delete chain_[i];
			chain_[i] = nullptr;
		}
	};
	bool update();
private:
	vector<Move*> chain_;
	int index_ = 0;
};

