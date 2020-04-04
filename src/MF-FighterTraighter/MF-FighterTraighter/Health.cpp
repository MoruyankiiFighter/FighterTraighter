#include "Health.h"
#include "PlayerState.h"
#include "Entity.h"

bool Health::LoseLife(unsigned int damage, int hitstun) {
	if (!entity_->getComponent<PlayerState>(ecs::PlayerState)->isGuarding()) {
		entity_->getComponent<PlayerState>(ecs::PlayerState)->goHitsun(hitstun);
		health_ -= damage;

		std::cout << health_;

		if (health_ > 0) {
			return true;
		}
		else
		{
			health_ = 0;
			std::cout << "memori" << endl;
			return false;
		}
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

