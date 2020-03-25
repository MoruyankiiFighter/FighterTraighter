#include "Fight.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"
#include "FactoryMk.h"

//constructor
Fight::Fight(App* app) : GameState(app)
{
	init();
}

//destructor
Fight::~Fight(){
	
	for (auto vec : vecMov) {
		delete vec;
		vec = nullptr;
	}
	delete world;
	world = nullptr;
	delete debugInstance;
	debugInstance = nullptr;
}

//create th world and the entitys
void Fight::init()
{
	world = new b2World(b2Vec2(0.0, 9.81));//inicializamos el mundo para las f�sicas de b2D
	//---------Debuggear hitbox-------------------------------------------
	debugInstance = new SDLDebugDraw(app_->getRenderer());
	world->SetDebugDraw(debugInstance);
	debugInstance->SetFlags(b2Draw::e_aabbBit);
	//---------------------------------------------------------------
	
	Entity* floor = getEntityManager().addEntity();
	floor->addComponent<PhysicsTransform>(Vector2D(400, 600), Vector2D(0,0), 800, 100, 0, world, BOUNDARY, EVERYTHING, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));	

	FactoryMk::addMkToGame(app_, this, world, PLAYER_1, PLAYER_2 | BOUNDARY);
}

//handle input
void Fight::handleInput()
{
	if (app_->getInputManager()->isKeyDown(SDLK_p)) {
		app_->getStateMachine()->pushState(new PauseMenu(app_));
	}
	GameState::handleInput();
}

//update the hitboox manager and the entitys
void Fight::update()
{
	GameState::update();
	app_->getHitboxMng()->update();		//es posible que esto sea un sistema
	world->Step(1.0/30,8,3);//update box2d
	
}

//render the entitys and their debug
void Fight::render() {
	SDL_RenderClear(app_->getRenderer());
	GameState::render();
	world->DrawDebugData();
	SDL_RenderPresent(app_->getRenderer());
}

