#include "UITransform.h"

void UITransform::init()
{
	windowMngr_ = app_->getWindowManager();
	windowSize_ = Vector2D(windowMngr_->getCurResolution().w, windowMngr_->getCurResolution().h);
}

void UITransform::update()
{

	SDL_DisplayMode w = windowMngr_->getCurResolution();
	if (windowSize_.getX() != w.w || windowSize_.getY() != w.h) {
		WindowResized(w.w, w.h);
	}
}

void UITransform::setAnchorPreset(AnchorPreset preset)
{
	SDL_DisplayMode w = windowMngr_->getCurResolution();
	switch (preset)
	{
	case UITransform::TopLeft:
		anchor_ = Vector2D(0, 0);
		break;
	case UITransform::Top:
		anchor_ = Vector2D(w.w / 2, 0);
		break;
	case UITransform::TopRight:
		anchor_ = Vector2D(w.w, 0);
		break;
	case UITransform::CenterLeft:
		anchor_ = Vector2D(0, w.h / 2);
		break;
	case UITransform::Center:
		anchor_ = Vector2D(w.w / 2, w.h / 2);
		break;
	case UITransform::CenterRight:
		anchor_ = Vector2D(w.w, w.h / 2);
		break;
	case UITransform::BottomLeft:
		anchor_ = Vector2D(0, w.h);
		break;
	case UITransform::Bottom:
		anchor_ = Vector2D(w.w / 2, w.h);
		break;
	case UITransform::bottomRight:
		anchor_ = Vector2D(w.w, w.h);
		break;
	default:
		break;
	}
}

void UITransform::WindowResized(double newW, double newH)
{
	anchor_ = Vector2D(anchor_.getX() * (newW / windowSize_.getX()), anchor_.getY() * (newW / windowSize_.getX()));
	wMult_ *= (newW / windowSize_.getX());
	hMult_ *= (newH / windowSize_.getY());
	double newPosX = position_.getX() * (newW / windowSize_.getX());
	double newPosY = position_.getY() * (newH / windowSize_.getY());
	position_.set({ newPosX, newPosY });
	windowSize_.setX(newW);
	windowSize_.setY(newH);
}