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
		Vector2D(15, 10), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), 100, 60, 0, GoBack, nullptr, "<-", 60);

	Entity* keyboard = entManager_.addEntity();
	keyboard->addComponent<Transform>(Vector2D(100, 60), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	keyboard->addComponent<TextComponent>("KeyBoard", app_->getAssetsManager()->getFont(0), 40);

	Entity* controller = entManager_.addEntity();
	controller->addComponent<Transform>(Vector2D(900, 60), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	controller->addComponent<TextComponent>("Controller", app_->getAssetsManager()->getFont(0), 40);

	Entity* movement = entManager_.addEntity();
	movement->addComponent<Transform>(Vector2D(100, 100), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	movement->addComponent<TextComponent>("Movement-> Arrows", app_->getAssetsManager()->getFont(0), 30);
	
	Entity* movementC = entManager_.addEntity();
	movementC->addComponent<Transform>(Vector2D(850, 100), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	movementC->addComponent<TextComponent>(" ->Joystick", app_->getAssetsManager()->getFont(0), 30);

	Entity* punch = entManager_.addEntity();
	punch->addComponent<Transform>(Vector2D(100, 140), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	punch->addComponent<TextComponent>("Punch-> Q", app_->getAssetsManager()->getFont(0), 30);

	Entity* punchC = entManager_.addEntity();
	punchC->addComponent<Transform>(Vector2D(850, 140), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	punchC->addComponent<TextComponent>(" -> A", app_->getAssetsManager()->getFont(0), 30);

	Entity* kick = entManager_.addEntity();
	kick->addComponent<Transform>(Vector2D(100, 180), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	kick->addComponent<TextComponent>("Kick-> W", app_->getAssetsManager()->getFont(0), 30);
	
	Entity* kickC = entManager_.addEntity();
	kickC->addComponent<Transform>(Vector2D(850, 180), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	kickC->addComponent<TextComponent>(" -> X", app_->getAssetsManager()->getFont(0), 30);

	Entity* grab = entManager_.addEntity();
	grab->addComponent<Transform>(Vector2D(100, 220), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	grab->addComponent<TextComponent>("Grab-> E", app_->getAssetsManager()->getFont(0), 30);
	
	Entity* grabC = entManager_.addEntity();
	grabC->addComponent<Transform>(Vector2D(850, 220), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	grabC->addComponent<TextComponent>(" -> B", app_->getAssetsManager()->getFont(0), 30);

	Entity* block = entManager_.addEntity();
	block->addComponent<Transform>(Vector2D(100, 260), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	block->addComponent<TextComponent>("Block-> D", app_->getAssetsManager()->getFont(0), 30);
	
	Entity* blockC = entManager_.addEntity();
	blockC->addComponent<Transform>(Vector2D(850, 260), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	blockC->addComponent<TextComponent>(" -> Y", app_->getAssetsManager()->getFont(0), 30);

	Entity* habilityOne = entManager_.addEntity();
	habilityOne->addComponent<Transform>(Vector2D(100, 300), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	habilityOne->addComponent<TextComponent>("Hability One-> R", app_->getAssetsManager()->getFont(0), 30);
	
	Entity* habilityOneC = entManager_.addEntity();
	habilityOneC->addComponent<Transform>(Vector2D(850, 300), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	habilityOneC->addComponent<TextComponent>(" -> RB", app_->getAssetsManager()->getFont(0), 30);

	Entity* habilityTwo = entManager_.addEntity();
	habilityTwo->addComponent<Transform>(Vector2D(100, 340), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	habilityTwo->addComponent<TextComponent>("Hability Two -> F", app_->getAssetsManager()->getFont(0), 30);
	
	Entity* habilityTwoC = entManager_.addEntity();
	habilityTwoC->addComponent<Transform>(Vector2D(850, 340), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	habilityTwoC->addComponent<TextComponent>(" -> LB", app_->getAssetsManager()->getFont(0), 30);

	Entity* pause = entManager_.addEntity();
	pause->addComponent<Transform>(Vector2D(100, 380), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	pause->addComponent<TextComponent>("Pause Game -> Esc", app_->getAssetsManager()->getFont(0), 30);
	
	Entity* pauseC = entManager_.addEntity();
	pauseC->addComponent<Transform>(Vector2D(850, 380), Vector2D(0, app_->getWindowManager()->getCurResolution().h / 2), 50, 50, 0);
	pauseC->addComponent<TextComponent>(" -> Start", app_->getAssetsManager()->getFont(0), 30);

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