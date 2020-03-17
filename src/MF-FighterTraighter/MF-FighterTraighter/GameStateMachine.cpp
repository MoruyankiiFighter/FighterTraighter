#include "GameStateMachine.h"

//constructor
GameStateMachine::GameStateMachine(){ }

//destructor, deletes every state of the stack 
GameStateMachine::~GameStateMachine()
{
	while (!states.empty()) {
		delete states.top();
		popState();
	}
}

//if there is a state then returns the top of the stack
GameState* GameStateMachine::getCurrentState() 

{
	if (!states.empty()) { 
		return states.top();
	}
	else {
		return nullptr;
	}
}

////Return second state
//GameState* GameStateMachine::getSecond() {
//	GameState* top = getCurrentState();
//	popState();
//	GameState* secondTop = getCurrentState();
//	pushState(top);
//	return secondTop;
//}