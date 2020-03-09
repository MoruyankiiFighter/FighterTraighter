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


	Entity* controller = new Entity();

	Transform* transform = controller->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, 500);

	RenderImage* img = controller->addComponent<RenderImage>(app_->getTextureManager()->getTexture(3));

	scene.push_back(controller);

	Entity* fullscreen_button = new Entity();

	Transform* transform_ = fullscreen_button->addComponent<Transform>();

	transform_->setPosition(POS_X_FULLSCREEN, POS_Y_FULLSCREEN);
	transform_->setWidthHeight(WIDTH_LITTLE_BUTTONS, HEIGHT_LITTLE_BUTTONS);
	RenderImage* im = fullscreen_button->addComponent<RenderImage>(app_->getTextureManager()->getTexture(3);
	Button* fullscreen = fullscreen_button->addComponent<Button>(SetFullScreen);

	scene.push_back(fullscreen_button);


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
	for (auto var : scene) {
		var->handleInput();
	}
}
