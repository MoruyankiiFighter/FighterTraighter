#pragma once
#include "Component.h"
#include "Texture.h"
#include "PlayerState.h"

class PlayerAnimation : public Component {
public:
	PlayerAnimation(Texture* spritesheet) : Component(ecs::PlayerAnimation), spriteShit_(spritesheet), activeFrame_(0), currStateInt_(0) {};
	~PlayerAnimation() {};
	virtual void init() {
		currState_ = entity_->getComponent<PlayerState>(ecs::PlayerState);
		currStateInt_ = currState_->getState();
	}
	virtual void update();
private:
	Texture* spriteShit_;
	double activeFrame_;
	PlayerState* currState_;
	int currStateInt_;
};