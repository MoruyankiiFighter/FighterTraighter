#pragma once
#include "GameState.h"
#include <stack>

class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();

	GameState* getCurrentState();
	void pushState(GameState* state) { states.push(state); }
	void popState() { states.pop(); }
private:
	std::stack<GameState*> states; //it's the different scenes that we have

};

