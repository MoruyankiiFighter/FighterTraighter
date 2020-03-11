#include "Fight.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Collider.h"
#include "Jump.h"
#include "PauseMenu.h"
#include "Crouch.h"
#include "MkWh00pAttacks.h"

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
	listener = new myListener(this);
	world->SetContactListener(listener); 
	//---------------------------------------------------------------

	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<PhysicsTransform>(Vector2D(10,400), Vector2D(10,10), 50, 50, 0,world);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
	e->addComponent<Jump>(-1000);
	e->addComponent<Crouch>();

	 vecMov = std::vector<Move*>(2);
	vecMov[0] = new Move(100, nullptr);
	vecMov[1] = new Move(50, nullptr);
	AnimationChain* testMove = new AnimationChain(vecMov);
	//solo creo un ataque, Attacks tiene otra constructora que le llegan 4 ataques y sus respectivas teclas
	e->addComponent<PlayerAttacks>(testMove, SDL_SCANCODE_Q, testMove, SDL_SCANCODE_E, testMove, SDL_SCANCODE_Z, testMove, SDL_SCANCODE_X);
	
	scene.push_back(e);	
	
	Entity* floor = new Entity();
	floor->addComponent<PhysicsTransform>(Vector2D(100, 600), Vector2D(0,0), 100, 100, 0, world, false);
	floor->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(0));
	scene.push_back(floor);
	//world->DestroyBody(scene.front()->getComponent<PhysicsTransform>(ecs::Transform)->getBody());
	testCreateBody();
}

void Fight::test(b2Body* body) {
	bodytest = body;
	
}
void Fight::prueba() {
	b2BodyDef bodydef;
	bodydef.position.Set(50, 50);
	//position_ = bodydef.position();
	bodydef.type = b2_dynamicBody;
	Fight::body_ = world->CreateBody(&bodydef);
	b2PolygonShape shape;
	shape.SetAsBox(50 * 1 / 2, 50 * 1 / 2);
	//shape.s
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 0;			//densidad 0, para que no cambie segun el ancho y el alto por ahora

	body_->CreateFixture(&fixturedef);
}
void Fight::testCreateBody() {
	//prueba();

	crear = true;
	
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
	if (bodytest != nullptr) {
		cout << "destruyo cuerpo"<<endl;
		world->DestroyBody(bodytest);
		bodytest = nullptr;
	}
	if (crear) {
		crear = false;
		prueba();
	}
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
	delete listener;
}
