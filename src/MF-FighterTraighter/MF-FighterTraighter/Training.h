#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "PunchingBagListener.h"

class Training: public GameState
{
public:
	Training(App* app);
	void init() override;
	virtual void update() override;
	virtual void render() override;
	virtual ~Training();
private:
	b2World* world;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	PunchingBagListener* pbListener = nullptr;

};

