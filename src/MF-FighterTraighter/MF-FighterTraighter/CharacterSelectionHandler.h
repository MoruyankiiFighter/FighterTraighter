#pragma once
#include "Component.h"
#include "CharacterSelectionLogic.h"
class CharacterSelectionHandler :
	public Component
{
public:
	
	CharacterSelectionHandler(Entity* j1, Entity* j2): Component(ecs::CharacterSelectionHandler), log1(j1), log2(j2){}
	void init() override;
	void update() override;
	void handleInput() override;
private:
	bool j1_ = false, j2_ = false;

	Entity* log1;
	Entity* log2;
};

