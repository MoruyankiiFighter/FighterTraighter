#pragma once
#include "GameState.h"
class Fight: public GameState
{
public:
	Fight(App* app);
	void init() override;
	virtual void update() override;
	virtual void render() override;
	virtual ~Fight();
};

