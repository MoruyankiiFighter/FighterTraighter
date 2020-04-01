#include "Health.h"


bool Health::LoseLife(unsigned int  damage) {
	health_ -= damage;
	std::cout << health_;

	if (health_ > 0) {		
		return true;
	}
	else
	{
		health_ = 0;
		std::cout << "memori";
		return false;
	}
}


int Health::getLife()
{
	return health_;
}
void  Health::setLife(int health_)
{
	health_ = health_;
}
void  Health::GainLife(unsigned int life)
{
	health_ += life;

	if (health_>maxHealth_)
	{
		health_ = maxHealth_;
	}
	std::cout << health_;

}

