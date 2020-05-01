#pragma once
#include <vector>
#include "InputManager.h"
class HID
{
public:
	enum ButtonsID {
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
		RightJoystickClick = 8192
	};

	enum AxesID {
		LJoyX = 0,
		LJoyY,
		RJoyX,
		RJoyY,
		LTrigger,
		RTrigger,
		/*
		
		*/
		_NumAxes_
	};

	inline virtual bool isButtonDown(ButtonsID button) {
		return (curbuttonState & button) != 0;
	}
	inline virtual float AxisInput(AxesID axis) {
		return axes[axis];
	}

	virtual void updateInput() = 0;

	virtual ~HID() {}
protected:
	short curbuttonState; // 0 = not pressed
	short lastButtonState;
	// LJoyX, LJoyY, RJoyX, RJoyY, LTrigger, RTrigger
	std::vector<float> axes = std::vector<float>(_NumAxes_); // (-1 to) 0 to 1
};

