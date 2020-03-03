#include "Fight.h"
#include "Entity.h"
#include "PlayerController.h"
#include "RenderImage.h"
#include "Jump.h"


Fight::Fight(App* app) : GameState(app)
{
		init();
}

void Fight::init()
{
	world = new b2World(b2Vec2(0.0, 981));//inicializamos el mundo para las físicas de b2D

	string filePath = "../../../../assets/Assets/personaje.png";
	Texture* tex = new Texture(app_->getRenderer(), filePath.c_str() , 1, 1);
	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	pTR_ = e->addComponent<PhysicsTransform>(Vector2D(10,10), Vector2D(10,10), 5, 5, 0,world);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(tex);
	e->addComponent<Jump>(-10000);
	scene.push_back(e);	
}

void Fight::update()
{
	GameState::update();
	//Vector2D v;v = scene.front()->getComponent<PhysicsTransform>(ecs::PhysicsTransform)->getPosition(); // Temporary testing
	//std::cout << v.getX() << std::endl; // Temporary testing
	world->Step(1.0/30,8,3);//update box2d
	//scene.front()->getComponent<Transform>(ecs::Transform)->getPosition();
	//
	/*if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_W)) {
		Vector2D v = pTR_->getPosition();
		
		std::cout << v.getX() << std::endl << v.getY() << std::endl;
	}*/
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
