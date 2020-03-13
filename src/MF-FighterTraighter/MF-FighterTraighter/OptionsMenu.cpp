#include "OptionsMenu.h"
#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"

#include "App.h"
#include "consts.h"

OptionsMenu::OptionsMenu(App* app) : GameState(app)
{
	cout << "OptionsMenu" << endl;
	init();
}

OptionsMenu::~OptionsMenu()
{

}

void OptionsMenu::init()
{
	cout << "init" << endl;
	Entity* BG = new Entity();
	Transform* transform = BG->addComponent<Transform>();
	transform->setWidthHeight(WINDOW_WIDTH_, WINDOW_HEIGHT_);
	transform->setPosition(0, 0);
	BG->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	scene.push_back(BG);


	Entity* fullscreen_button_ = new Entity();

	transform = fullscreen_button_->addComponent<Transform>();
	transform->setWidthHeight(50, 50);
	transform->setPosition(WINDOW_WIDTH_ - 50, WINDOW_HEIGHT_ - 50);

	fullscreen_button_->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	fullscreen_button_->addComponent<Button>(fullScreen);

	scene.push_back(fullscreen_button_);
	
	Entity* back_button_ = new Entity();

	transform = back_button_->addComponent<Transform>();
	transform->setWidthHeight(50, 50);
	transform->setPosition(50, 50);

	back_button_->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	back_button_->addComponent<Button>(MenuCallback);

	scene.push_back(back_button_);


	Entity* morebright_button = new Entity();

	transform = morebright_button->addComponent<Transform>();
	transform->setWidthHeight(50, 50);
	transform->setPosition(WINDOW_WIDTH_ / 2 + 100, WINDOW_HEIGHT_ / 3);

	morebright_button->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	morebright_button->addComponent<Button>(moreBright);

	scene.push_back(morebright_button);

	Entity* lessbright_button = new Entity();

	transform = lessbright_button->addComponent<Transform>();
	transform->setWidthHeight(50, 50);
	transform->setPosition(WINDOW_WIDTH_ / 2 - 100, WINDOW_HEIGHT_ / 3);

	lessbright_button->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	lessbright_button->addComponent<Button>(lessBright);

	scene.push_back(lessbright_button);



	Entity* controller = new Entity();

	transform = controller->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, 500);

	controller->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(3));
	scene.push_back(controller);

}

void OptionsMenu::update()
{

}

void OptionsMenu::render()
{
	SDL_RenderClear(app_->getRenderer());
	for (auto e : scene) {
		e->getComponent<RenderImage>(ecs::RenderImage)->render();
	}

	SDL_RenderPresent(app_->getRenderer());
}

void OptionsMenu::handleInput()
{
	if (app_->getInputManager()->isKeyDown(SDLK_p)) {
		cout << "back" << endl;
		app_->getStateMachine()->popState();

	}
	else 
	{
		for (auto var : scene) {
			var->handleInput();
		}
	}
}