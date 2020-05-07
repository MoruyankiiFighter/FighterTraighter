#pragma once
#include "PhysicsTransform.h"
#include "Timer.h"
#include "App.h"
class Particle:public Component
{
public :
	Particle(PhysicsTransform* tr,Vector2D vel, uint32 lifetime):Component(ecs::Particle), tr_(tr), speed_(vel), lifetime_(lifetime+SDL_GetTicks())
	{}
	virtual ~Particle() {}
	void init() override 
	{
		Entity* e = entity_;
		tr_ = entity_->getComponent<PhysicsTransform>(ecs::Transform);
		tr_->setSpeed(speed_);
		SDL_TimerID id = Timer::Instance()->StartTimer(lifetime_, [e](Uint32 interval,void*data){e->getState()->getEntityManager().removeEntity(e);
		return (SDL_TimerCallback) 0; }, (void*)"Destruido");
	};
	
	/* Uint32 destroy(Uint32 interval, void* data)
	{
		entity_->getState()->getEntityManager().removeEntity(entity_);
		return 0;
	}*/
private :
	PhysicsTransform* tr_;
	uint32 lifetime_;
	Vector2D speed_;
};

