#include "AnimationChain.h"

void AnimationChain::update()
{
	if (chain_[index_].update()) {
		index_++;
	}
	if (index_ > chain_.size()) {
		//Move finished boi!!! I die boy shit boiii!!
	}
}
