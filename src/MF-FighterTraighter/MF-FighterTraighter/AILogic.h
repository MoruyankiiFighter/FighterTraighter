#pragma once
#include "Component.h"
#include "PlayerState.h"
#include <queue>
class AILogic :
	public Component
{
	// Size: (49 + nProjectiles * 24) bytes
	struct WorldInformation {
		PlayerState::Status otherPlayerStatus_; // 1 byte
		Vector2D otherPlayerPosition_; // 24 bytes
		Vector2D thisPosition_; // 24 bytes
		std::vector<Vector2D> projectilesPosition_; // nProjectiles * 24 bytes
	};

public:
	AILogic(ecs::HandlerId playerID, int reactionTime) : Component(ecs::AILogic), reactionTime_(reactionTime), playerID_(playerID) {}

	void init() override;
	void update() override;

protected:
	int reactionTime_;
	int timePassed = 0;
	ecs::HandlerId playerID_;


	// Current information
	Entity* otherPlayer_;
	std::vector<Entity*> projectiles_;

	// Each item was the state of the world captured at that moment
	std::queue<WorldInformation> worldReads_;
};

