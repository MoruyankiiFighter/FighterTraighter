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
public:
	Fight(App* app);
	void init() override;
	virtual void handleInput() override;
	virtual ~Fight();
	Entity* giveMeTimerAb1() { return timerab1; };
	Entity* giveMeTimerAb2() { return timerab2; };
private:
	Entity* timerab1;
	Entity* timerab2;
};
