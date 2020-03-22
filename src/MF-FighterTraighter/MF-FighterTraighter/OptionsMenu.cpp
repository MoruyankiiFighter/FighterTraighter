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
	transform->setPosition(WINDOW_WIDTH_ / 4, POS_Y_LOGO / 2);
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
		Vector2D(WINDOW_WIDTH_ / 2 - 150, 300), 150, 50, 0, nullptr, fullScreen, "FULLSCREEN", 20);

	tuple<Entity*, Entity*, Entity*, Entity*> brightSlider = UIFactory::createSlider(app_, this, 0.4, 1, 6, app_->getAssetsManager()->getTexture(4), app_->getAssetsManager()->getTexture(1), nullptr,
		Vector2D(WINDOW_WIDTH_ / 4, 200), 500, 10, 50, 50, SetBright, nullptr, LessBright, MoreBright, "", "");

	tuple<Entity*, Entity*, Entity*, Entity*> resolutionSlider = UIFactory::createSlider(app_, this, 0, 10, 10, app_->getAssetsManager()->getTexture(4), app_->getAssetsManager()->getTexture(1), nullptr,
		Vector2D(WINDOW_WIDTH_ / 4, 100), 500, 10, 50, 50, setResolution, nullptr, nullptr, nullptr, "", "");

	Entity* logic = entManager_.addEntity();
	logic->addComponent<OptionsLogic>(std::get<0>(resolutionSlider)->getComponent<Slider>(ecs::Slider),
		resolutionText->getComponent<TextComponent>(ecs::TextComponent),
		std::get<0>(brightSlider)->getComponent<Slider>(ecs::Slider),
		brightnessText->getComponent<TextComponent>(ecs::TextComponent));
}

void GoBackCallback(App* app) {
	app->getStateMachine()->popState();
}

void SetBright(App* app, double value)
{
	app->getWindowManager()->setBrightness(value);
}

void MoreBright(App* app)
{
	double flag = app->getWindowManager()->getCurBrightness();
	flag += 0.1;
	if (flag > 1) {
		flag = 1;
	}
	app->getWindowManager()->setBrightness(flag);
}

void LessBright(App* app)
{
	double flag = app->getWindowManager()->getCurBrightness();
	flag -= 0.1;
	if (flag < 0.4) {
		flag = 0.4;
	}
	app->getWindowManager()->setBrightness(flag);

}

void SetVolume(App* app, double value) //CAMBIAR CUANDO TENGAMOS UN SOUND MANAGER/AUDIO MANAGER
{
	SDL_SetWindowBrightness(app->getWindow(), value);
}

//fullscreen
void fullScreen(App* app) {
	bool IsFullscreen = SDL_GetWindowFlags(app->getWindow()) & SDL_WINDOW_FULLSCREEN_DESKTOP;
	app->getWindowManager()->setFullscreen(!IsFullscreen);
}

void setResolution(App* app, double value)
{
	app->getWindowManager()->setResolution(lround(value));
}
