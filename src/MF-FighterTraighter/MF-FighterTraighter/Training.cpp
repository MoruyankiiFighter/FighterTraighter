#include "Training.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"
#include "SacoTimer.h"
#include "FactoryMk.h"
#include "PunchingBagOnHit.h"
#include "FloorOnHit.h"
#include "Collider.h"

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


	FactoryMk::addMkToGame(app_, this, world, 1, { SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_Q, SDL_SCANCODE_E, SDL_SCANCODE_Z, SDL_SCANCODE_X });
	//FactoryMk::addMkToGame(app_, this, world, -1, { SDL_SCANCODE_J, SDL_SCANCODE_L, SDL_SCANCODE_I, SDL_SCANCODE_K, SDL_SCANCODE_U, SDL_SCANCODE_O, SDL_SCANCODE_N, SDL_SCANCODE_M },
		//PLAYER_2, PLAYER_1 | BOUNDARY);

	double floorWidth_ = 800, floorHeight_ = 100,
			pbWidth_ = 35, pbHeight_ = 100;

	Entity* punchingBag = entManager_.addEntity();
	PhysicsTransform* pBpT = punchingBag->addComponent<PhysicsTransform>(Vector2D(250, 500), Vector2D(10, 10), pbWidth_, pbHeight_, 0, world, false);
	Collider* pbC = punchingBag->addComponent<Collider>(pbWidth_, pbHeight_, pBpT->getBody());
	app_->getHitboxMng()->addMainHitbox(pbC->getCollider());
	punchingBag->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
	punchingBag->addComponent<PunchingBagOnHit>();
	//saco->addComponent<SacoTimer>(5000);

	Entity* floor = entManager_.addEntity();
	PhysicsTransform* FpT = floor->addComponent<PhysicsTransform>(Vector2D(100, 600), Vector2D(0, 0), floorWidth_, floorHeight_, 0, world, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));	
	Collider* fC = floor->addComponent<Collider>(floorWidth_, floorHeight_, FpT->getBody());
	app_->getHitboxMng()->addFloorHitbox(fC->getCollider());
	floor->addComponent<FloorOnHit>();

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
	world->Step(1.0 / 30, 8, 3);//update box2d
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
}