#include "MainMenu.h"
#include "InputManager.h"
#include "Entity.h"
#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "App.h"
MainMenu::MainMenu(App* app): GameState(app)
{
	
	cout << "Menu principal" << endl;
	init();
}

MainMenu::~MainMenu()
{
	delete arcade;
	arcade = nullptr;
	
	delete pvp;
	pvp = nullptr;

	delete options;
	options = nullptr;

	delete exit;
	exit= nullptr;

	for (auto i : scene) {
		delete i;
		i = nullptr;
	}

}

//void MainMenu::OnButtClick(string text) { std::cout << "Botón activado: "<< text << endl; };

void MainMenu::init()
{

	cout << "init" << endl;
	string filePath = "../../../../assets/Assets/UI/buttons.png";
	string filename_logo = "../../../../assets/Assets/UI/logo.png";
	texture_ = new Texture(app_->getRenderer(),filePath.c_str(), 1, 1);
	logo_ = new Texture(app_->getRenderer(), filename_logo.c_str(), 1, 1);

	Entity* logo = new Entity();
	
	Transform* transform=logo->addComponent<Transform>();
	transform->setWidthHeight(200, 200);
	transform->setPosition(0, 50);
	
	RenderImage* img = logo->addComponent<RenderImage>(logo_);
	scene.push_back(logo);

	arcade = new Entity();
	arcade->setApp(app_);
	Transform* t=arcade->addComponent<Transform>();
	t->setPosition(150, 350);
	t->setWidth(300); 
	t->setHeight(150);
	t->setRotation(0);
	arcade->addComponent<RenderImage>(texture_); //añadir textura
	scene.push_back(arcade);


}

void MainMenu::render()
{
	SDL_RenderClear(app_->getRenderer());
	
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
	SDL_Event event;

	if (SDL_PollEvent(&event)) {

		if (event.type == SDL_MOUSEBUTTONUP||event.type==SDL_MOUSEBUTTONDOWN) {
			SDL_Point p = {event.button.x, event.button.y};

			if (SDL_PointInRect(&p, &arcade->getComponent<RenderImage>(ecs::RenderImage)->getDestRect())) {
				cout << "arcade";
				app_->PlayArcade();
			}
			cout << "click";
		}
		if (event.type == SDL_KEYUP) {
			cout << "keyboard";
		}
	}
}
