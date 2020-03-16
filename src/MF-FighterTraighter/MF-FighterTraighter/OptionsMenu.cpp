#include "OptionsMenu.h"
#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "Slider.h"

#include "App.h"
#include "consts.h"
#include "TextComponent.h"
#include "VerticalSlider.h"

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
	Entity* logo = new Entity();
	Transform* transform = logo->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(WINDOW_WIDTH_ / 2, POS_Y_LOGO/2);
	RenderImage* img = logo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	scene.push_back(logo);

	Entity* ent = new Entity();
	ent->setApp(app_);
	Transform* t = ent->addComponent<Transform>(Vector2D(10, 10), Vector2D(), 50, 50, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<TextComponent>("<-" ,app_->getAssetsManager()->getFont(0), 30);
	ent->addComponent<Button>(GoBackCallback);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>(Vector2D(WINDOW_WIDTH_ - 100, WINDOW_HEIGHT_ - 100), Vector2D(), 100, 100, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(fullScreen);
	scene.push_back(ent);

	//slidebar
	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>(Vector2D(WINDOW_WIDTH_ / 4, 230), Vector2D(), 500, 10, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	ent->addComponent<Slider>(0.4, 1, SetBright); // min = 0.4 to be able to see
	scene.push_back(ent);
	/*
	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>(Vector2D(WINDOW_WIDTH_ / 4, 430), Vector2D(), 500, 10, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	ent->addComponent<Slider>(0, 1, SetVolume); // min = 0 (sound), although now it's set to change brightness
	scene.push_back(ent);
	*/

	//buttons

}

void GoBackCallback(App* app) {
	app->getStateMachine()->popState();
}

void SetBright(App* app, double value)
{
	SDL_SetWindowBrightness(app->getWindow(), value);
}

void SetVolume(App* app, double value) //CAMBIAR CUANDO TENGAMOS UN SOUND MANAGER/AUDIO MANAGER
{
	SDL_SetWindowBrightness(app->getWindow(), value);
}

//fullscreen
void fullScreen(App* app) {
	bool IsFullscreen = SDL_GetWindowFlags(app->getWindow()) & SDL_WINDOW_FULLSCREEN_DESKTOP;
	if (IsFullscreen)
	{
		SDL_SetWindowFullscreen(app->getWindow(), 0);
	}
	else
	{
		SDL_SetWindowFullscreen(app->getWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);
		SDL_RenderSetLogicalSize(app->getRenderer(), WINDOW_WIDTH_, WINDOW_HEIGHT_); //para que se redimensionen a su proporcion

	}
}

void MenuCallback(App* app) {
	app->Menu();
}