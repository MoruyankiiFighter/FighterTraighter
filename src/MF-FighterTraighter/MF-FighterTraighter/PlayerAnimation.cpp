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
		if (timeSinceLastIncrement_ >= data_->getAnimVelocity(currStateInt_)) {	
			activeFrame_ = (activeFrame_ + 1) % data_->getAnimLength(currStateInt_);	//Should have a "velocity" in PlayerData per animation, 
			timeSinceLastIncrement_ = 0;												//the number it increases each frame, now it's hardcoded but works
			//if (!data_->getAnimLoops(currStateInt_)) currStateInt_ = 0;				//No idea how to handle looping, I suppose it just does but on attacks ends before it
		}
	}
}
