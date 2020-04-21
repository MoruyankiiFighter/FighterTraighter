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

#include "KeyboardInput.h"

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
	tuple<Entity*, Entity*> back = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(15, 10), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(7, 0), 100, 60, 0, GoBack, nullptr, "<-", 60);
	initString();


	for (int i = 0; i < 12; i++)
	{
		std::tuple<Entity*, Entity*> Key = UIFactory::createButtonControl(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button),
			app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), Vector2D(400,i*45-350),
			Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2),
			Vector2D(0, 50),
			250, 50, 0, ChangeControl, predet[i], 50, TextComponent::Center, i);
	
	
		std::tuple<Entity*, Entity*> Button = UIFactory::createButtonControl(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button),
			app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), Vector2D(700, i * 45-350),
			Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2),
			Vector2D(0, 50),
			250, 50, 0, ChangeControl, "Mando", 50, TextComponent::Center, i);
	}
	Entity* keyboard = entManager_.addEntity();
	keyboard->addComponent<Transform>(Vector2D(250, 60), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 400, 400, 0);
	keyboard->addComponent<TextComponent>("KeyBoard", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 60);

	Entity* controller = entManager_.addEntity();
	controller->addComponent<Transform>(Vector2D(525, 60), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 400, 400, 0);
	controller->addComponent<TextComponent>("Controller", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 60);

	Entity* movement = entManager_.addEntity();
	movement->addComponent<Transform>(Vector2D(60, 150), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	movement->addComponent<TextComponent>("Movement ", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);
	

	Entity* punch = entManager_.addEntity();
	punch->addComponent<Transform>(Vector2D(60, 195), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	punch->addComponent<TextComponent>("Punch", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);

	

	Entity* kick = entManager_.addEntity();
	kick->addComponent<Transform>(Vector2D(60, 240), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	kick->addComponent<TextComponent>("Kick", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);
	

	Entity* grab = entManager_.addEntity();
	grab->addComponent<Transform>(Vector2D(60, 285), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	grab->addComponent<TextComponent>("Grab", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);
	
	
	Entity* block = entManager_.addEntity();
	block->addComponent<Transform>(Vector2D(60, 330), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	block->addComponent<TextComponent>("Block", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);

	Entity* habilityOne = entManager_.addEntity();
	habilityOne->addComponent<Transform>(Vector2D(60, 375), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	habilityOne->addComponent<TextComponent>("Hability One", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);

	Entity* habilityTwo = entManager_.addEntity();
	habilityTwo->addComponent<Transform>(Vector2D(60, 420), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	habilityTwo->addComponent<TextComponent>("Hability Two", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);

	Entity* pause = entManager_.addEntity();
	pause->addComponent<Transform>(Vector2D(60, 465), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	pause->addComponent<TextComponent>("Pause Game", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);
	
	

	Entity* nav = entManager_.addEntity();
	NavigationController* ctrl = nav->addComponent<NavigationController>(1, 1);
	ctrl->SetElementInPos(std::get<0>(back)->getComponent<UIElement>(ecs::UIElement), 0, 0);




/*	Entity* logic = entManager_.addEntity();
	logic->addComponent<OptionsLogic>(std::get<0>(resolutionSlider)->getComponent<Slider>(ecs::UIElement),
		std::get<3>(resolutionSlider)->getComponent<TextComponent>(ecs::TextComponent),
		std::get<0>(brightSlider)->getComponent<Slider>(ecs::UIElement),
		std::get<3>(brightSlider)->getComponent<TextComponent>(ecs::TextComponent));

	Entity* nav = entManager_.addEntity();
	NavigationController* ctrl = nav->addComponent<NavigationController>(1, 6);
	ctrl->SetElementInPos(std::get<0>(back)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl->SetElementInPos(std::get<0>(controls)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	ctrl->SetElementInPos(std::get<0>(fullscreen)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	ctrl->SetElementInPos(std::get<0>(resolutionSlider)->getComponent<UIElement>(ecs::UIElement), 0, 3);
	ctrl->SetElementInPos(std::get<0>(brightSlider)->getComponent<UIElement>(ecs::UIElement), 0, 4);
	ctrl->SetElementInPos(std::get<0>(applyButton)->getComponent<UIElement>(ecs::UIElement), 0, 5);*/
	
}

void ControlsMenu::GoBack(App* app) {
	app->getStateMachine()->popState();
	
}

void ControlsMenu::ChangeControl(App*app,int index) {

	/*Entity* h = std::get<1>(botones.at(index));

    h->getComponent<TextComponent>(ecs::TextComponent)->setText("hola");*/
	
}
//left, right, up, down, hit1, hit2, hit3, hit4, ab1, ab2, block, guardbreak

void ControlsMenu::initString()
{
	predet[0] = "A";
	predet[1] = "D";
	predet[2] = "W";
	predet[3] = "S";
	predet[4] = "Q";
	predet[5] = "E";
	predet[6] = "Z";
	predet[7] = "X";
	predet[8] = "SPACE";
	predet[9] = "R";
	predet[10] = "1";
	predet[11] = "2";

}

void ControlsMenu::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->popState();
	}
	GameState::handleInput();
}