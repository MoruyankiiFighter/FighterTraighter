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
	Entity* ent = entManager_.addEntity();
	Transform* transform = ent->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(app_->getWindowManager()->getCurResolution().w / 4, POS_Y_LOGO / 2);
	RenderImage* img = ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	
	Entity* resolutionText = entManager_.addEntity();
	resolutionText->addComponent<Transform>(Vector2D(500, 500), Vector2D(), 300, 100, 0);
	resolutionText->addComponent<TextComponent>("", app_->getAssetsManager()->getFont(0), 20);
	
	Entity* brightnessText = entManager_.addEntity();
	brightnessText->addComponent<Transform>(Vector2D(500, 600), Vector2D(), 300, 100, 0);
	brightnessText->addComponent<TextComponent>("", app_->getAssetsManager()->getFont(0), 20);
	
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(10, 10), 60, 60, 0, GoBackCallback, nullptr, "<-", 20);

	 UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 2 - 150, 300), 150, 50, 0, nullptr, fullScreen, "FULLSCREEN", 20);

	tuple<Entity*, Entity*, Entity*, Entity*> brightSlider = UIFactory::createSlider(app_, this, 0.4, 1, 6, app_->getAssetsManager()->getTexture(4), app_->getAssetsManager()->getTexture(1), nullptr,
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4, 200), 500, 10, 50, 50, SetBright, nullptr, LessBright, MoreBright, "", "");

	tuple<Entity*, Entity*, Entity*, Entity*> resolutionSlider = UIFactory::createSlider(app_, this, 0, 10, 10, app_->getAssetsManager()->getTexture(4), app_->getAssetsManager()->getTexture(1), nullptr,
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4, 100), 500, 10, 50, 50, setResolution, nullptr, nullptr, nullptr, "", "");

	Entity* logic = entManager_.addEntity();
	logic->addComponent<OptionsLogic>(std::get<0>(resolutionSlider)->getComponent<Slider>(ecs::Slider),
		resolutionText->getComponent<TextComponent>(ecs::TextComponent),
		std::get<0>(brightSlider)->getComponent<Slider>(ecs::Slider),
		brightnessText->getComponent<TextComponent>(ecs::TextComponent));
}


void OptionsMenu::GoBackCallback(App* app) {
	app->getStateMachine()->popState();
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
