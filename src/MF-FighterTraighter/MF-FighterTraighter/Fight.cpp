#include "Fight.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"

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

	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<PhysicsTransform>(Vector2D(10,10), Vector2D(10,10), 50, 50, 0,world);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
	e->addComponent<Jump>(-1000);
	e->addComponent<Crouch>();

	vecMov = std::vector<Move*>(2);
	vecMov[0] = new Move(100, nullptr,e);
	vecMov[1] = new Move(50, nullptr,e);
	AnimationChain* testMove = new AnimationChain(vecMov);
	//solo creo un ataque, Attacks tiene otra constructora que le llegan 4 ataques y sus respectivas teclas
	//Este comentario es tan sólo para el commit xddddddddddddddddddddddddddddddddd
	e->addComponent<PlayerAttacks>(testMove, SDL_SCANCODE_Q, testMove, SDL_SCANCODE_E, testMove, SDL_SCANCODE_Z, testMove, SDL_SCANCODE_X);
	
	entManager_.getScene().push_back(e);
	
	Entity* floor = new Entity();
	floor->addComponent<PhysicsTransform>(Vector2D(100, 600), Vector2D(0,0), 100, 100, 0, world, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
	entManager_.getScene().push_back(floor);
	
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
	app_->getHitboxMng()->update();		//es posible que esto sea un sistema
	GameState::update();
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

