#include "Fight.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"
#include "FactoryMk.h"

Fight::Fight(App* app) : GameState(app)
{
	init();
}

void Fight::init()
{
	world = new b2World(b2Vec2(0.0, 9.81));//inicializamos el mundo para las fisicas de b2D
	//---------Debuggear hitbox-------------------------------------------
	debugInstance = new SDLDebugDraw(app_->getRenderer());
	world->SetDebugDraw(debugInstance);
	debugInstance->SetFlags(b2Draw::e_aabbBit);
	//---------------------------------------------------------------
	
	Entity* floor = giveMeManager().addEntity();
	floor->addComponent<PhysicsTransform>(Vector2D(400, 600), Vector2D(0,0), 800, 100, 0, world, BOUNDARY, EVERYTHING, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));	

	FactoryMk::addMkToGame(app_, this, world, 1, { SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_Q, SDL_SCANCODE_E, SDL_SCANCODE_Z, SDL_SCANCODE_X },
		PLAYER_1, PLAYER_2 | BOUNDARY);
	FactoryMk::addMkToGame(app_, this, world, -1, { SDL_SCANCODE_J, SDL_SCANCODE_L, SDL_SCANCODE_I, SDL_SCANCODE_K, SDL_SCANCODE_U, SDL_SCANCODE_O, SDL_SCANCODE_N, SDL_SCANCODE_M },
		PLAYER_2, PLAYER_1 | BOUNDARY);
}

void Fight::handleInput()
{
	if (app_->getInputManager()->isKeyDown(SDLK_p)) {
		app_->getStateMachine()->pushState(new PauseMenu(app_));
	}
	GameState::handleInput();
}

void Fight::update()
{
	GameState::update();
	app_->getHitboxMng()->update();		//es posible que esto sea un sistema
	world->Step(1.0/30,8,3);//update box2d
	
}

void Fight::render() {
	SDL_RenderClear(app_->getRenderer());
	GameState::render();
	world->DrawDebugData();
	SDL_RenderPresent(app_->getRenderer());
}

Fight::~Fight()
{
	for (auto vec : vecMov) {
		delete vec;

	}
	delete world;
	delete debugInstance;
}

