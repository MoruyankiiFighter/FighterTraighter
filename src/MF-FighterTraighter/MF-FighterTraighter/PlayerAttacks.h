#pragma once
#include "Component.h"
#include "AnimationChain.h"
#include <vector>
#include "PlayerState.h"
//component that have all the attacks that you have
class PlayerAttacks : public Component 
{
public:
	
	PlayerAttacks(AnimationChain* highFist , AnimationChain* airHighFist, SDL_Scancode key1, AnimationChain* lowFist, AnimationChain* airLowFist, 
		SDL_Scancode key2, AnimationChain* highKick, AnimationChain* airHighKick, SDL_Scancode key3, AnimationChain* lowKick, AnimationChain* airLowKick, 
		SDL_Scancode key4, SDL_Scancode key5, SDL_Scancode key6);
	virtual ~PlayerAttacks();
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
			//else if (entity_->getComponent<PlayerState>(ecs::PlayerState)->isHitstun()) interruptAttack(); <-- Esto es inútil (nunca va a estar atacando y ser hitstun)
		}
	};
	void handleInput() override;
	void setAbility(AnimationChain* newAbility, int index);
	void interruptAttack();
private:
	std::vector<AnimationChain*> attacksList;//pointer to the attack that you can use
	std::vector<AnimationChain*> abilityList = std::vector<AnimationChain*>(2);//pointer to the habilities 
	AnimationChain* activeAttack_=nullptr;

	//keys to use the attacks and habilities
	SDL_Scancode highFistKey, lowFistKey, highKickKey, lowKickKey;
	SDL_Scancode abilityKey1, abilityKey2;
};

