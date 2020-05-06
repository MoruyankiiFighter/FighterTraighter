#include "ControlsMenu.h"

#include "Fight.h"
#include "OptionsMenu.h"
#include "Training.h"

#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "ButtonControl.h"
#include "TextComponent.h"
#include "NavigationController.h"

#include "Font.h"

#include "App.h"
#include "consts.h"
#include "UIFactory.h"

#include "KeyboardInput.h"
#include "KeyboardHID.h"
#include "GamepadHID.h"


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
	GameState::init();
	cout << "init" << endl;
	tuple<Entity*, Entity*> back = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(15, 10), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(7, 0), 100, 60, 0, GoBack, nullptr, "<-", 60);
	initString();

	Entity* nav = entManager_.addEntity();
	NavigationController* ctrl = nav->addComponent<NavigationController>(2, 13);
	ctrl->SetElementInPos(std::get<0>(back)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl->SetElementInPos(std::get<0>(back)->getComponent<UIElement>(ecs::UIElement), 1, 0);


	for (int i = 0; i < 12; i++)
	{
		std::tuple<Entity*, Entity*> Key = UIFactory::createButtonControl(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button),
			app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), Vector2D(400,i*45.0-350),
			Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2),
			Vector2D(0, 50),
			250, 50, 0, ChangeControl, predet[i], 50, TextComponent::Center, i,0);
		ctrl->SetElementInPos(std::get<0>(Key)->getComponent<UIElement>(ecs::UIElement), 0, i+1);
		if (i>3)
		{
			std::tuple<Entity*, Entity*> Button = UIFactory::createButtonControl(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button),
				app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), Vector2D(700, i * 45.0 - 350),
				Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2),
				Vector2D(0, 50),
				250, 50, 0, ChangeControl, predetMando[i-4], 50, TextComponent::Center, i,1);
			ctrl->SetElementInPos(std::get<0>(Button)->getComponent<UIElement>(ecs::UIElement), 1, i + 1);
		}
		


	}
	std::tuple<Entity*, Entity*> Joy = UIFactory::createButtonControl(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), Vector2D(700,-360),
		Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(0, 50),
		250, 200, 0, ChangeControl, "JOYSTICK", 50, TextComponent::Center, 0);
	ctrl->SetElementInPos(std::get<0>(Joy)->getComponent<UIElement>(ecs::UIElement), 1, 1 );
	ctrl->SetElementInPos(std::get<0>(Joy)->getComponent<UIElement>(ecs::UIElement), 1, 2 );
	ctrl->SetElementInPos(std::get<0>(Joy)->getComponent<UIElement>(ecs::UIElement), 1, 3 );
	ctrl->SetElementInPos(std::get<0>(Joy)->getComponent<UIElement>(ecs::UIElement), 1, 4 );

	

		
	
	Entity* keyboard = entManager_.addEntity();
	keyboard->addComponent<Transform>(Vector2D(410, 60), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 400, 400, 0);
	keyboard->addComponent<TextComponent>("KeyBoard", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 60);

	Entity* controller = entManager_.addEntity();
	controller->addComponent<Transform>(Vector2D(675, 60), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 400, 400, 0);
	controller->addComponent<TextComponent>("Controller", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 60);


	for (int i = 0; i < 12; i++)
	{
		Entity* text = entManager_.addEntity();
		text->addComponent<Transform>(Vector2D(60, 145.0+i*45), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
		text->addComponent<TextComponent>(texto[i], app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 50);
	}
}

void ControlsMenu::GoBack(App* app) {
	app->getStateMachine()->popState();
	
}

void ControlsMenu::ChangeControl(App*app,int index,int control) {
	//app->getInputManager()->change(index,control);
	dynamic_cast<KeyboardHID*>(app->getGameManager()->getPlayerInfo(control + 1).hid)->changeKey(index, app->getInputManager()->lastKey());
	
		

}
//left, right, up, down, hit1, hit2, hit3, hit4, ab1, ab2, block, guardbreak

void ControlsMenu::initString()
{
	

	for (int i = 0; i < 16; i++)
	{
		predet[i] =SDL_GetScancodeName(dynamic_cast<KeyboardHID*>(app_->getGameManager()->getPlayerInfo(1).hid)->getkeys().at(i));
	}
	/*for (int i = 0; i < button.size(); i++)
	{
		predetMando[i] = button[i];
	}*/
	

	

	texto[0] = "Start";
	texto[1] = "Select";
	texto[2] = "LEFT";
	texto[3] = "UP";
	texto[4] = "RIGHT";
	texto[5] = "DOWN";
	texto[6] = "NORMAL KICK";
	texto[7] = "STRONG KICK";
	texto[8] = "NORMAL PUNCH";
	texto[9] = "STRONG PUNCH";
	texto[10] = "ABILITY ONE";
	texto[11] = "ABILITY TWO";
	texto[12] = "CLICK LEFTJOY";
	texto[13] = "CLICK RIGHTJOY";
	texto[14] = "GUARD";
	texto[15] = "GUARDBREAK";


}

void ControlsMenu::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getGameManager()->pressedStart();
	}
	GameState::handleInput();
}