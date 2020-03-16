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

	//
	GameState* getCurrentState();
	void pushState(GameState* state) { states.push(state); }
	void popState() { states.pop(); }
private:
	std::stack<GameState*> states; //it's the different scenes that we have

};

