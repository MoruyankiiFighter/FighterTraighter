#include "Fight.h"
#include "Entity.h"
#include "Transform.h"
#include "PlayerController.h"
#include "RenderImage.h"



Fight::Fight(App* app) : GameState(app)
{
		init();
}

void Fight::init()
{
	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<Transform>(Vector2D(), Vector2D(), 50, 50, 0);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(app_->getTextureManager()->getTexture(0));
	scene.push_back(e);
}

void Fight::update()
{
	GameState::update();
	Vector2D v = scene.front()->getComponent<Transform>(ecs::Transform)->getPosition(); // Temporary testing
	std::cout << v.getX() << std::endl; // Temporary testing
}

void Fight::render() {
	SDL_RenderClear(app_->getRenderer());
	GameState::render();
	scene.front()->getComponent<RenderImage>(ecs::RenderImage)->render();
	SDL_RenderPresent(app_->getRenderer());
}

Fight::~Fight()
{
}
