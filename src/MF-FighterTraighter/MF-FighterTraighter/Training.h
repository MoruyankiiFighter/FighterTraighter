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
public:
	//constructor
	Training(App* app);
	//destructor
	virtual ~Training();
	//methods overrided from Gamestate
	//init the components and create the entities
	void init() override;
	//handle the input of gamestate and if ESC is pressed set the pause state
	virtual void handleInput() override;

	
	static void skillSelection(App* app);

private:
	std::vector<Move*> vecMov;
	b2World* world= nullptr;
	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
	ResetJumpListener* resJumpListener = nullptr;

};

