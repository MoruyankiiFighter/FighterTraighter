#include "PlayerAnimation.h"

void PlayerAnimation::update()
{
	if (currStateInt_ != currState_->getState()) {
		activeFrame_ = 0;
		currStateInt_ = currState_->getState();
	}
	else {
		//render (must change renderImage and/or Texture to be able to render a single frame in a position with a multiplier)
		spriteShit_->render({ 0, 0, 256, 256 }, currStateInt_, activeFrame_, 0);
		activeFrame_++;	//Should have a "velocity" in PlayerData per animation, teh number it increases each frame
	}
}
