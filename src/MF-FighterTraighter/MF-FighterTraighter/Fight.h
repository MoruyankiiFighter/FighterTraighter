#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "Jump.h"
#include "PlayerAttacks.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"
#include "FactoryMk.h"
#include "ResetJumpListener.h"

class Fight : public GameState
{
	//	Collision filters for the b2d collision
	enum CollisionFilters : uint16 {
		BOUNDARY = 0x0001,
		PLAYER_1 = 0x0002,
		PLAYER_2 = 0x0004,
		WALL = 0x0006,
		EVERYTHING = 0XFFFF
	};
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
	std::vector<Move*> vecMov;//until we have factories to create characters
	b2World* world;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	ResetJumpListener* resJumpListener = nullptr;
};
