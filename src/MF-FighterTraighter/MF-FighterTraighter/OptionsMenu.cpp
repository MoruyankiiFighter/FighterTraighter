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

	RenderImage* img = controller->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(3));
	entManager_.getScene().push_back(controller);
}

void OptionsMenu::update()
{

}

void OptionsMenu::render()
{
	SDL_RenderClear(app_->getRenderer());

	for (auto e : entManager_.getScene()) {
		e->getComponent<RenderImage>(ecs::RenderImage)->render();
	}

	SDL_RenderPresent(app_->getRenderer());
}

void OptionsMenu::handleInput()
{
	for (auto var : entManager_.getScene()) {
		var->handleInput();
	}
}