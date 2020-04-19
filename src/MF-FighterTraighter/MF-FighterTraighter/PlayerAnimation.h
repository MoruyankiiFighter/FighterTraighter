#pragma once
#include "Component.h"
#include "Texture.h"
#include "PlayerState.h"
#include "RenderImage.h"
#include "PlayerData.h"

class PlayerAnimation : public Component {
public:
	PlayerAnimation(int incr) : Component(ecs::PlayerAnimation), activeFrame_(0), currStateInt_(0), timeBetweenIncrements_(incr) {};
	~PlayerAnimation() {};
	virtual void init() {
		imgR_ = entity_->getComponent<RenderImage>(ecs::RenderImage);
		currState_ = entity_->getComponent<PlayerState>(ecs::PlayerState);
		currStateInt_ = currState_->getState();
		data_ = entity_->getComponent<PlayerData>(ecs::PlayerData);
	}
	virtual void update();
private:
	RenderImage* imgR_;
	int activeFrame_;
	int timeSinceLastIncrement_ = 0; //Manually delay animation speed
	int timeBetweenIncrements_;
	PlayerData* data_;
	PlayerState* currState_;
	int currStateInt_;
};