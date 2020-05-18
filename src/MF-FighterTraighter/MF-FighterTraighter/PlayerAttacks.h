#pragma once
#include "HID.h"
#include "CharacterAttacks.h"

//component that have all the attacks that you have
class PlayerAttacks : public CharacterAttacks
{
public:	
	PlayerAttacks(HID* hid, AnimationChain* highFist, AnimationChain* airHighFist, AnimationChain* lowFist, AnimationChain* airLowFist,
		AnimationChain* highKick, AnimationChain* airHighKick, AnimationChain* lowKick, AnimationChain* airLowKick, AnimationChain* testGB);
	virtual ~PlayerAttacks() {};
	virtual void handleInput();
private:
	HID* inputSt_;
};

