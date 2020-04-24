#pragma once
#include "Component.h"
#include "Slider.h"
#include "TextComponent.h"

class OptionsLogic :
	public Component
{
public:
	OptionsLogic(Slider* resolutionsSlider, TextComponent* resolutionsText, Slider* brightnessSlider, TextComponent* brightnessText) :
		Component(ecs::OptionsLogic), resolutionsSlider_(resolutionsSlider), resolutionsText_(resolutionsText), brightnessSlider_(brightnessSlider), brightnessText_(brightnessText) {};
	void init() override;
	void SetElements();
	void update() override;
protected:
	Slider* resolutionsSlider_;
	TextComponent* resolutionsText_;
	Slider* brightnessSlider_;
	TextComponent* brightnessText_;
};

