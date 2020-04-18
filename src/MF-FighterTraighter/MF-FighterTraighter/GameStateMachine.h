#pragma once
#include "GameState.h"
#include <stack>
#include <iostream>

class GameStateMachine
{
public:
	//constructor
	GameStateMachine();
	
	//destructor
	~GameStateMachine();

	//return the current state
	GameState* getCurrentState();

	//push a new current state
	void pushState(GameState* state) { states.push(state); stackSize_++; std::cout << "Stack size: " << stackSize_ << std::endl; }
	
	//deletes the current state
	void popState() { 
		delete states.top();
		states.pop();
		stackSize_--; std::cout << "Stack size: " << stackSize_ << std::endl;
	}

private:
	std::stack<GameState*> states; //stack with the different scenes
	int stackSize_;
};

