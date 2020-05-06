#pragma once
#include "HID.h"
#include <SDL.h>
class KeyboardHID :
	public HID
{
public:
	KeyboardHID(InputManager* input) : inputM_(input) {}

	inline void changeKey(int index, SDL_Scancode newKey) {
		keys_[index] = newKey;
	}
	inline void changeKey(std::vector<SDL_Scancode> newKeys, int start = 0, int end = 10) {
		int indexNew = 0;
		for (int i = start; i < end; ++i) {
			keys_[i] = newKeys[indexNew];
			indexNew++;
		}
	}
	void updateInput();
protected:
	// order: buttons + axes(joysticks have two keys)
	std::vector<SDL_Scancode> keys_ = { SDL_SCANCODE_ESCAPE, SDL_SCANCODE_RETURN,
		SDL_SCANCODE_LEFT, SDL_SCANCODE_UP, SDL_SCANCODE_RIGHT, SDL_SCANCODE_DOWN,
		SDL_SCANCODE_E, SDL_SCANCODE_R, SDL_SCANCODE_W, SDL_SCANCODE_Q, SDL_SCANCODE_2,
		SDL_SCANCODE_3, SDL_SCANCODE_RETURN, SDL_SCANCODE_SPACE, SDL_SCANCODE_LEFT,
		SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_J, SDL_SCANCODE_L,
		SDL_SCANCODE_I, SDL_SCANCODE_L, SDL_SCANCODE_SPACE, SDL_SCANCODE_T };	//Default value maybe?
	InputManager* inputM_;
};

