#pragma once
#include "GameState.h"
#include "App.h"
class AIGameState :
	public GameState
{
public:
	AIGameState(App* app): GameState(app) { init(); }
	void init() override;
	void handleInput() override;
	virtual ~AIGameState() {};
protected:
};

