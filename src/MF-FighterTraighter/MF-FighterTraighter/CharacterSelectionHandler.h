#pragma once
#include "Component.h"
class CharacterSelectionHandler :
	public Component
{
public:
	CharacterSelectionHandler(GameState* state,bool j1,bool j2):Component(ecs::CharacterSelectionHandler),state_(state), j1_(j1), j2_(j2){}

	void init() override;
	void update() override;
	void handleInput() override;
private:
	bool j1_, j2_;
	GameState* state_;
};

