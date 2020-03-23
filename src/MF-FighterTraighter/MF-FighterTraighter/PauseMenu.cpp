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

void PauseMenu::init()
{
	cout << "initPausa" << endl;

	Entity* logo = giveMeManager().addEntity();
	Transform* transform = logo->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(WINDOW_WIDTH_ / 2, POS_Y_LOGO);
	RenderImage* img = logo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));

	Entity* ent = new Entity();
	ent->setApp(app_);
	Transform* t = ent->addComponent<Transform>();
	t->setPosition(100, 100);
	t->setWidth(500);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(Resume);

	ent = giveMeManager().addEntity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(100, 300);
	t->setWidth(500);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(GoMainMenu);

	ent = giveMeManager().addEntity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(100, 500);
	t->setWidth(500);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(ShowMeYourMoves);

	ent = giveMeManager().addEntity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(100, 700);
	t->setWidth(500);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(GoOptions);
}

void PauseMenu::render()
{
	/*SDL_RenderClear(app_->getRenderer());

	for (auto e : entManager_.getScene()) {
		e->getComponent<RenderImage>(ecs::RenderImage)->render();
	}

	SDL_RenderPresent(app_->getRenderer());*/
}

void PauseMenu::update()
{
}

void PauseMenu::handleInput()
{
	/*for (auto var : entManager_.getScene()) {
		var->handleInput();
	}*/
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
