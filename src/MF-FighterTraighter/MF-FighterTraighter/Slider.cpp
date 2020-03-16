#include "Slider.h"
#include "Entity.h"

Slider::Slider(double minValue, double maxValue, int steps) : Component(ecs::Slider), tr_(nullptr), minValue_(minValue), maxValue_(maxValue), steps_(steps)
{
}

Slider::Slider(double minValue, double maxValue, int steps, CallbackOnValueChanged* valueChanged, CallbackOnDrag* startDrag, CallbackOnDrag endDrag)
	: Component(ecs::Slider), tr_(nullptr), valueChanged_(valueChanged), startDrag_(startDrag), endDrag_(endDrag), minValue_(minValue), maxValue_(maxValue), steps_(steps)
{
}

void Slider::init()
{
	value_ = minValue_;
	tr_ = entity_->getComponent<Transform>(ecs::Transform);
}

void Slider::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(InputManager::Left)) {
		if (isMouseOver()) { // dragging
			if (!dragging_) {
				dragging_ = true;
				if (startDrag_) startDrag_(app_);
				setValueOnClick();
			}
		}
	}
	else if (dragging_) {
		if (endDrag_) endDrag_(app_);
		dragging_ = false;
	}
}

void Slider::setValueOnClick()
{
	double a = (value_ + app_->getInputManager()->getMousePosX() - tr_->getPosition().getX()) / tr_->getWidth() * tr_->getWMult() * (maxValue_ - minValue_) + minValue_;
	setValue(a);
}

void Slider::update()
{
	if (dragging_) {
		dragValue();
	}

	cout << value_ << endl;
}

void Slider::dragValue()
{
	InputManager* input = app_->getInputManager();
	Vector2D mouseMovement = input->getMouseMovement();
	Vector2D mousePos = input->getMousePos();
	if (mouseMovement.getX() != 0 && mousePos.getX() >= tr_->getPosition().getX() && mousePos.getX() <= tr_->getPosition().getX() + tr_->getWidth() * tr_->getWMult()) {
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
		int i = 0;
		bool stop = false;
		while (i <= steps_ && !stop) {
			double currentValue = minValue_ + distanceBetweenSteps * i;
			if (currentValue - distanceBetweenSteps / 2 <= newValue && currentValue + distanceBetweenSteps / 2 >= newValue) {
				newValue = currentValue;
				stop = true;
			}
			++i;
		}
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
	Vector2D trPos = tr_->getPosition();
	SDL_Point mousePos = { app_->getInputManager()->getMousePosX(),app_->getInputManager()->getMousePosY() };

	SDL_Rect trRect = { trPos.getX(), trPos.getY(), tr_->getWidth() * tr_->getWMult(), tr_->getHeight() * tr_->getHMult() };

	return SDL_PointInRect(&mousePos, &trRect);
}

Slider::~Slider()
{
}
