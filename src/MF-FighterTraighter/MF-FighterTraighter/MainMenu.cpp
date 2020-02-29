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
	string filePath = "../../../../assets/Assets/UI/buttons.png";
	string filename_logo = "../../../../assets/Assets/UI/logo.png";
	texture_ = new Texture(app_->getRenderer(),filePath.c_str(), 1, 1);
	logo_ = new Texture(app_->getRenderer(), filename_logo.c_str(), 1, 1);

	Entity* logo = new Entity();

	Transform* transform=logo->addComponent<Transform>();
	transform->setWidthHeight(1, 1);
	transform->setPosition(150, 50);
	


	RenderImage* img = logo->addComponent<RenderImage>(logo_);
	scene.push_back(logo);
	arcade = new Entity();
	Transform* t=arcade->addComponent<Transform>();
	t->setPosition(150, 250);
	t->setWidth(2); //doble de ancho
	t->setHeight(1);
	t->setRotation(0);
	arcade->addComponent<RenderImage>(texture_); //añadir textura
	scene.push_back(arcade);

	pvp = new Entity();
	t = pvp->addComponent<Transform>();
	t->setPosition(50, 400);
	t->setWidth(1);
	t->setHeight(2); //doble de alto
	t->setRotation(0);
	pvp->addComponent<RenderImage>(texture_); //añadir textura
	scene.push_back(pvp);

	options = new Entity();
	t = options->addComponent<Transform>();
	t->setPosition(50, 650);
	t->setWidth(1);
	t->setHeight(1);
	t->setRotation(0);
	options->addComponent<RenderImage>(texture_); //añadir textura
	scene.push_back(options);
	cout << "init" << endl;
}

void MainMenu::render()
{
	SDL_RenderClear(app_->getRenderer());
	GameState::render();
	//cout << "render" << endl;
	for (auto e : scene) {
		e->getComponent<RenderImage>(ecs::RenderImage)->render();
	}
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
		cout << "handle events main menu";
		//botones
		if (input->isMouseButtonPressed(input->Left)) 
		{ 
			cout << "click";
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
