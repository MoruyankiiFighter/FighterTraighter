#include "Health.h"
#include "PlayerState.h"
#include "Entity.h"

bool Health::LoseLife(unsigned int damage) {
	bool toReturn = false;

	PlayerData* data = entity_->getComponent<PlayerData>(ecs::PlayerData);
	if (data) {
		health_ -= damage * data->geDefense();
		if (!isMultiplierTimed) entity_->getComponent<PlayerData>(ecs::PlayerData)->setDefense(1);
	}
	else {
		health_ -= damage;
	}

	if (health_ > 0) {
		toReturn = true;
	}
	else
	{
		health_ = 0;
		std::cout << "memori" << endl;
		toReturn = false;
	}

	std::cout << health_ << endl;
	return toReturn;
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

