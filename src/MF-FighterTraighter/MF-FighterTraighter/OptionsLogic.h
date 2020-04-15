#pragma once
#include "Component.h"
#include "Slider.h"
#include "TextComponent.h"

class OptionsLogic :
	public Component
{
public:
	OptionsLogic(Slider* resolutionsSlider, TextComponent* resolutionsText, Slider* brightnessSlider, TextComponent* brightnessText, Slider* volumeSlider, TextComponent* volumeText) :
		Component(ecs::OptionsLogic), resolutionsSlider_(resolutionsSlider), resolutionsText_(resolutionsText), brightnessSlider_(brightnessSlider), brightnessText_(brightnessText) {};
	void init() override;
	void SetElements();
	void update() override;
protected:
	Slider* resolutionsSlider_=nullptr;
	TextComponent* resolutionsText_=nullptr;
	Slider* brightnessSlider_=nullptr;
	TextComponent* brightnessText_=nullptr;
	Slider* volumeSlider_=nullptr;
	TextComponent* VolumeText_=nullptr;
};

