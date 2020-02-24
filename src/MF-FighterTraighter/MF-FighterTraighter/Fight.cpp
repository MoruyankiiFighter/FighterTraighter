#include "Fight.h"
#include "Entity.h"
#include "Transform.h"
#include "PlayerController.h"

Fight::Fight(App* app) : GameState(app)
{
	init();
}

void Fight::init()
{
	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<Transform>();
	e->addComponent<PlayerController>();
	scene.push_back(e);
}

void Fight::update()
{
	GameState::update();
	Vector2D v = scene.front()->getComponent<Transform>(ecs::Transform)->getPosition(); // Temporary testing
	std::cout << v.getX() << std::endl; // Temporary testing
}

Fight::~Fight()
{
}
