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
	scene.push_back(arcade);

	pvp = new Entity();
	pvp->addComponent<RenderImage>(texture_); //añadir textura
	t = pvp->addComponent<Transform>();
	t->setPosition(200, 500);
	t->setWidth(400);
	t->setHeight(150);
	scene.push_back(pvp);

	options = new Entity();
	options->addComponent<RenderImage>(texture_); //añadir textura
	t = options->addComponent<Transform>();
	t->setPosition(200, 700);
	t->setWidth(400);
	t->setHeight(150);

	scene.push_back(options);
	cout << "init" << endl;
}

void MainMenu::render()
{
	SDL_RenderClear(app_->getRenderer());
	cout << "render" << endl;
	for (auto i : scene) {
		
		RenderImage* img=i->getComponent<RenderImage>(ecs::RenderImage);
		if (img != nullptr) {
			cout << "f";
			img->render();
		}
		else {
			cout << "aqui va una excepcion uwu";
		}

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
		if (input->isMouseButtonPressed(input->Left)) { 
		
			SDL_Point p = { input->getMousePosX(),input->getMousePosY() };

			//revisar si coincide con nuestros botones y en caso de ello llamar al metodo correspondiente
			cout << "click";

		}
		


	}

}
