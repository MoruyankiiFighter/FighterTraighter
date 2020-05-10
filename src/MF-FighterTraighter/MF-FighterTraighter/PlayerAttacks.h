#pragma once
#include "Component.h"
#include "AnimationChain.h"
#include <vector>
#include "PlayerState.h"
#include "PlayerData.h"
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
				if (!isMultiplierTimed && remainingUses_ > -1) { 
					//This is to prevent, in theory, that the abilities that grant the multiplier themeselves don't consume it on ending
					if (remainingUses_ == 0) {
						entity_->getComponent<PlayerData>(ecs::PlayerData)->setAttack(1);
						remainingUses_ = -1;
					}
					else remainingUses_--;
				}
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

		if (multiplierTimer_ > 0) {
			multiplierTimer_--;
		}
		else if (multiplierTimer_ == 0) {
			entity_->getComponent<PlayerData>(ecs::PlayerData)->setAttack(1);
			multiplierTimer_ = -1;
		}
	};
	void handleInput() override;
	void setAbility(AnimationChain* newAbility, int index);
	void interruptAttack();
	inline void goOnCooldown(int id, int cool) {
		cooldowns[id] = cool;
	}
	int getAbilityIndex();
	int getAbilityCooldown(int index) {  cout << cooldowns[index] <<endl; return cooldowns[index]; }

	void setMultiplier(double mul, bool timed, int timer = -1) {
		entity_->getComponent<PlayerData>(ecs::PlayerData)->setAttack(mul);
		isMultiplierTimed = timed;
		if (timed) multiplierTimer_ = timer;
		else {
			timer = -1;
			remainingUses_ = 1;
		}
	}
private:
	std::vector<AnimationChain*> attacksList;	//pointer to the attack that you can use
	std::vector<AnimationChain*> abilityList = std::vector<AnimationChain*>(2);	//pointer to the abilities 
	std::vector<int> cooldowns = std::vector<int>(2);
	AnimationChain* activeAttack_ = nullptr;

	int multiplierTimer_ = -1;
	int remainingUses_ = 0;
	bool isMultiplierTimed = false;

	//keys to use the attacks and abilities
	HID* inputSt_;
};

