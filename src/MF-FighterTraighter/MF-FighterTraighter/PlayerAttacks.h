#pragma once
#include "Component.h"
#include "AnimationChain.h"
#include <vector>
#include "PlayerState.h"
#include "PlayerData.h"
#include "HID.h"
#include "AbilitiesTimerFunction.h"
#include "PlayerParticleSystem.h"

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
				if (!isAbility(activeAttack_) && !isMultiplierTimed) resetOneTimeMultiplier();	//This should ONLY reset OneTimeMultipliers, but I'm sure errors will end up popping up and making me look lika big doo doo head >:/
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
		setTimeCool(cool);
		cout << cooldowns[id] << endl;
	}
	void setTimeCool(int cool);
	int getTimeCool();
	int getAbilityIndex();
	int getAbilityCooldown(int index) { 
#ifdef _DEBUG
		//cout << cooldowns[index] <<endl; 
#endif 
		return cooldowns[index];
	}

	void setMultiplier(double mul, bool timed, int timer = -1) {
		entity_->getComponent<PlayerData>(ecs::PlayerData)->setAttack(mul);
		isMultiplierTimed = timed;
		if (timed) multiplierTimer_ = timer;
		else timer = -1;
	}

	void resetOneTimeMultiplier() {
		entity_->getComponent<PlayerData>(ecs::PlayerData)->setAttack(1);
		entity_->getComponent<PlayerParticleSystem>(ecs::PlayerParticleSystem)->removeDeletionMethodParticles(PlayerParticleSystem::DeletionMethod::OnAttack);
	}

	bool isAbility(AnimationChain* anim) {
		int i = 0;
		bool is = false;
		while (i < abilityList.size() && !is) {
			if (abilityList[i] == anim) is = true;
			++i;
		}
		return is;
	}
private:
	std::vector<AnimationChain*> attacksList;	//pointer to the attack that you can use
	std::vector<AnimationChain*> abilityList = std::vector<AnimationChain*>(2);	//pointer to the abilities 
	std::vector<int> cooldowns = std::vector<int>(2);
	AnimationChain* activeAttack_ = nullptr;

	int multiplierTimer_ = -1;
	bool isMultiplierTimed = false;
	int timeCool = 0;
	//keys to use the attacks and abilities
	HID* inputSt_;
	//AbilitiesTimerFunction* abstimer;
};

