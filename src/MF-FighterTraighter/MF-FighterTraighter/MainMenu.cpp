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
#include "UIFactory.h"

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

	Entity* ent = entManager_.addEntity();
	Transform* transform=ent->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, POS_Y_LOGO);
	RenderImage* img = ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));


	tuple < Entity*, Entity *> arcade=	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0), Vector2D(POS_X_BUTTONS, POS_Y_ARCADE), WIDTH_BUTTON, HEIGHT_BUTTON,0, nullptr,GoArcade,"Arcade",20);
	tuple < Entity*, Entity *> pvp=	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0), Vector2D(POS_X_BUTTONS, POS_Y_PVP), WIDTH_BUTTON, HEIGHT_BUTTON,0, nullptr,Go1v1,"1vs1",20);

	tuple < Entity*, Entity *> options = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0), Vector2D(POS_X_BUTTONS, POS_Y_OPTIONS), WIDTH_BUTTON, HEIGHT_BUTTON,0, nullptr,GoOptions,"Options",20);
	tuple < Entity*, Entity *> exit = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0), Vector2D(POS_X_BUTTONS, POS_Y_EXIT), WIDTH_BUTTON, HEIGHT_BUTTON,0, nullptr,Leave,"quit",20);

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
