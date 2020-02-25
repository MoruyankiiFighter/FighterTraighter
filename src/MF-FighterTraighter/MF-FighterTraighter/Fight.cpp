#include "Fight.h"
#include "Entity.h"
#include "Transform.h"
#include "PlayerController.h"
#include "RenderImage.h"



Fight::Fight(App* app, SDL_Renderer* rend) : GameState(app, rend)
{
		init();
}

void Fight::init()
{
	Texture* tex = new Texture(rend_, "../../../assets/Assets/personaje.png" , 1, 1);
	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<Transform>(Vector2D(), Vector2D(), 50, 50, 0);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(tex);
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
