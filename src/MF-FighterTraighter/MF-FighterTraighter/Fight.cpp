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
	string filePath = "../../../../assets/Assets/personaje.png";
	Texture* tex = new Texture(app_->getRenderer(), filePath.c_str() , 1, 1);
	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	e->addComponent<Transform>(Vector2D(), Vector2D(), 5, 5, 0);
	e->addComponent<PlayerController>();
	e->addComponent<RenderImage>(tex);
	scene.push_back(e);

	world = new b2World(b2Vec2(0.0, 2.81));
	body_=addRect(10, 5, 15, 15);
	body2_ = addRect(1000, 500, 5000, 15,false);//estatico

}

void Fight::update()
{
	GameState::update();
	Vector2D v = scene.front()->getComponent<Transform>(ecs::Transform)->getPosition(); // Temporary testing
	//std::cout << v.getX() << std::endl; // Temporary testing
	world->Step(1.0/30,8,3);//update box2d
	std::cout << body_->GetPosition().x<<endl;
	std::cout << body_->GetPosition().y<<endl;

	//
	 if (app_->getInputManager()->isKeyDown(SDL_SCANCODE_W)) {
		 body_->ApplyLinearImpulse(b2Vec2(0,-300), body_->GetWorldCenter(),true);

	}
	scene.front()->getComponent<Transform>(ecs::Transform)->setPosition(body_->GetPosition().x, body_->GetPosition().y);

}

b2Body* Fight:: addRect(int x, int y, int w, int h, bool dyn) {
	//bodydef (position, type)
	//world->createBody
	//fixturedef (shape)
	//body->createFixture
	b2BodyDef bodydef;
	bodydef.position.Set(x, y);
	if (dyn)  bodydef.type = b2_dynamicBody;
	b2Body* body=world->CreateBody(&bodydef);
	b2PolygonShape shape;
	shape.SetAsBox(w / 2, h / 2);
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 1.0;

	body->CreateFixture(&fixturedef);
	return body;
}
void drawSquare(b2Vec2 points[4], b2Vec2& GetWorldCenter(), float32 GetAngle())
{

}
void Fight::render() {
	SDL_RenderClear(app_->getRenderer());
	GameState::render();
	scene.front()->getComponent<RenderImage>(ecs::RenderImage)->render();
	SDL_RenderPresent(app_->getRenderer());

	/*b2Body* tmp = world->GetBodyList();
	b2Vec2 points[4];
	while (tmp != nullptr) {
		for (int i = 0; i < 4; i++) {
			points[i] = ((b2PolygonShape*)tmp->GetFixtureList()->GetShape())->GetVertex(i);
			
		}
		//drawSquare(points, tmp->GetWorldCenter(), body->GetAngle());
		tmp = tmp->GetNext();
	}*/
}

Fight::~Fight()
{
}
