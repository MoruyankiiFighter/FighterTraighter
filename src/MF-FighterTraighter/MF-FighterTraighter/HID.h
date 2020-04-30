#pragma once
class HID
{
public:
	enum ControlButtonsID {
		Start = 1,
		Select = 2,
		LeftPad_Left = 4,
		LeftPad_Up = 8,
		LeftPad_Right = 16,
		LeftPad_Down = 32,
		RightPad_Left = 64,
		RightPad_Up = 128,
		RightPad_Right = 256,
		RightPad_Down = 512,
		LeftBumper = 1024,
		RightBumper = 2048,
		LeftJoystickClick = 4096,
		RightJoystickClick = 8192,
	};

	virtual bool isButtonPressed(ControlButtonsID button) {
		return (curbuttonState & button) == 0;
	}

	virtual void updateInput() = 0;
protected:
	short curbuttonState; // 0 = not pressed
	short lastButtonState;
	int LJoyX;
	int LJoyY;
	int RJoyX;
	int RJoyY;
};

