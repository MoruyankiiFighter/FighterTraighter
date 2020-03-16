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
	Entity* ent = new Entity();
	Transform* transform = ent->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(WINDOW_WIDTH_ / 4, POS_Y_LOGO/2);
	RenderImage* img = ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	Transform* t = ent->addComponent<Transform>();
	t->setPosition(10, 10);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	
	ent->addComponent<Button>(GoBackCallback);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_-100, WINDOW_HEIGHT_-100);
	t->setWidth(10);
	t->setHeight(10);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(fullScreen);
	scene.push_back(ent);

	//slidebar
	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 4, 230);
	t->setWidth(500);
	t->setHeight(10);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	ent->addComponent<Button>(SetBright);
	scene.push_back(ent);
	
	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ /4 , 430);
	t->setWidth(500);
	t->setHeight(10);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	ent->addComponent<Button>(SetVolume);
	scene.push_back(ent);


	//buttons
	
	//bright
	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 4 +500, 200);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(moreBright);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 4 , 200);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(lessBright);
	scene.push_back(ent);


	//volume
	ent = new Entity();
	ent->setApp(app_);
	
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 4 , 400);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(lessSFXVolume);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 4 + 500, 400);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(moreSFXVolume);
	scene.push_back(ent);


	//regulators

	reg_bright = new Entity();
	
	reg_bright->setApp(app_);

	t = reg_bright->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 4 + 250, 200);
	t->setWidth(20);
	t->setHeight(50);
	t->setRotation(0);

	reg_bright->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(5));
	scene.push_back(reg_bright);

	reg_volume = new Entity();
	
	reg_volume->setApp(app_);

	t = reg_volume->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 2, 400);
	t->setWidth(20);
	t->setHeight(50);
	t->setRotation(0);

	reg_volume->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(5));
	scene.push_back(reg_volume);

	Entity* slider = new Entity();
	slider->setApp(app_);
	slider->addComponent<Transform>(Vector2D(50, 600), Vector2D(), 200, 70, 0);
	slider->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	slider->addComponent<Slider>(0, 100);
	scene.push_back(slider);
}

void OptionsMenu::update()
{
	GameState::update();
	Transform* t = reg_bright->getComponent<Transform>(ecs::Transform);
	//mover el regulador

	if (t->getPosition().getX() > WINDOW_WIDTH_ / 4 && t->getPosition().getX() < WINDOW_WIDTH_ / 4 + 500) {
		cout << "t" << endl;
	}
	double d = 50 +650* (SDL_GetWindowBrightness(app_->getWindow()));

	t->setPosition(d, t->getPosition().getY());
	
	// t = reg_volume->getComponent<Transform>(ecs::Transform);

	// d = 50 +650* (SDL_GetWindowBrightness(app_->getWindow()));

	cout << SDL_GetWindowBrightness(app_->getWindow());

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