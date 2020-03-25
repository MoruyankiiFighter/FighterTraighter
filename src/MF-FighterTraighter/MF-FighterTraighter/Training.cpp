#include "Training.h"
#include "Entity.h"
#include "EntityManager.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"
#include "SacoTimer.h"
#include "FactoryMk.h"

Training::Training(App* app) : GameState(app)
{
	init();
}

void Training::init()
{
	world = new b2World(b2Vec2(0.0, 9.81));//inicializamos el mundo para las f�sicas de b2D
	//---------Debuggear hitbox-------------------------------------------
	debugInstance = new SDLDebugDraw(app_->getRenderer());
	world->SetDebugDraw(debugInstance);
	debugInstance->SetFlags(b2Draw::e_aabbBit);
	//---------Add collision listeners
	pbListener = new PunchingBagListener();
	world->SetContactListener(pbListener);
	//---------------------------------------------------------------

	FactoryMk::addMkToGame(app_, this, world, PLAYER_1, BOUNDARY | P_BAG);

	Entity* saco = getEntityManager().addEntity();
	saco->addComponent<PhysicsTransform>(Vector2D(250, 500), Vector2D(10, 10), 35, 100, 0, world, P_BAG, PLAYER_1 | PLAYER_2, false);
	saco->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
	//saco->addComponent<SacoTimer>(5000);
	saco->addComponent<PunchingBagCollision>();

	Entity* floor = getEntityManager().addEntity();
	floor->addComponent<PhysicsTransform>(Vector2D(100, 600), Vector2D(0, 0), 1000, 100, 0, world, BOUNDARY, EVERYTHING, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
}

void Training::handleInput()
{
	if (app_->getInputManager()->isKeyDown(SDLK_p)) {
		app_->getStateMachine()->pushState(new PauseMenu(app_));
	}
	GameState::handleInput();
}

void Training::update()
{
	app_->getHitboxMng()->update();		//es posible que esto sea un sistema
	GameState::update();
	world->Step(1.0 / 30, 8, 3);//update box2d+
}


void Training::render() {
	SDL_RenderClear(app_->getRenderer());
	GameState::render();
	world->DrawDebugData();
	SDL_RenderPresent(app_->getRenderer());
}

Training::~Training()
{
	for (auto vec : vecMov) {
		delete vec;
	}
	delete world;
	delete debugInstance;
	delete pbListener;
}