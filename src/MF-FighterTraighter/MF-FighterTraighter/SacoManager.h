#pragma once
#include "Component.h"
#include "PhysicsTransform.h"
class SacoManager : public Component
{
public:

	enum PunchingBagInteraction {
		LAST_HIT,
		MORE_DAMAGE,
		_last_interaction
	};
	//constructor
	SacoManager(int timeLimit) : Component(ecs::SacoTimer), timeLimit_(timeLimit) {};
	
	//destructor
	~SacoManager() {};
	
	//method overrided from Component
	virtual void init() override;
	virtual void update() override;
private:
	PhysicsTransform* transform_ = nullptr;
	int timeLimit_;
	int startTime_=0;
	int currTime_ = 0;
};

