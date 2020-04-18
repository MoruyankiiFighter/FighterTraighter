#pragma once
#include "GameState.h"
#include <stack>
#include <iostream>
class App;

class GameStateMachine
{
public:
	//constructor
	GameStateMachine(App* app);
	
	//destructor
	~GameStateMachine();

	//return the current state
	GameState* getCurrentState();

	//push a new current state
	void pushState(GameState* state) { states.push(state); stackSize_++; std::cout << "Stack size: " << stackSize_ << std::endl; }
	
	//deletes the current state
	void popState();

	void deleteStates() {
		while (!toDelete.empty()) {
			GameState* s = toDelete.top();
			delete s;
			toDelete.pop();
		}
	}

private:
	std::stack<GameState*> states; //stack with the different scenes
	std::stack<GameState*> toDelete;
	int stackSize_;

	App* app_;
};

