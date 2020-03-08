#pragma once
#include "Component.h"
#include "Attack.h"
#include <vector>
//component that have all the attacks that you have
class Attacks: public Component
{
public:
	//testing
	Attacks(Attack* highFist, SDL_Scancode key1) :Component(ecs::Attacks)
		
	{
		attacksList.push_back(highFist);
		highFistKey = key1;
	}
	Attacks(Attack* highFist, SDL_Scancode key1, Attack* lowFist, SDL_Scancode key2, Attack* highKick, SDL_Scancode key3,
		Attack* lowKick, SDL_Scancode key4/*, Hability* hability1, SDL_Scancode key5, Hability* hability2, SDL_Scancode key6*/);
	virtual ~Attacks();
	//methods to change your habilities
	/*void addFirstHability(Hability* hab);//add first hability
	void addSecondHability(Hability* hab);*///add second hability
	void handleInput() override;
private:
	std::vector<Attack*> attacksList;//pointer to the attack that you can use
	//std::list<Hability*> habilityList;//pointer to the habilities 

	//keys to use the attacks and habilities
	SDL_Scancode highFistKey, lowFistKey, highKickKey,
		 lowKickKey/*, hability1Key, hability2Key*/;
};

