#include "PauseMenu.h"
#include "InputManager.h"
#include "MainMenu.h"
#include "OptionsMenu.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"

#include "App.h"
#include "consts.h"

#include "UIFactory.h"

void PauseMenu::init()
{
	cout << "initPausa" << endl;

	Entity* logo = getEntityManager().addEntity();
	Transform* transform = logo->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(app_->getWindowManager()->getCurResolution().w / 2, POS_Y_LOGO);
	RenderImage* img = logo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));

	std::tuple<Entity*, Entity*> continue_button = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0), Vector2D(100, 100), 500, 100, 0, nullptr, Resume, "Continue", 20);
	std::tuple<Entity*, Entity*> menu_button = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0), Vector2D(100, 300), 500, 100, 0, nullptr, GoMainMenu, "Go to menu", 20);
	std::tuple<Entity*, Entity*> controls_button = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0), Vector2D(100, 500), 500, 100, 0, nullptr, ShowMeYourMoves, "Controls", 20);
	std::tuple<Entity*, Entity*> controls_button = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0), Vector2D(100, 700), 500, 100, 0, nullptr, GoOptions, "Options", 20);

}

void PauseMenu::Resume(App* app)
{
	app->getStateMachine()->popState();
}

void PauseMenu::GoMainMenu(App* app)
{
	app->getStateMachine()->popState();
	while (dynamic_cast<MainMenu*>(app->getStateMachine()->getCurrentState()) == nullptr) {
		app->getStateMachine()->popState();
	}
}

void PauseMenu::ShowMeYourMoves(App* app)
{
	std::cout << "No implementado de momento" << endl;
}

void PauseMenu::GoOptions(App* app)
{
	app->getStateMachine()->pushState(new OptionsMenu(app));
}
