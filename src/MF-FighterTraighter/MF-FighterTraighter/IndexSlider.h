#pragma once
#include "Component.h"
#include "Transform.h"
#include "Slider.h"
class IndexSlider :
	public Component
{
public:
	IndexSlider(Transform* transform, Slider* slider) : Component(ecs::IndexSlider),transform_slider(transform_) ,slider_(slider){}
	virtual ~IndexSlider();
	
	void init() override;
	void update() override;


private:
	Slider* slider_=nullptr;
	Transform* transform_ = nullptr;
	Transform* transform_slider = nullptr;
};

