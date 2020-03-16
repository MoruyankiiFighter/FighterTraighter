#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "PunchingBagListener.h"

class Training: public GameState
{
public:
	//constructor	
	Training(App* app);
	//destructor
	virtual ~Training();

	//methods overrided from GameState
	void init() override;
	virtual void update() override;
	virtual void render() override;
private:
	b2World* world=nullptr;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	PunchingBagListener* pbListener = nullptr;
};

