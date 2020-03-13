#include "OptionsMenu.h"
#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"

#include "App.h"
#include "consts.h"
#include "TextComponent.h"

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
	transform->setPosition(WINDOW_WIDTH_ / 2, POS_Y_LOGO);
	RenderImage* img = logo->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	scene.push_back(logo);

	Entity* ent = new Entity();
	ent->setApp(app_);
	Transform* t = ent->addComponent<Transform>();
	t->setPosition(10, 10);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<TextComponent>("<-" ,app_->getAssetsManager()->getFont(0), 30);

	ent->addComponent<Button>(GoBackCallback);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_-100, WINDOW_HEIGHT_-100);
	t->setWidth(100);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(fullScreen);
	scene.push_back(ent);

	//slidebar
	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 6, 230);
	t->setWidth(600);
	t->setHeight(10);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	scene.push_back(ent);
	
	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(WINDOW_WIDTH_ / 6, 430);
	t->setWidth(600);
	t->setHeight(10);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	scene.push_back(ent);


	//buttons
	
	//bright
	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(700, 200);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(moreBright);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	
	t = ent->addComponent<Transform>();
	t->setPosition(100, 200);
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
	t->setPosition(100, 400);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(lessSFXVolume);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	
	t = ent->addComponent<Transform>();
	t->setPosition(700, 400);
	t->setWidth(50);
	t->setHeight(50);
	t->setRotation(0);
	
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(1));
	ent->addComponent<Button>(moreSFXVolume);
	scene.push_back(ent);


	//regulators


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
	{
		for (auto var : scene) {
			var->handleInput();
		}
	}
}