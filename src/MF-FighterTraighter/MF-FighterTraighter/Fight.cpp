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
	world = new b2World(b2Vec2(0.0, 9.81));//inicializamos el mundo para las f�sicas de b2D
	//---------Debuggear hitbox-------------------------------------------
	debugInstance = new SDLDebugDraw(app_->getRenderer());
	world->SetDebugDraw(debugInstance);
	debugInstance->SetFlags(b2Draw::e_aabbBit);
	pbListener = new PunchingBagListener();
	world->SetContactListener(pbListener);
	//---------------------------------------------------------------
	
	Entity* floor = giveMeManager().addEntity();
	floor->addComponent<PhysicsTransform>(Vector2D(400, 600), Vector2D(0,0), 800, 100, 0, world, BOUNDARY, EVERYTHING, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));	

	FactoryMk::addMkToGame(app_, this, world, PLAYER_1, PLAYER_2 | BOUNDARY);
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

