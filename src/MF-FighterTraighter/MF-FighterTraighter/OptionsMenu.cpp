#include "OptionsMenu.h"
#include "InputManager.h"

#include "Entity.h"
#include "UIFactory.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Slider.h"
#include "VerticalSlider.h"
#include "IndexSlider.h"
#include "OptionsLogic.h"
#include "NavigationController.h"
#include "MovementsMenu.h"
#include "App.h"
#include "consts.h"
#include <cmath>

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
	/*Entity* bg = entManager_.addEntity();
	Transform* t = bg->addComponent<Transform>();
	t->setPosition(0, 0);
	t->setWidthHeight(800, 600);
	RenderImage* img = bg->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(7));*/

	Entity* ent = entManager_.addEntity();
	Transform* transform = ent->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(app_->getWindowManager()->getCurResolution().w / 4, POS_Y_LOGO / 2);
	RenderImage* img = ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));

	tuple<Entity*, Entity*> back = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(20, 20), 60, 60, 0, GoBackCallback, nullptr, "<-", 60);

	tuple<Entity*, Entity*> movements = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4 + 500, 200), 400, 50, 0, GoMovementsCallback, nullptr, "Controls", 60);

	tuple<Entity*, Entity*> fullscreen = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4, 200), 400, 50, 0, nullptr, fullScreen, "FULLSCREEN", 60);

	tuple<Entity*, Entity*, Entity*, Entity*> brightSlider = UIFactory::createSlider(app_, this, 0.4, 1, 6,
		app_->getAssetsManager()->getTexture(4), app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4, 500), 500, 10, SetBright, "BRIGHTNESS", 60, "", 60);

	tuple<Entity*, Entity*, Entity*, Entity*> resolutionSlider = UIFactory::createSlider(app_, this, 0, 10, 10,
		app_->getAssetsManager()->getTexture(4), app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4, 350), 500, 10, setResolution, "RESOLUTION", 60, "", 60);

	Entity* logic = entManager_.addEntity();
	logic->addComponent<OptionsLogic>(std::get<0>(resolutionSlider)->getComponent<Slider>(ecs::Slider),
		std::get<3>(resolutionSlider)->getComponent<TextComponent>(ecs::TextComponent),
		std::get<0>(brightSlider)->getComponent<Slider>(ecs::Slider),
		std::get<3>(brightSlider)->getComponent<TextComponent>(ecs::TextComponent));

	Entity* nav = entManager_.addEntity();
	NavigationController* ctrl = nav->addComponent<NavigationController>(2, 1);
	ctrl->SetElementInPos(std::get<0>(back), 0, 0);
	ctrl->SetElementInPos(std::get<0>(fullscreen), 1, 0);
	//ctrl->SetElementInPos(options, 0, 2);
	//ctrl->SetElementInPos(exit, 0, 3);
}

void OptionsMenu::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->popState();
	}
	GameState::handleInput();
}


void OptionsMenu::GoBackCallback(App* app) {
	app->getStateMachine()->popState();
}

void OptionsMenu::GoMovementsCallback(App* app) {
	app->getStateMachine()->pushState(new MovementsMenu(app));
}

void OptionsMenu::SetBright(App* app, double value)
{
	app->getWindowManager()->setBrightness(value);
}

void OptionsMenu::MoreBright(App* app)
{
	double flag = app->getWindowManager()->getCurBrightness();
	flag += 0.1;
	if (flag > 1) {
		flag = 1;
	}
	app->getWindowManager()->setBrightness(flag);
}

void OptionsMenu::LessBright(App* app)
{
	double flag = app->getWindowManager()->getCurBrightness();
	flag -= 0.1;
	if (flag < 0.4) {
		flag = 0.4;
	}
	app->getWindowManager()->setBrightness(flag);

}

void OptionsMenu::SetVolume(App* app, double value) //CAMBIAR CUANDO TENGAMOS UN SOUND MANAGER/AUDIO MANAGER
{
	SDL_SetWindowBrightness(app->getWindowManager()->getWindow(), value);
}

//fullscreen
void OptionsMenu::fullScreen(App* app) {
	bool IsFullscreen = SDL_GetWindowFlags(app->getWindowManager()->getWindow()) & SDL_WINDOW_FULLSCREEN_DESKTOP;
	app->getWindowManager()->setFullscreen(!IsFullscreen);
}

void OptionsMenu::setResolution(App* app, double value)
{
	app->getWindowManager()->setResolution(lround(value));
}
