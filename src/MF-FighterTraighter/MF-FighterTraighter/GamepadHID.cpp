#include "GamepadHID.h"

void GamepadHID::updateInput()
{
	lastButtonState = curbuttonState;

	//Start = 1,
	short state = inputM_->isControllerButtonHeld(gamepadID, buttons[0]);
	//Select = 2,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[1]) << 1;
	//LeftPad_Left = 4,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[2]) << 2;
	//LeftPad_Up = 8,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[3]) << 3;
	//LeftPad_Right = 16,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[4]) << 4;
	//LeftPad_Down = 32,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[5]) << 5;
	//RightPad_Left = 64,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[6]) << 6;
	//RightPad_Up = 128,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[7]) << 7;
	//RightPad_Right = 256,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[8]) << 8;
	//RightPad_Down = 512,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[9]) << 9;
	//LeftBumper = 1024,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[10]) << 10;
	//RightBumper = 2048,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[11]) << 11;
	//LeftJoystickClick = 4096,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[12]) << 12;
	//RightJoystickClick = 8192
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[13]) << 13;
	curbuttonState = state;

	lastAxesState = curAxesState;
	char Xstate = 0;
	//LJoyX = 0,
	if ((axes[0] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[0]))) != 0) Xstate |= 1;
	//LJoyY,
	if ((axes[1] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[1]))) != 0) Xstate |= 1 << 1;
	//RJoyX,
	if ((axes[2] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[2]))) != 0) Xstate |= 1 << 2;
	//RJoyY,
	if ((axes[3] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[3]))) != 0) Xstate |= 1 << 3;
	//LTrigger,
	if ((axes[4] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[4]))) != 0) Xstate |= 1 << 4;
	//RTrigger,
	if ((axes[5] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[5]))) != 0) Xstate |= 1 << 5;
	curAxesState = Xstate;
}
