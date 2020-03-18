#include "IndexSlider.h"
#include "Entity.h"
void IndexSlider::init()
{
	transform_ = entity_->getComponent<Transform>(ecs::Transform);
}

void IndexSlider::update()
{
	transform_->setPosition(transform_slider->getPosition().getX(), transform_->getPosition().getY());
}

