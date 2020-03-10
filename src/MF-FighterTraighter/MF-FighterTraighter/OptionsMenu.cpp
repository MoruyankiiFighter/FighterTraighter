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
	BG->addComponent<RenderImage>(app_->getTextureManager()->getTexture(4));
	scene.push_back(BG);


	Entity* controller = new Entity();

	transform = controller->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, 500);

	controller->addComponent<RenderImage>(app_->getTextureManager()->getTexture(3));
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
	for (auto var : scene) {
		var->handleInput();
	}
}
