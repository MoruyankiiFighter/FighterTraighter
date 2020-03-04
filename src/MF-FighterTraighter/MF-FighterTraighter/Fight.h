#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"

class Fight: public GameState
{
public:
	Fight(App* app);
	void init() override;
	virtual void update() override;
	virtual void render() override;
	virtual ~Fight();
private:


	b2World* world;
	//Debugging physics transform
	//Transform* pTR_ = nullptr;
};

