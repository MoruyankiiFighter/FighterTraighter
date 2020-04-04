#pragma once
#include "Component.h"
class Health : public Component
{
public:

	//constructor
	Health(int health) :Component(ecs::Health), maxHealth_(health), health_(health){};
	virtual ~Health() {}
	
	// lose damage life (life-=damage) and check if life<0 to be dead
	bool LoseLife(unsigned int  damage, int hitstun);

	// add cuantity
	void GainLife(unsigned int cuantity);
	
	//set health_=newhealth
	void setLife(int newhealth);
	
	//return the current health(health_)
	int getLife();

private:
	int health_; //current health
	int maxHealth_; //max health

};

