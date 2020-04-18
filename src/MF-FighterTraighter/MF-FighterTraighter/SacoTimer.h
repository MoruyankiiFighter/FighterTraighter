#pragma once
#include "Component.h"
#include "PlayerData.h"
class SacoTimer :
	public Component
{
public:
	//constructor
	SacoTimer(int timeLimit) : Component(ecs::SacoTimer), timeLimit_(timeLimit) {};
	
	//destructor
	~SacoTimer() {};
	
	//method overrided from Component
	virtual void init() override { startTime_ = SDL_GetTicks(); };
	virtual void update() override;
private:
	int timeLimit_;
	int startTime_=0;
	int currTime_ = 0;
	PlayerData* player; //puntero a playerdata para 
	vector<string> abilities; //meter todas las habilidades en la constructora? Y que cuando acabe el saco salgan todas
							// en pantalla y se pueda elegir las habilidades
};

