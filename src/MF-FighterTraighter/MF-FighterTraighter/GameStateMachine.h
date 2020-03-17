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

	//get the state that we're using now
	GameState* getCurrentState();
	//create a new state
	void pushState(GameState* state) { states.push(state); };
	//delete the current state
	void popState() { states.pop(); }
private:
	std::stack<GameState*> states; //stack with the scenes that we will use in the game

};

