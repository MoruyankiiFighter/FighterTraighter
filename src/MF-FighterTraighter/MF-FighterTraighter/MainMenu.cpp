#include "MainMenu.h"
#include "InputManager.h"
#include "Entity.h"
#include "RenderImage.h"
#include "Transform.h"
#include "App.h"
MainMenu::MainMenu(App* app): GameState(app)
{
	
	cout << "Menu principal" << endl;
	init();
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{

	cout << "init" << endl;
	string filePath = "../../../../Assets/Assets/UI/buttons.png";
	texture_ = new Texture(app_->getRenderer(),filePath.c_str(), 1, 1);

	arcade = new Entity();
	arcade->setApp(app_);
	arcade->addComponent<RenderImage>(texture_); //añadir textura
	Transform* t=arcade->addComponent<Transform>();
	t->setPosition(200, 300);
	t->setWidth(400);
	t->setHeight(150);
	t->setRotation(0);
	scene.push_back(arcade);

	pvp = new Entity();
	pvp->addComponent<RenderImage>(texture_); //añadir textura
	t = pvp->addComponent<Transform>();
	t->setPosition(200, 500);
	t->setWidth(400);
	t->setHeight(150);
	t->setRotation(0);
	scene.push_back(pvp);

	options = new Entity();
	options->addComponent<RenderImage>(texture_); //añadir textura
	t = options->addComponent<Transform>();
	t->setPosition(200, 700);
	t->setWidth(400);
	t->setHeight(150);
	t->setRotation(0);
	scene.push_back(options);
	cout << "init" << endl;
}

void MainMenu::render()
{

	//REVISAR ESTO AAAAAAAAAAA

	SDL_RenderClear(app_->getRenderer());
	cout << "render" << endl;
	scene.front()->getComponent<RenderImage>(ecs::RenderImage)->render();
	SDL_RenderPresent(app_->getRenderer());
}

void MainMenu::update()
{
}

void MainMenu::handleInput()
{
	InputManager* input = app_->getInputManager();
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		//botones
		if (input->isMouseButtonPressed(input->Left)) 
		{ 
		
			SDL_Point p = { input->getMousePosX(),input->getMousePosY() };

			if (SDL_PointInRect(&p, arcade->getComponent<Transform>(ecs::Transform)->getDestRect())) 
			{
				cout << "arcade";
				app_->PlayArcade();
			}
			else if (SDL_PointInRect(&p, options->getComponent<Transform>(ecs::Transform)->getDestRect())) {
				cout << "options";
				app_->Options();
			}
			else if (SDL_PointInRect(&p, pvp->getComponent<Transform>(ecs::Transform)->getDestRect())) {
				cout << "pvp";
				app_->PlayOnevsOne();
			}
			else if (SDL_PointInRect(&p, exit->getComponent<Transform>(ecs::Transform)->getDestRect())) {
				app_->Exit();
			}
			cout << "click";
		}

		/* mando
		
		
		*/

		/* teclado
		
		*/
	}
}
