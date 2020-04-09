#pragma once
#include "Component.h"
#include <SDL.h>
#include "TextComponent.h"
class UITimer :
	public Component
{
	enum Format {
		Miliseconds, // 0000 (miliseconds)
		Seconds, // 00 (seconds)
		Minutes, // 00:00
		Clock // 00:00:00
	};
public:
	// Note: this timer is frame independent
	UITimer(Format format, bool isCountdown = false, int countdownAmount = 0)
		: Component(ecs::UITimer), format_(format), countdown_(isCountdown), countdownAmount_(countdownAmount) {}

	void init() override;
	void update() override;

	inline void setFormat(Format f) { format_ = f; }
	// Sets the countdown to c, resets the timer and sets it to a countdown timer
	inline void setCountdown(int c) { 
		countdown_ = true;
		countdownAmount_ = c; 
		resetTimer();
	}

	void resetTimer();
	void stopTimer();
	void resumeTimer();

	virtual ~UITimer() {}
protected:
	void setText();

	int timerStart_ = 0; // ms
	int timerNow_ = 0; // ms
	bool timerStopped_ = false;
	bool countdown_; // if true, the timer will countdown from countdownAmount_ to 0
	int countdownAmount_ = 0; // amount in miliseconds
	Format format_;
	TextComponent* text_ = nullptr;
};

