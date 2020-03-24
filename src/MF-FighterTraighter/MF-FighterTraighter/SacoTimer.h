#pragma once
#include "Component.h"
class SacoTimer :
	public Component
{
public:
	//constructor
	SacoTimer(int timeLimit) : Component(ecs::SacoTimer), timeLimit_(timeLimit) {};
	
	//destructor
	~SacoTimer() {};
	
	//method overrided from Component
	virtual void init() override { startTime_ = SDL_GetTicks(); };
	virtual void update() override;
private:
	int timeLimit_;
	int startTime_;
	int currTime_ = 0;
};

