#include "Training.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"
#include "MkWh00pAttacks.h"
#include "SacoTimer.h"

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
	string filePath = "../../../../assets/Assets/personaje.png";
	Texture* tex = new Texture(app_->getRenderer(), filePath.c_str(), 1, 1);

	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<PhysicsTransform>(Vector2D(10, 10), Vector2D(10, 10), 50, 50, 0, world);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(tex);
	e->addComponent<Jump>(-1000);
	e->addComponent<Crouch>();
	e->addComponent<creatorBody>(e->getComponent<Transform>(ecs::Transform), world);
	

	vecMov = std::vector<Move*>(2);
	vecMov[0] = new Move(100, nullptr, e);
	vecMov[1] = new Move(50, nullptr, e);
	AnimationChain* testMove = new AnimationChain(vecMov);
	//solo creo un ataque, Attacks tiene otra constructora que le llegan 4 ataques y sus respectivas teclas
	e->addComponent<PlayerAttacks>(testMove, SDL_SCANCODE_Q, testMove, SDL_SCANCODE_E, testMove, SDL_SCANCODE_Z, testMove, SDL_SCANCODE_X);


	scene.push_back(e);

	Entity* saco = new Entity();
	saco->addComponent<PhysicsTransform>(Vector2D(250, 500), Vector2D(10, 10), 35, 100, 0, world, false);
	saco->addComponent<RenderImage>(tex);
	//saco->addComponent<SacoTimer>(5000);
	saco->addComponent<PunchingBagCollision>();
	scene.push_back(saco);

	Entity* floor = new Entity();
	floor->addComponent<PhysicsTransform>(Vector2D(100, 600), Vector2D(0, 0), 1000, 100, 0, world, false);
	floor->addComponent<RenderImage>(tex);
	scene.push_back(floor);

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
	delete pbListener;
}