#pragma once
#include "Component.h"
#include "AnimationChain.h"
#include <vector>
#include "PlayerState.h"
#include "InpuState.h"

//component that have all the attacks that you have
class PlayerAttacks : public Component 
{
public:
	
	PlayerAttacks(AnimationChain* highFist, AnimationChain* airHighFist, AnimationChain* lowFist, AnimationChain* airLowFist,
		AnimationChain* highKick, AnimationChain* airHighKick, AnimationChain* lowKick, AnimationChain* airLowKick, AnimationChain* testGB);
	virtual ~PlayerAttacks();
	virtual void init() override;
	virtual void update() override { 
		if (activeAttack_ != nullptr) { 
			
			if (activeAttack_->update()) {
				activeAttack_->reset();
				activeAttack_ = nullptr;
				if (entity_->getComponent<PlayerState>(ecs::PlayerState)->isGrounded()) {
					entity_->getComponent<PlayerState>(ecs::PlayerState)->goIdle();
				}
				else {
					entity_->getComponent<PlayerState>(ecs::PlayerState)->goJumping();
				}
			}
			//else if (entity_->getComponent<PlayerState>(ecs::PlayerState)->isHitstun()) interruptAttack(); <-- Esto es in�til (nunca va a estar atacando y ser hitstun)
		}
	};
	void handleInput() override;
	void setAbility(AnimationChain* newAbility, int index);
	void interruptAttack();
private:
	std::vector<AnimationChain*> attacksList;	//pointer to the attack that you can use
	std::vector<AnimationChain*> abilityList = std::vector<AnimationChain*>(2);	//pointer to the abilities 
	AnimationChain* activeAttack_ = nullptr;

	//keys to use the attacks and abilities
	InputState* inputSt_;
};

