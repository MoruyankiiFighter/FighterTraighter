#include "IndexSlider.h"
#include "Entity.h"
IndexSlider::~IndexSlider()
{
	delete transform_;
	 transform_=nullptr;

	delete slider_;
	slider_ = nullptr;
	
	delete transform_slider;
	transform_slider = nullptr;
}
void IndexSlider::init()
{
	transform_ = entity_->getComponent<Transform>(ecs::Transform);
}

void IndexSlider::update()
{
	if (slider_->getSteps() > 0) {

	}
}

