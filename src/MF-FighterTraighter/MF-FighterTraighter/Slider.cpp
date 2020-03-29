#include "Slider.h"
#include "Entity.h"

Slider::Slider(double minValue, double maxValue, int steps) : Component(ecs::Slider), transform_(nullptr), minValue_(minValue), maxValue_(maxValue), steps_(steps)
{
}

Slider::Slider(double minValue, double maxValue, int steps, CallbackOnValueChanged* valueChanged, CallbackOnDrag* startDrag, CallbackOnDrag endDrag)
	: Component(ecs::Slider), transform_(nullptr), valueChanged_(valueChanged), startDrag_(startDrag), endDrag_(endDrag), minValue_(minValue), maxValue_(maxValue), steps_(steps)
{
}

void Slider::init()
{
	value_ = minValue_;
	transform_ = entity_->getComponent<Transform>(ecs::Transform);
}

void Slider::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(InputManager::Left)) {
		if (app_->getInputManager()->mouseEvent()) {
			if (isMouseOver()) { // dragging
				if (!dragging_) {
					dragging_ = true;
					if (startDrag_) startDrag_(app_);
					setValueOnClick();
				}
			}
		}
	}
	else if (dragging_) {
		dragging_ = false;
		if (endDrag_) endDrag_(app_);
	}

	//cout << dragging_ << endl;
}

void Slider::setValueOnClick()
{
	double a = (value_ + app_->getInputManager()->getMousePosX() - transform_->getPosition().getX()) / transform_->getWidth() * transform_->getWMult() * (maxValue_ - minValue_) + minValue_;
	setValue(a);
}

void Slider::update()
{
	if (dragging_) {
		dragValue();
	}
}

void Slider::dragValue()
{
	InputManager* input = app_->getInputManager();
	Vector2D mouseMovement = input->getMouseMovement();
	Vector2D mousePos = input->getMousePos();
	if (mouseMovement.getX() != 0 && mousePos.getX() >= transform_->getPosition().getX() && mousePos.getX() <= transform_->getPosition().getX() + transform_->getWidth() * transform_->getWMult()) {
		setValueOnClick();
	}
}

void Slider::render()
{
	// should render itself, or have children which render themselves (transform and children?)
}

void Slider::setValue(double newValue)
{
	double oldValue = value_;
	if (steps_ >= 1) { // if steps < 1, continuous
		double distanceBetweenSteps = (maxValue_ - minValue_) / steps_;

		int j = ceil((-distanceBetweenSteps / 2 + newValue - minValue_) / distanceBetweenSteps);
		newValue = minValue_ + distanceBetweenSteps * j;
	}
	value_ = newValue;

	if (value_ < minValue_)
		value_ = minValue_;
	else if (value_ > maxValue_)
		value_ = maxValue_;

	if (valueChanged_ && oldValue != value_) valueChanged_(app_, value_);
}

bool Slider::isMouseOver()
{
	Vector2D trPos = transform_->getPosition();
	SDL_Point mousePos = { app_->getInputManager()->getMousePosX(),app_->getInputManager()->getMousePosY() };

	SDL_Rect trRect = { trPos.getX(), trPos.getY(), transform_->getWidth() * transform_->getWMult(), transform_->getHeight() * transform_->getHMult() };

	return SDL_PointInRect(&mousePos, &trRect);
}

Slider::~Slider()
{
}
