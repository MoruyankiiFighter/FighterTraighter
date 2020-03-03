#include "Fight.h"
#include "Entity.h"
#include "PhysicsTransform.h"
#include "PlayerController.h"
#include "RenderImage.h"



Fight::Fight(App* app) : GameState(app)
{
		init();
}

void Fight::init()
{
	world = new b2World(b2Vec2(0.0, 2.81));

	string filePath = "../../../../assets/Assets/personaje.png";
	Texture* tex = new Texture(app_->getRenderer(), filePath.c_str() , 1, 1);
	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<PhysicsTransform>(Vector2D(10,10), Vector2D(10,10), 5, 5, 0,world);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(tex);
	scene.push_back(e);

	

}

void Fight::update()
{
	GameState::update();
	//Vector2D v;v = scene.front()->getComponent<PhysicsTransform>(ecs::PhysicsTransform)->getPosition(); // Temporary testing
	//std::cout << v.getX() << std::endl; // Temporary testing
	world->Step(1.0/30,8,3);//update box2d
	scene.front()->getComponent<PhysicsTransform>(ecs::PhysicsTransform)->getPosition();
	//
	 if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_W)) {
		 std::cout  << std::endl;
	}
	//scene.front()->getComponent<Transform>(ecs::Transform)->setPosition(body_->GetPosition().x, body_->GetPosition().y);

}

void Fight::render() {
	SDL_RenderClear(app_->getRenderer());
	GameState::render();
	scene.front()->getComponent<RenderImage>(ecs::RenderImage)->render();
	SDL_RenderPresent(app_->getRenderer());

}

Fight::~Fight()
{
	delete world;
}
