#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "Jump.h"
#include "PlayerAttacks.h"
#include "PunchingBagListener.h"
#include "Hitbox.h"

//	Collision filters for the b2d collision
enum CollisionFilters : uint16 {
	TERRAIN = 0x0001,
	PLAYER_1 = 0x0002,
	PLAYER_2 = 0x0004
};

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
	PunchingBagListener* pbListener = nullptr;
	//Debugging physics transform
	//Transform* pTR_ = nullptr;
};

