#pragma once
#include "Component.h"
#include "InpuState.h"


class KeyboardInput: public Component {
public:
	KeyboardInput() : Component(ecs::KeyboardInput), inSt(nullptr) {};
	KeyboardInput(std::vector<SDL_Scancode> keys) : Component(ecs::KeyboardInput), keys_(keys), inSt(nullptr) {};
	~KeyboardInput() {};
	virtual void init();
	void changeKey(int index, SDL_Scancode newKey) {
		keys_[index] = newKey;
	}
	void changeKey(std::vector<SDL_Scancode> newKeys, int start = 0, int end = 10) {
		int indexNew = 0;
		for (int i = start; i < end; ++i) {
			keys_[i] = newKeys[indexNew];
			indexNew++;
		}
	}
	virtual void handleInput() override {	//This could easily be done much less spaghettily
		int i = 0;
		for (; i < 4; ++i) {
			inSt->setInput(i, app_->getInputManager()->isKeyDown(keys_[i]));
		}
		for (; i < 10; ++i) {
			inSt->setInput(i, app_->getInputManager()->KeyPressed(keys_[i]));
		}

		inSt->setInput(i, app_->getInputManager()->isKeyDown(keys_[i]));	//Block
		++i;
		inSt->setInput(i, app_->getInputManager()->KeyPressed(keys_[i]));	//Guardbreak
		++i;
	}
private:
	//left, right, up, down, hit1, hit2, hit3, hit4, ab1, ab2, block, guardbreak
	int keysSize = 12;
	std::vector<SDL_Scancode> keys_ = { SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_Q, SDL_SCANCODE_E, SDL_SCANCODE_Z, SDL_SCANCODE_X,
		SDL_SCANCODE_1, SDL_SCANCODE_2, SDL_SCANCODE_SPACE, SDL_SCANCODE_R,  };	//Default value maybe?
	InputState* inSt;
};