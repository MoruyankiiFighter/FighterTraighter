#pragma once
#include "GameState.h"
class Fight: public GameState
{
public:
	Fight(App* app);
	void init() override;
	void update() override;
	virtual ~Fight();
};

