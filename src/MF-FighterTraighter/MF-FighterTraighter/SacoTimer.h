#pragma once
#include "Component.h"
class SacoTimer :
	public Component
{
public:
	SacoTimer(int timeLimit) : Component(ecs::SacoTimer), timeLimit_(timeLimit) {};
	~SacoTimer() {};
	virtual void init() override { startTime_ = SDL_GetTicks(); };
	virtual void update() override;
private:
	int timeLimit_;
	int startTime_;
	int currTime_ = 0;
};

