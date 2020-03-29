#pragma once
#include "GameState.h"
#include <stack>

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
	void pushState(GameState* state) { states.push(state); }
	
	//deletes the current state
	void popState() { states.pop(); }

private:
	std::stack<GameState*> states; //stack with the different scenes

};

