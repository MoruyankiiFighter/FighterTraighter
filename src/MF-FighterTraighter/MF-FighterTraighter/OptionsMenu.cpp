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
	string filename_controls = "../../../../assets/Assets/images/UI/controller.png";
	controls_ = new Texture(app_->getRenderer(), filename_controls.c_str(), 1, 1);

	Entity* controller = new Entity();

	Transform* transform = controller->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, 500);

	RenderImage* img = controller->addComponent<RenderImage>(controls_);
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