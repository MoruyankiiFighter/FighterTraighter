#pragma once
#include "Component.h"
class Health : public Component
{
public:

	//constructor
	Health(int health) :Component(ecs::Health), maxHealth_(health), health_(health){};
	virtual ~Health() {}
	
	// lose damage life (life-=damage) and check if life<0 to be dead
	bool LoseLife( double  damage);

	// add cuantity
	void GainLife(unsigned int cuantity);
	
	//set health_=newhealth
	void setLife(int newhealth);
	
	//return the current health(health_)
	int getLife();
	inline int getMaxHealth() { return maxHealth_; }

	int getHealth() { return health_; }

private:
	double health_; //current health
	int maxHealth_; //max health

};

