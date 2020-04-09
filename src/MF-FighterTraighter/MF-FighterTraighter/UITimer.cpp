#include "UITimer.h"
#include "Entity.h"

void UITimer::init()
{
	text_ = entity_->getComponent<TextComponent>(ecs::TextComponent);
	timerStart_ = SDL_GetTicks();
}

void UITimer::update()
{
	if (!timerStopped_) {
		if (!countdown_) {
			timerNow_ = SDL_GetTicks();
		}
		else {
			timerStart_ = SDL_GetTicks();
			if (timerNow_ - timerStart_ <= 0) {
				timerStart_ = timerNow_;
			}
		}
		setText();
	}
}

void UITimer::resetTimer()
{
	timerStart_ = SDL_GetTicks();
	if (!countdown_) {
		timerNow_ = SDL_GetTicks();
	}
	else {
		timerNow_ = SDL_GetTicks() + countdownAmount_;
	}
}

void UITimer::stopTimer()
{
	timerStopped_ = true;
}

void UITimer::resumeTimer()
{
	timerStopped_ = false;
}

void UITimer::setText()
{
	switch (format_)
	{
	case UITimer::Miliseconds:
		text_->setText(to_string(timerNow_ - timerStart_));
		break;
	case UITimer::Seconds:
		text_->setText(to_string((timerNow_ - timerStart_) / 1000));
		break;
	case UITimer::Minutes:
		text_->setText(to_string((timerNow_ - timerStart_) / 60000) + ":" + to_string(((timerNow_ - timerStart_) / 1000) % 60));
		break;
	case UITimer::Clock:
		text_->setText(to_string((timerNow_ - timerStart_) / 3600000) + ":" + to_string(((timerNow_ - timerStart_) / 60000) % 60) + ":" + to_string(((timerNow_ - timerStart_) / 1000) % 60));
		break;
	default:
		break;
	}
}
