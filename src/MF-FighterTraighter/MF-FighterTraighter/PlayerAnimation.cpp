#include "PlayerAnimation.h"

void PlayerAnimation::update()
{
	if (currStateInt_ != currState_->getState()) {
		activeFrame_ = 0;
		timeSinceLastIncrement_ = 0;
		currStateInt_ = currState_->getState();
	}
	else {
		//render (currently testing)
		imgR_->setFrame(activeFrame_, currStateInt_);
		timeSinceLastIncrement_++;
		if (timeSinceLastIncrement_ >= 15) {	//Every 15 frames
			activeFrame_ = (activeFrame_ + 1) % 15;	//Should have a "velocity" in PlayerData per animation, teh number it increases each frame, now it's hardcoded but works
			timeSinceLastIncrement_ = 0;
		}
	}
}
