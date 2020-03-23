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

	Entity* logo = giveMeManager().addEntity();
	
	Transform* transform=logo->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, POS_Y_LOGO);
	RenderImage* img = logo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	entManager_.getScene().push_back(logo);
	

	Entity* arcade = giveMeManager().addEntity();
	Transform* t=arcade->addComponent<Transform>();
	t->setPosition(POS_X_BUTTONS, POS_Y_ARCADE);
	t->setWidth(WIDTH_BUTTON); 
	t->setHeight(HEIGHT_BUTTON);
	t->setRotation(0);
	arcade->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	arcade->addComponent<TextComponent>("ARCADE", app_->getAssetsManager()->getFont(0), 20);
	arcade->addComponent<Button>(GoArcade);
	buttons.push_back(arcade);

	Entity* pvp = giveMeManager().addEntity();
	Transform* tr = pvp->addComponent<Transform>();
	tr->setPosition(POS_X_BUTTONS, POS_Y_PVP);
	tr->setWidth(WIDTH_BUTTON);
	tr->setHeight(HEIGHT_BUTTON);
	tr->setRotation(0);
	pvp->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1)); 
	pvp->addComponent<Button>(Go1v1);
	buttons.push_back(pvp);


	Entity* options = giveMeManager().addEntity();
	Transform* tra = options->addComponent<Transform>();
	tra->setPosition(POS_X_BUTTONS, POS_Y_OPTIONS);
	tra->setWidth(WIDTH_BUTTON);
	tra->setHeight(HEIGHT_BUTTON);
	tra->setRotation(0);
	options->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	options->addComponent<Button>(GoOptions);
	buttons.push_back(options);


	Entity* exit = giveMeManager().addEntity();
	Transform* tran = exit->addComponent<Transform>();
	tran->setPosition(POS_X_BUTTONS, POS_Y_EXIT);
	tran->setWidth(WIDTH_BUTTON);
	tran->setHeight(HEIGHT_BUTTON);
	tran->setRotation(0);
	exit->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	exit->addComponent<Button>(Leave);
	buttons.push_back(exit);

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
	app->getStateMachine()->pushState(new OptionsMenu(app));
}

void MainMenu::Leave(App* app)
{
	app->Exit();
}

void MainMenu::update() {

	//subir al boton de arriba si existe
	if (buttonSel != 0 && (app_->getInputManager()->isKeyDown(SDLK_UP)/* || app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) < -0.8*/)) {
		buttonSel--;
		cout << buttonSel;

	}
	//bajar al boton de abajo si existe
	else if (buttonSel != buttons.size() - 1 && (app_->getInputManager()->isKeyDown(SDLK_DOWN) /*|| app_->getInputManager()->getControllerAxis(InputManager::Controllers::PLAYER1, SDL_CONTROLLER_AXIS_LEFTY) > 0.8*/)) {
		buttonSel++;
			cout << buttonSel;

	}

	buttons.at(buttonSel)->getComponent<Button>(ecs::Button)->setSelect(true);
	//buttons.at(buttonSel)->estaSeleccionado  -----> esto seria para indicar que el boton este seleccionado ya sea con sombrado o como sea
}