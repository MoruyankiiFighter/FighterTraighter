#include "PauseMenu.h"
#include "InputManager.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"

#include "App.h"
#include "consts.h"

void PauseMenu::init()
{
	cout << "initPausa" << endl;
	string filePath = "../../../../assets/Assets/images/UI/buttons.png";
	string filename_logo = "../../../../assets/Assets/images/UI/logo.png";
	texture_ = new Texture(app_->getRenderer(), filePath.c_str(), 1, 1);
	logo_ = new Texture(app_->getRenderer(), filename_logo.c_str(), 1, 1);

	Entity* logo = new Entity();
	Transform* transform = logo->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(WINDOW_WIDTH_ / 2, POS_Y_LOGO);
	RenderImage* img = logo->addComponent<RenderImage>(logo_);
	scene.push_back(logo);

	Entity* ent = new Entity();
	ent->setApp(app_);
	Transform* t = ent->addComponent<Transform>();
	t->setPosition(100, 100);
	t->setWidth(500);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(texture_); //añadir textura
	ent->addComponent<Button>(ContinuePlayingCallback);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(100, 300);
	t->setWidth(500);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(texture_); //añadir textura
	ent->addComponent<Button>(MenuCallback);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(100, 500);
	t->setWidth(500);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(texture_); //añadir textura
	ent->addComponent<Button>(MovementsCallback);
	scene.push_back(ent);

	ent = new Entity();
	ent->setApp(app_);
	t = ent->addComponent<Transform>();
	t->setPosition(100, 700);
	t->setWidth(500);
	t->setHeight(100);
	t->setRotation(0);
	ent->addComponent<RenderImage>(texture_); //añadir textura
	ent->addComponent<Button>(OptionsCallback);
	scene.push_back(ent);
}

void PauseMenu::render()
{
	SDL_RenderClear(app_->getRenderer());

	for (auto e : scene) {
		e->getComponent<RenderImage>(ecs::RenderImage)->render();
	}

	SDL_RenderPresent(app_->getRenderer());
}

void PauseMenu::update()
{
}

void PauseMenu::handleInput()
{
	for (auto var : scene) {
		var->handleInput();
	}
}
