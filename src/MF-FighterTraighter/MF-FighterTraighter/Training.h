#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "Jump.h"
#include "PlayerAttacks.h"
#include <vector>
#include "ResetJumpListener.h"


class Training: public GameState
{
	//	Collision filters for the b2d collision
	enum CollisionFilters : uint16 {
		BOUNDARY = 0x0001,
		PLAYER_1 = 0x0002,
		PLAYER_2 = 0x0004,
		WALL = 0x0006,
		P_BAG = 0X008,
		EVERYTHING = 0XFFFF
	};
public:
	//constructor
	Training(App* app);
	//destructor
	virtual ~Training();
	//methods overrided from Gamestate
	//init the components and create the entitys
	void init() override;
	//handle the input of gamestate and if ESC is pressed set the pause state
	virtual void handleInput() override;
	//update the hitbox manager
	virtual void update() override;
	//render the gamestate entitys if needed and the hitboxes for debuging
	virtual void render() override;
	
	static void skillSelection(App* app);

private:
	std::vector<Move*> vecMov;
	b2World* world= nullptr;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	ResetJumpListener* resJumpListener = nullptr;

};

