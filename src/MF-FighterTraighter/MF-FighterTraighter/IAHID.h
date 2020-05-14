#pragma once
#pragma once
#include "HID.h"
#include <SDL.h>
class KeyboardHID :
	public HID
{
public:
	KeyboardHID() {}
	void updateInput();
protected:
	InputManager* inputM_;
};