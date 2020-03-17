#pragma once
#include "GameState.h"
#include "Texture.h"
class OptionsMenu:public GameState
{
public:
	//constructor
	OptionsMenu(App* app);
	//destructor	
	virtual ~OptionsMenu();

	void init() override;
};

