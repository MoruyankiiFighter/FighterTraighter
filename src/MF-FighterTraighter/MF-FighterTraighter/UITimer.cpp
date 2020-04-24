#include "UITimer.h"
#include "Entity.h"

void UITimer::init()
{
	text_ = entity_->getComponent<TextComponent>(ecs::TextComponent);
	resetTimer();
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
	string text;
	switch (format_)
	{
	case UITimer::Miliseconds:
		text_->setText(to_string(timerNow_ - timerStart_));
		break;
	case UITimer::Seconds:
		text_->setText(to_string((timerNow_ - timerStart_) / 1000));
		break;
	case UITimer::Minutes:
		text = to_string((timerNow_ - timerStart_) / 60000) + ":";
		if ((((timerNow_ - timerStart_) / 1000) % 60) < 10) {
			text += "0";
		}
		text += to_string(((timerNow_ - timerStart_) / 1000) % 60);
		text_->setText(text);
		break;
	case UITimer::Clock:
		text = to_string((timerNow_ - timerStart_) / 3600000) + ":";
		if ((((timerNow_ - timerStart_) / 60000) % 60) < 10) {
			text += "0";
		}
		text += to_string(((timerNow_ - timerStart_) / 60000) % 60) + ":";
		if ((((timerNow_ - timerStart_) / 1000) % 60) < 10) {
			text += "0";
		}
		text += to_string(((timerNow_ - timerStart_) / 1000) % 60);
		text_->setText(text);
		break;
	default:
		break;
	}
}
