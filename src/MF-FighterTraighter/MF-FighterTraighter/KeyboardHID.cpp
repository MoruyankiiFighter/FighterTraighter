#include "KeyboardHID.h"

void KeyboardHID::updateInput()
{
	lastButtonState = curbuttonState;

	//Start = 1,
	short state = inputM_->KeyPressed(keys_[0]);
	//Select = 2,
	state |= inputM_->KeyPressed(keys_[1]) << 1;
	//LeftPad_Left = 4,
	state |= inputM_->isKeyDown(keys_[2]) << 2;
	//LeftPad_Up = 8,
	state |= inputM_->isKeyDown(keys_[3]) << 3;
	//LeftPad_Right = 16,
	state |= inputM_->isKeyDown(keys_[4]) << 4;
	//LeftPad_Down = 32,
	state |= inputM_->isKeyDown(keys_[5]) << 5;
	//RightPad_Left = 64,
	state |= inputM_->KeyPressed(keys_[6]) << 6;
	//RightPad_Up = 128,
	state |= inputM_->KeyPressed(keys_[7]) << 7;
	//RightPad_Right = 256,
	state |= inputM_->KeyPressed(keys_[8]) << 8;
	//RightPad_Down = 512,
	state |= inputM_->KeyPressed(keys_[9]) << 9;
	//LeftBumper = 1024,
	state |= inputM_->KeyPressed(keys_[10]) << 10;
	//RightBumper = 2048,
	state |= inputM_->KeyPressed(keys_[11]) << 11;
	//LeftJoystickClick = 4096,
	state |= inputM_->KeyPressed(keys_[12]) << 12;
	//RightJoystickClick = 8192
	state |= inputM_->KeyPressed(keys_[13]) << 13;
	curbuttonState = state;

	//LJoyX = 0,
	if (inputM_->isKeyDown(keys_[14])) { // -1
		axes[0] = -1;
	}
	else if (inputM_->isKeyDown(keys_[15])) { // 1
		axes[0] = 1;
	}
	else {
		axes[0] = 0;
	}
	//LJoyY,
	if (inputM_->isKeyDown(keys_[16])) { // -1
		axes[1] = -1;
	}
	else if (inputM_->isKeyDown(keys_[17])) { // 1
		axes[1] = 1;
	}
	else {
		axes[1] = 0;
	}
	//RJoyX,
	if (inputM_->isKeyDown(keys_[18])) { // -1
		axes[2] = -1;
	}
	else if (inputM_->isKeyDown(keys_[19])) { // 1
		axes[2] = 1;
	}
	else {
		axes[2] = 0;
	}
	//RJoyY,
	if (inputM_->isKeyDown(keys_[20])) { // -1
		axes[3] = -1;
	}
	else if (inputM_->isKeyDown(keys_[21])) { // 1
		axes[3] = 1;
	}
	else {
		axes[3] = 0;
	}
	//LTrigger,
	if (inputM_->isKeyDown(keys_[22])) {
		axes[4] = 1;
	}
	else {
		axes[4] = 0;
	}
	//RTrigger,
	if (inputM_->KeyPressed(keys_[23])) {
		axes[5] = 1;
	}
	else {
		axes[5] = 0;
	}
}
