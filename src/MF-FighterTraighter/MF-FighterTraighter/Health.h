#pragma once
#include "Component.h"
class Health : public Component
{
private:
	int health;
	int maxHealth;
public:

	Health(int health_) :Component(ecs::Health), maxHealth(health_)
	{
		health = maxHealth;
	};
	//virtual ~Health();
	//si pierdes vida devuelve true si no es porque estas muerto y devuelve false
	bool LoseLife(int damage);
	//sumas una cantidad a la vida sin pasar los limites
	void GainLife(int life);
	//set la vida 
	void setLife(int health);
	//return la vida 
	int getLife();

};

