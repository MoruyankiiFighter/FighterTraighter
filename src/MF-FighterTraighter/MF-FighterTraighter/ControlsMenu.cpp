#include "ControlsMenu.h"

#include "Fight.h"
#include "OptionsMenu.h"
#include "Training.h"

#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "TextComponent.h"
#include "NavigationController.h"

#include "Font.h"

#include "App.h"
#include "consts.h"
#include "UIFactory.h"

ControlsMenu::ControlsMenu(App* app) : GameState(app)
{
	cout << "MovementsMenu" << endl;
	init();
}

ControlsMenu::~ControlsMenu()
{

}

void ControlsMenu::init()
{
	cout << "init" << endl;
	tuple<Entity*, Entity*> back = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(0, 20), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), 200, 60, 0, GoBack, nullptr, "<-", 60);

	Entity* movement = entManager_.addEntity();
	movement->addComponent<Transform>(Vector2D(100, 70), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	movement->addComponent<TextComponent>("Movement ---> Arrows", app_->getAssetsManager()->getFont(0), 40);

	Entity* punch = entManager_.addEntity();
	punch->addComponent<Transform>(Vector2D(100, 100), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	punch->addComponent<TextComponent>("Punch ---> Q", app_->getAssetsManager()->getFont(0), 40);

	Entity* kick = entManager_.addEntity();
	kick->addComponent<Transform>(Vector2D(100, 130), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	kick->addComponent<TextComponent>("Kick ---> W", app_->getAssetsManager()->getFont(0), 40);

	Entity* grab = entManager_.addEntity();
	grab->addComponent<Transform>(Vector2D(100, 160), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	grab->addComponent<TextComponent>("Grab ---> E", app_->getAssetsManager()->getFont(0), 40);

	Entity* block = entManager_.addEntity();
	block->addComponent<Transform>(Vector2D(100, 190), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	block->addComponent<TextComponent>("Block ---> D", app_->getAssetsManager()->getFont(0), 40);

	Entity* nav = entManager_.addEntity();
	NavigationController* ctrl = nav->addComponent<NavigationController>(1, 1);
	ctrl->SetElementInPos(std::get<0>(back)->getComponent<UIElement>(ecs::UIElement), 0, 0);
}

void ControlsMenu::GoBack(App* app) {
	app->getStateMachine()->popState();
}

void ControlsMenu::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->popState();
	}
	GameState::handleInput();
}