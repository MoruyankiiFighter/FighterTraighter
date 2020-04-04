#pragma once
#include "Component.h"
#include "AnimationChain.h"
#include <vector>
#include "PlayerState.h"
//component that have all the attacks that you have
class PlayerAttacks : public Component 
{
public:
	//testing
	PlayerAttacks(AnimationChain* highFist, SDL_Scancode key1) :Component(ecs::PlayerAttacks)
		
	{
		attacksList.push_back(highFist);
		highFistKey = key1;
	}
	PlayerAttacks(AnimationChain* highFist , AnimationChain* airHighFist, SDL_Scancode key1, AnimationChain* lowFist, AnimationChain* airLowFist, 
		SDL_Scancode key2, AnimationChain* highKick, AnimationChain* airHighKick, SDL_Scancode key3, AnimationChain* lowKick, AnimationChain* airLowKick, 
		SDL_Scancode key4/*, Hability* hability1, SDL_Scancode key5, Hability* hability2, SDL_Scancode key6*/);
	virtual ~PlayerAttacks();
	virtual void update() override { 
		if (activeAttack_ != nullptr) { 
			if (activeAttack_->update()) {
				activeAttack_ = nullptr;
				if (entity_->getComponent<PlayerState>(ecs::PlayerState)->isGrounded()) {
					entity_->getComponent<PlayerState>(ecs::PlayerState)->goIdle();
				}
				else {
					entity_->getComponent<PlayerState>(ecs::PlayerState)->goJumping();
				}
			}
		}
	};
	//methods to change your habilities
	/*void addFirstHability(Hability* hab);//add first hability
	void addSecondHability(Hability* hab);*///add second hability
	void handleInput() override;

	void interruptAttack();
private:
	std::vector<AnimationChain*> attacksList;//pointer to the attack that you can use
	//std::list<Hability*> habilityList;//pointer to the habilities 
	AnimationChain* activeAttack_=nullptr;

	//keys to use the attacks and habilities
	SDL_Scancode highFistKey, lowFistKey, highKickKey, lowKickKey;
};

