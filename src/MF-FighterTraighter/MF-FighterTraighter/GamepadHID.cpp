#include "GamepadHID.h"

void GamepadHID::updateInput()
{
	lastButtonState = curbuttonState;

	//Start = 1,
	short state = inputM_->isControllerButtonPressed(gamepadID, buttons[0]);
	//Select = 2,
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[1]) << 1;
	//LeftPad_Left = 4,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[2]) << 2;
	//LeftPad_Up = 8,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[3]) << 3;
	//LeftPad_Right = 16,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[4]) << 4;
	//LeftPad_Down = 32,
	state |= inputM_->isControllerButtonHeld(gamepadID, buttons[5]) << 5;
	//RightPad_Left = 64,
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[6]) << 6;
	//RightPad_Up = 128,
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[7]) << 7;
	//RightPad_Right = 256,
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[8]) << 8;
	//RightPad_Down = 512,
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[9]) << 9;
	//LeftBumper = 1024,
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[10]) << 10;
	//RightBumper = 2048,
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[11]) << 11;
	//LeftJoystickClick = 4096,
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[12]) << 12;
	//RightJoystickClick = 8192
	state |= inputM_->isControllerButtonPressed(gamepadID, buttons[13]) << 13;
	curbuttonState = state;

	//LJoyX = 0,
	axes[0] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[0]));
	//LJoyY,
	axes[1] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[1]));
	//RJoyX,
	axes[2] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[2]));
	//RJoyY,
	axes[3] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[3]));
	//LTrigger,
	axes[4] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[4]));
	//RTrigger,
	axes[5] = ApplyDeadZone(inputM_->getControllerAxis(gamepadID, axesButtons[5]));
}
