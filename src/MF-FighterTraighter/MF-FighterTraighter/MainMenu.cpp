#include "MainMenu.h"
#include "Fight.h"
#include "OptionsMenu.h"
#include "Training.h"

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

	Entity* ent = new Entity();
	
	Transform* t=ent ->addComponent<Transform>();
	t->setWidthHeight(2*WIDTH_LOGO, HEIGHT_LOGO);
	t->setPosition(POS_X_BUTTONS, POS_Y_LOGO);
	ent->setApp(app_);
	RenderImage* img = ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	t=ent->addComponent<Transform>();
	t->setPosition(POS_X_BUTTONS, POS_Y_ARCADE);
	t->setWidth(WIDTH_BUTTON); 
	t->setHeight(HEIGHT_BUTTON);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<TextComponent>("ARCADE", app_->getAssetsManager()->getFont(0), 20);
	ent->addComponent<Button>(GoArcade);
	scene.push_back(ent);
	//buttons.push_back(arcade);

	ent = new Entity();
	ent->setApp(app_);
	t=ent->addComponent<Transform>();
	t->setPosition(POS_X_BUTTONS, POS_Y_PVP);
	t->setWidth(WIDTH_BUTTON); 
	t->setHeight(HEIGHT_BUTTON);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<TextComponent>("1vs1", app_->getAssetsManager()->getFont(0), 20);
	ent->addComponent<Button>(Go1v1);
	scene.push_back(ent);
	//buttons.push_back(arcade);

	ent = new Entity();
	ent->setApp(app_);
	t=ent->addComponent<Transform>();
	t->setPosition(POS_X_BUTTONS, POS_Y_OPTIONS);
	t->setWidth(WIDTH_BUTTON); 
	t->setHeight(HEIGHT_BUTTON);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<TextComponent>("OPTIONS", app_->getAssetsManager()->getFont(0), 20);
	ent->addComponent<Button>(GoOptions);
	scene.push_back(ent);
	//buttons.push_back(arcade);


	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(POS_X_BUTTONS, POS_Y_EXIT);
	t->setWidth(WIDTH_BUTTON);
	t->setHeight(HEIGHT_BUTTON);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<TextComponent>("QUIT", app_->getAssetsManager()->getFont(0), 20);
	ent->addComponent<Button>(Leave);
	scene.push_back(ent);
	//buttons.push_back(exit);
}

void MainMenu::GoArcade(App* app)
{
	app->getStateMachine()->pushState(new Fight(app));
}

void MainMenu::Go1v1(App* app)
{
	// TEMPORARY, TESTING
	app->getStateMachine()->pushState(new Training(app));
}

void MainMenu::GoOptions(App* app)
{
	app->Options();
}

void MainMenu::Leave(App* app)
{
	app->Exit();
}

void MainMenu::update() {

	
	////subir al boton de arriba si existe
	//if (/*si existe &&*/app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.9) {
	//	buttonSel--;
	//}
	////bajar al boton de abajo si existe
	//else if (/*si existe &&*/app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.9) {
	//	buttonSel++;
	//}
	////buttons.at(buttonSel)->estaSeleccionado

	/* shouldn't be here
	//subir al boton de arriba si existe
	if (app_->getInputManager()->GamepadConnected() && app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.9) {
		buttonSel--;
	}
	//bajar al boton de abajo si existe
	else if (app_->getInputManager()->GamepadConnected() && app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.9) {
		buttonSel++;
	}
	//buttons.at(buttonSel)->estaSeleccionado
	*/
}