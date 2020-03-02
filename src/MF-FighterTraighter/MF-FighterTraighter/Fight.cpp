#include "Fight.h"
#include "Entity.h"
#include "Transform.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Collider.h"


Fight::Fight(App* app) : GameState(app)
{
		init();
}

void Fight::init()
{
	string filePath = "../../../../assets/Assets/personaje.png";
	Texture* tex = new Texture(app_->getRenderer(), filePath.c_str() , 1, 1);
	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<Transform>(Vector2D(), Vector2D(), 5, 5, 0);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(tex);
	e->addComponent<Collider>(e);
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
