#pragma once
#include "Component.h"
#include "Texture.h"
#include "PlayerState.h"
#include "RenderImage.h"

class PlayerAnimation : public Component {
public:
	PlayerAnimation() : Component(ecs::PlayerAnimation), activeFrame_(0), currStateInt_(0) {};
	~PlayerAnimation() {};
	virtual void init() {
		imgR_ = entity_->getComponent<RenderImage>(ecs::RenderImage);
		currState_ = entity_->getComponent<PlayerState>(ecs::PlayerState);
		currStateInt_ = currState_->getState();
	}
	virtual void update();
private:
	RenderImage* imgR_;
	int activeFrame_;
	int timeSinceLastIncrement_ = 0; //Manually delay animation speed
	PlayerState* currState_;
	int currStateInt_;
};