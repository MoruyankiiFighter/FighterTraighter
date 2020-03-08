#include "MainMenu.h"

#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"

#include "App.h"
#include "consts.h"

MainMenu::MainMenu(App* app): GameState(app)
{
	
	cout << "Menu principal" << endl;
	init();
}

MainMenu::~MainMenu()
{

}

//void MainMenu::OnButtClick(string text) { std::cout << "Botón activado: "<< text << endl; };

void MainMenu::init()
{

	cout << "init" << endl;
	string filePath = "../../../../assets/Assets/images/UI/buttons.png";
	string filename_logo = "../../../../assets/Assets/images/UI/logo.png";
	texture_ = new Texture(app_->getRenderer(),filePath.c_str(), 1, 1);
	logo_ = new Texture(app_->getRenderer(), filename_logo.c_str(), 1, 1);

	Entity* logo = new Entity();
	
	Transform* transform=logo->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, POS_Y_LOGO);
	
	RenderImage* img = logo->addComponent<RenderImage>(logo_);
	scene.push_back(logo);

	arcade = new Entity();
	arcade->setApp(app_);
	Transform* t=arcade->addComponent<Transform>();
	t->setPosition(POS_X_BUTTONS, POS_Y_ARCADE);
	t->setWidth(WIDTH_BUTTON); 
	t->setHeight(HEIGHT_BUTTON);
	t->setRotation(0);
	arcade->addComponent<RenderImage>(texture_); //añadir textura
	arcade->addComponent<Button>(ArcadeCallback);
	scene.push_back(arcade);

	pvp = new Entity();
	pvp->setApp(app_);
	Transform* tr = pvp->addComponent<Transform>();
	tr->setPosition(POS_X_BUTTONS, POS_Y_PVP);
	tr->setWidth(WIDTH_BUTTON);
	tr->setHeight(HEIGHT_BUTTON);
	tr->setRotation(0);
	pvp->addComponent<RenderImage>(texture_); //añadir textura
	pvp->addComponent<Button>(OneVsOneCallback);
	scene.push_back(pvp);

	options = new Entity();
	options->setApp(app_);
	Transform* tra = options->addComponent<Transform>();
	tra->setPosition(POS_X_BUTTONS, POS_Y_OPTIONS);
	tra->setWidth(WIDTH_BUTTON);
	tra->setHeight(HEIGHT_BUTTON);
	tra->setRotation(0);
	options->addComponent<RenderImage>(texture_); //añadir textura
	options->addComponent<Button>(OptionsCallback);
	scene.push_back(options);

	exit = new Entity();
	exit->setApp(app_);
	Transform* tran = exit->addComponent<Transform>();
	tran->setPosition(POS_X_BUTTONS, POS_Y_EXIT);
	tran->setWidth(WIDTH_BUTTON);
	tran->setHeight(HEIGHT_BUTTON);
	tran->setRotation(0);
	exit->addComponent<RenderImage>(texture_); //añadir textura
	exit->addComponent<Button>(ExitCallback);
	scene.push_back(exit);
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
	for (auto var : scene) {
		var->handleInput();
	}
}
