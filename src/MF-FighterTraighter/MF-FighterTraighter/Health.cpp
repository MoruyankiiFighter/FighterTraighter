#include "Health.h"


bool Health::LoseLife(unsigned int  damage) {
	health -= damage;

	if (health > 0) {		
		return true;
	}
	else
	{
		std::cout << "memori";
		return false;
	}
}


int Health::getLife()
{
	return health;
}
void  Health::setLife(int health_)
{
	health = health_;
}
void  Health::GainLife(unsigned int life)
{
	health += life;

	if (health>maxHealth)
	{
		health = maxHealth;
	}
}

