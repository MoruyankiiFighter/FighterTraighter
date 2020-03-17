#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "Jump.h"
#include "PlayerAttacks.h"

class Fight: public GameState
{
public:
	//constructor
	Fight(App* app);
	//destructor
	virtual ~Fight();

	//methods overrided from GameState
	void init() override;
	virtual void handleInput() override;
	virtual void update() override;
	virtual void render() override;

private:

	std::vector<Move*> vecMov; 
	b2World* world=nullptr;
	SDLDebugDraw* debugInstance = nullptr;
};

