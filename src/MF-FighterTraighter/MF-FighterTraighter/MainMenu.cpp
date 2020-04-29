#include "MainMenu.h"
#include "Fight.h"
#include "OptionsMenu.h"
#include "Training.h"
#include "CharacterSelection.h"
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
#include "RenderAnimation.h"

MainMenu::MainMenu(App* app) : GameState(app)
{
	init();
}

MainMenu::~MainMenu()
{

}

void MainMenu::init()
{
	GameState::init();
	Entity* bg = entManager_.addEntity();
	bg->addComponent<Transform>(Vector2D(), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);
	bg->addComponent<RenderAnimation>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight), 20);


	tuple < Entity*, Entity*> arcade = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -200), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2), 
		Vector2D(250, 75),
		500, 150, 0, nullptr, GoArcade, "Arcade", 150, TextComponent::TextAlignment::Center);

	tuple < Entity*, Entity*> pvp = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -50), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		500, 150, 0, nullptr, Go1v1, "1vs1", 150, TextComponent::TextAlignment::Center);

	tuple < Entity*, Entity*> options = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 100), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		500, 150, 0, nullptr, GoOptions, "Options", 150, TextComponent::TextAlignment::Center);

	tuple < Entity*, Entity*> exit = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 250), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		500, 150, 0, nullptr, Leave, "Quit", 150, TextComponent::TextAlignment::Center);

	Entity* navEnt = entManager_.addEntity();
	NavigationController* nav = navEnt->addComponent<NavigationController>(1, 4);
	nav->SetElementInPos(std::get<0>(arcade)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	nav->SetElementInPos(std::get<0>(pvp)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	nav->SetElementInPos(std::get<0>(options)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	nav->SetElementInPos(std::get<0>(exit)->getComponent<UIElement>(ecs::UIElement), 0, 3);

}

void MainMenu::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getGameManager()->pressedStart();
	}
	else
		GameState::handleInput();
	
}

void MainMenu::GoArcade(App* app)
{
	std::cout << app->getStateMachine()->getCurrentState()->getb2World()->GetBodyCount() << std::endl;
//	app->getStateMachine()->pushState(new Fight(app));
	app->getStateMachine()->pushState(new CharacterSelection(app));
	std::cout << app->getStateMachine()->getCurrentState()->getb2World()->GetBodyCount() << std::endl;
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
