#pragma once
#include "GameState.h"
#include "Box2D\Box2D.h"
#include "PhysicsTransform.h"
#include "SDLDebugDraw.h"
#include "PunchingBagListener.h"
#include "Jump.h"
#include "PlayerAttacks.h"
#include <vector>


class Training: public GameState
{
	//	Collision filters for the b2d collision
	enum CollisionFilters : uint16 {
		BOUNDARY = 0x0001,
		PLAYER_1 = 0x0002,
		PLAYER_2 = 0x0004,
		P_BAG = 0X008,
		EVERYTHING = 0XFFFF
	};
public:
	//constructor
	Training(App* app);
	
	void init() override;
	virtual void handleInput() override;
	virtual void update() override;
	virtual void render() override;
	virtual ~Training();
private:
	std::vector<Move*> vecMov;
	b2World* world;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	PunchingBagListener* pbListener = nullptr;
};

