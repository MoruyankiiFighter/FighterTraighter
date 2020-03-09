#pragma once
#include "GameState.h"
#include "Texture.h"
class OptionsMenu:public GameState
{
public:
	OptionsMenu(App* app);
	virtual ~OptionsMenu();

	void init() override;
	virtual void update() override;
	virtual void render() override;
	void handleInput();
};

