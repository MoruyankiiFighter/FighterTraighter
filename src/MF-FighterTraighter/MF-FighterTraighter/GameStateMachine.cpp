#include "GameStateMachine.h"
#include "App.h"

GameStateMachine::GameStateMachine(App* app): app_(app){ }

GameStateMachine::~GameStateMachine()
{
	while (!states.empty()) {
		//delete states.top();
		popState();
	}
}

GameState* GameStateMachine::getCurrentState() //if there is a state then returns the top of the stack
{
	if (!states.empty()) { 
		return states.top();
	}
	else {
		return nullptr;
	}
}

void GameStateMachine::popState()
{
	GameState* state = states.top();
	toDelete.push(state);
	app_->getHitboxMng()->clear();
	states.pop();
	stackSize_--; std::cout << "Stack size: " << stackSize_ << std::endl;
}
