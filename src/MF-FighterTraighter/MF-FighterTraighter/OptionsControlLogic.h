#pragma once
#include "Component.h"
#include "Button.h"
#include "TextComponent.h"

class OptionsControlLogic :
	public Component
{
public:
	OptionsControlLogic(Button* button, TextComponent* buttonText) :
		Component(ecs::OptionsControlLogic), button_(button), buttontext_(buttonText){};
	void init() override;
	void SetElements();
	void update() override;
protected:
	Button* button_;
	TextComponent* buttontext_;
	
};

