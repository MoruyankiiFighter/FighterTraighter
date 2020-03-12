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
	Fight(App* app);
	void init() override;
	virtual void handleInput() override;
	virtual void update() override;
	virtual void render() override;
	virtual ~Fight();
private:
	std::vector<Move*> vecMov;//until we have factories to create characters
	b2World* world;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	//Debugging physics transform
	//Transform* pTR_ = nullptr;
};

