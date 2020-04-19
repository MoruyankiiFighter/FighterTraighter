#include "PlayerAnimation.h"

void PlayerAnimation::update()
{
	if (currStateInt_ != currState_->getState()) {
		activeFrame_ = 0;
		currStateInt_ = currState_->getState();
	}
	else {
		//render (currently testing)
		imgR_->setFrame(activeFrame_, currStateInt_);
		activeFrame_++;	//Should have a "velocity" in PlayerData per animation, teh number it increases each frame
	}
}
