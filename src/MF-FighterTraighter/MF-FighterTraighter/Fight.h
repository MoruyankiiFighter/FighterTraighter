#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "Jump.h"
#include "PlayerAttacks.h"
#include "PunchingBagListener.h"
#include "Hitbox.h"



class Fight: public GameState
{
	//	Collision filters for the b2d collision
	enum CollisionFilters : uint16 {
		BOUNDARY = 0x0001,
		PLAYER_1 = 0x0002,
		PLAYER_2 = 0x0004,
		EVERYTHING = 0XFFFF
	};
public:
	//constructor
	Fight(App* app);
	
	//destructor
	virtual ~Fight();

	//methods overrided from the base class, GameState
	void init() override;
	virtual void handleInput() override;
	virtual void update() override;
	virtual void render() override;
private:
	
	std::vector<Move*> vecMov;//until we have factories to create characters
	b2World* world=nullptr;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	PunchingBagListener* pbListener = nullptr;
	
};