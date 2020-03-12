#include "Fight.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"
#include "MkWh00pAttacks.h"
#include "jute.h"

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
	//---------------------------------------------------------------

	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<PhysicsTransform>(Vector2D(10,10), Vector2D(10,10), 50, 50, 0,world);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
	e->addComponent<Jump>(-1000);
	e->addComponent<Crouch>();
	scene.push_back(e);	

	std::vector<Move*> vecMov = std::vector<Move*>(2);
	vecMov[0] = new Move(app_->getAssetsManager()->getJson(0)["NormalPunch"][0].as_int(), nullptr);
	vecMov[1] = new Move(app_->getAssetsManager()->getJson(0)["NormalPunch"][1].as_int(), nullptr);
	AnimationChain* testNP = new AnimationChain(vecMov);
	AnimationChain* testHP = new AnimationChain(vecMov);
	AnimationChain* testNK = new AnimationChain(vecMov);
	AnimationChain* testHK = new AnimationChain(vecMov);
	//solo creo un ataque, Attacks tiene otra constructora que le llegan 4 ataques y sus respectivas teclas
	e->addComponent<PlayerAttacks>(testNP, SDL_SCANCODE_Q, testHP, SDL_SCANCODE_E, testNK, SDL_SCANCODE_Z, testHK, SDL_SCANCODE_X);

	scene.push_back(e);	
	
	Entity* floor = new Entity();
	floor->addComponent<PhysicsTransform>(Vector2D(100, 600), Vector2D(0,0), 100, 100, 0, world, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
	scene.push_back(floor);
	
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
	delete world;
	delete debugInstance;
}
