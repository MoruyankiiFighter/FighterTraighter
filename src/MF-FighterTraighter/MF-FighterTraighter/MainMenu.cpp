#include "MainMenu.h"
#include "Fight.h"
#include "OptionsMenu.h"

#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "TextComponent.h"

#include "Font.h"

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

//void MainMenu::OnButtClick(string text) { std::cout << "Bot�n activado: "<< text << endl; };

void MainMenu::init()
{

	cout << "init" << endl;

	Entity* logo = new Entity();
	
	Transform* transform=logo->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, POS_Y_LOGO);
	logo->setApp(app_);
	RenderImage* img = logo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	scene.push_back(logo);

	Entity* arcade = new Entity();
	arcade->setApp(app_);
	Transform* t=arcade->addComponent<Transform>();
	t->setPosition(POS_X_BUTTONS, POS_Y_ARCADE);
	t->setWidth(WIDTH_BUTTON); 
	t->setHeight(HEIGHT_BUTTON);
	t->setRotation(0);
	arcade->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	arcade->addComponent<TextComponent>("ARCADE", app_->getAssetsManager()->getFont(0), 20);
	arcade->addComponent<Button>(GoArcade);
	scene.push_back(arcade);
	buttons.push_back(arcade);

	pvp = new Entity();
	pvp->setApp(app_);
	Transform* tr = pvp->addComponent<Transform>();
	tr->setPosition(POS_X_BUTTONS, POS_Y_PVP);
	tr->setWidth(WIDTH_BUTTON);
	tr->setHeight(HEIGHT_BUTTON);
	tr->setRotation(0);
	pvp->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1)); 
	pvp->addComponent<Button>(Go1v1);
	scene.push_back(pvp);
	buttons.push_back(pvp);

	options = new Entity();
	options->setApp(app_);
	Transform* tra = options->addComponent<Transform>();
	tra->setPosition(POS_X_BUTTONS, POS_Y_OPTIONS);
	tra->setWidth(WIDTH_BUTTON);
	tra->setHeight(HEIGHT_BUTTON);
	tra->setRotation(0);
	options->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	options->addComponent<Button>(GoOptions);
	scene.push_back(options);
	buttons.push_back(options);

	exit = new Entity();
	exit->setApp(app_);
	Transform* tran = exit->addComponent<Transform>();
	tran->setPosition(POS_X_BUTTONS, POS_Y_EXIT);
	tran->setWidth(WIDTH_BUTTON);
	tran->setHeight(HEIGHT_BUTTON);
	tran->setRotation(0);
	exit->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	exit->addComponent<Button>(Leave);
	scene.push_back(exit);
	buttons.push_back(exit);
}

void MainMenu::GoArcade(App* app)
{
	app->getStateMachine()->pushState(new Fight(app));
}

void MainMenu::Go1v1(App* app)
{
	app->getStateMachine()->pushState(new Fight(app));
}

void MainMenu::GoOptions(App* app)
{
	app->getStateMachine()->pushState(new OptionsMenu(app));
}

void MainMenu::Leave(App* app)
{
	app->Exit();
}

void MainMenu::update() {
	
	//subir al boton de arriba si existe
	if (/*si existe &&*/app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.9) {
		buttonSel--;
	}
	//bajar al boton de abajo si existe
	else if (/*si existe &&*/app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.9) {
		buttonSel++;
	}
	//buttons.at(buttonSel)->estaSeleccionado
}