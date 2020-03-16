#include "Slider.h"
#include "Entity.h"

Slider::Slider(double minValue, double maxValue) : Component(ecs::Slider), tr_(nullptr), minValue_(minValue), maxValue_(maxValue)
{
}

Slider::Slider(double minValue, double maxValue, CallbackOnValueChanged* valueChanged, CallbackOnStartDrag* startDrag, CallbackOnEndDrag endDrag)
	: Component(ecs::Slider), tr_(nullptr), valueChanged_(valueChanged), startDrag_(startDrag), endDrag_(endDrag), minValue_(minValue), maxValue_(maxValue)
{
}

void Slider::init()
{
	tr_ = entity_->getComponent<Transform>(ecs::Transform);
}

void Slider::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(InputManager::Left)) {
		if (isMouseOver()) { // dragging
			if (!dragging_) {
				dragging_ = true;
				if (startDrag_) startDrag_(app_);
				value_ = (app_->getInputManager()->getMousePosX() - tr_->getPosition().getX()) / tr_->getWidth() * (maxValue_ - minValue_);
			}
		}
	}
	else if (dragging_) {
		if (endDrag_) endDrag_(app_);
		dragging_ = false;
	}

	// vertical and horizontal sliders? enum? bool? different component?
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
	if (mouseMovement.getX() != 0) {
		setValue(value_ + mouseMovement.getX() / tr_->getWidth() * (maxValue_ - minValue_));
	}
}

void Slider::render()
{
	// should render itself, or have children which render themselves (transform and children?)
}

void Slider::setValue(double newValue)
{
	double oldValue = value_;
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
