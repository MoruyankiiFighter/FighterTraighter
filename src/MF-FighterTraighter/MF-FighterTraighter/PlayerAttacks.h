#pragma once
#include "Component.h"
#include "AnimationChain.h"
#include <vector>
#include "PlayerState.h"
#include "HID.h"
//component that have all the attacks that you have
class PlayerAttacks : public Component 
{
public:
	
	PlayerAttacks(HID* hid, AnimationChain* highFist, AnimationChain* airHighFist, AnimationChain* lowFist, AnimationChain* airLowFist,
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

		for (int i = 0; i < cooldowns.size(); ++i) {
			if (cooldowns[i] > 0) --cooldowns[i];
		}
	};
	void handleInput() override;
	void setAbility(AnimationChain* newAbility, int index);
	void interruptAttack();
	inline void goOnCooldown(int id, int cool) {
		cooldowns[id] = cool;
	}
	int getAbilityIndex();
	int getAbilityCooldown(int index) {  return cooldowns[index]; }
private:
	std::vector<AnimationChain*> attacksList;	//pointer to the attack that you can use
	std::vector<AnimationChain*> abilityList = std::vector<AnimationChain*>(2);	//pointer to the abilities 
	std::vector<int> cooldowns = std::vector<int>(2);
	AnimationChain* activeAttack_ = nullptr;

	//keys to use the attacks and abilities
	HID* inputSt_;
};

