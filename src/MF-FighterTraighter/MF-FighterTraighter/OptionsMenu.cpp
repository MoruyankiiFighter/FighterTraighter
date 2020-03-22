#include "OptionsMenu.h"
#include "InputManager.h"

#include "Entity.h"
#include "UIFactory.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Slider.h"
#include "VerticalSlider.h"
#include "IndexSlider.h"

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

	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(10, 10), 60, 60, 0, GoBackCallback, nullptr, "<-", 20);

	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(WINDOW_WIDTH_ / 2 - 150, 300), 150, 50, 0, nullptr, fullScreen, "FULLSCREEN", 20);

	UIFactory::createSlider(app_, this, 0.4, 1, 6, app_->getAssetsManager()->getTexture(4), app_->getAssetsManager()->getTexture(1), nullptr,
		Vector2D(WINDOW_WIDTH_ / 4, 200), 500, 10, 50, 50, SetBright, nullptr, LessBright, MoreBright, "", "");

	UIFactory::createSlider(app_, this, 0, 10, 10, app_->getAssetsManager()->getTexture(4), app_->getAssetsManager()->getTexture(1), nullptr,
		Vector2D(WINDOW_WIDTH_ / 4, 100), 500, 10, 50, 50, setResolution, nullptr, nullptr, nullptr, "", "");
}

void GoBackCallback(App* app) {
	app->getStateMachine()->popState();
}

void SetBright(App* app, double value)
{
	SDL_SetWindowBrightness(app->getWindow(), value); // si a alguien se le queda la pantalla oscura, que ponga aquí un 1 y descomente lo de abajo
	//int b = 0;
	//int a = 1 / b;
}

void MoreBright(App* app)
{
	double flag = SDL_GetWindowBrightness(app->getWindow());
	flag += 0.1;
	if (flag > 1) {
		flag = 1;
	}
	SDL_SetWindowBrightness(app->getWindow(), flag);

}

void LessBright(App* app)
{
	double flag = SDL_GetWindowBrightness(app->getWindow());
	flag -= 0.1;
	if (flag < 0.4) {
		flag = 0.4;
	}
	SDL_SetWindowBrightness(app->getWindow(), flag);

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
