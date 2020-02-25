#pragma once
#include "GameState.h"
class Fight: public GameState
{
public:
	Fight(App* app, SDL_Renderer* rend);
	void init() override;
	void update() override;
	virtual ~Fight();
};

