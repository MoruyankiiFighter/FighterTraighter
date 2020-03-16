#pragma once
#include "Component.h"
class Health : public Component
{
private:
	int health=0;
	int maxHealth=0;
public:

	//constructor
	Health(int health_) :Component(ecs::Health), maxHealth(health_)
	{
		health = maxHealth;
	};

	//destructor
	virtual ~Health() {}
	
	//lose life, returns false if health<=0
	bool LoseLife(unsigned int  damage);
	
	//gain life
	void GainLife(unsigned int life);
	
	//set life equal health (life = health)
	void setLife(int newLife);

	//return current life 
	int getLife();

};

