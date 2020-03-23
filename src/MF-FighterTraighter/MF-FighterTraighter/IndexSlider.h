#pragma once
#include "Component.h"
#include "Transform.h"
#include "Slider.h"
class IndexSlider :
	public Component
{
public:
	IndexSlider(Entity* slider) : Component(ecs::IndexSlider), sliderEnt_(slider) {}
	virtual ~IndexSlider();

	void init() override;
	void update() override;


private:
	Entity* sliderEnt_ = nullptr;
	Transform* transform_ = nullptr;
	Transform* transform_slider = nullptr;
	Slider* slider_ = nullptr;
};

