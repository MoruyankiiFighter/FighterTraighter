#pragma once
#include "GameState.h"
class Options: public GameState
{
public:
	Options(App* app);
	virtual ~Options();

	void init() override;
	virtual void update() override;
	virtual void render() override;

private:
};

