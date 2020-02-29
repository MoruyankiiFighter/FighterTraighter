#include "MainMenu.h"
#include "InputManager.h"
#include "Entity.h"
#include "RenderImage.h"
#include "Transform.h"
#include "App.h"
MainMenu::MainMenu(App* app): GameState(app)
{
	scene.push_back(arcade);
	scene.push_back(pvp);
	scene.push_back(options);
	scene.push_back(exit);

}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
	
	string filePath = "../../../../Assets/Assets/UI/buttons.png";
	texture_ = new Texture(app_->getRenderer(),filePath.c_str(), 1, 3);
	arcade = new Entity();
	arcade->setApp(app_);
	arcade->addComponent<RenderImage>(texture_); //añadir textura
	Transform* t=arcade->addComponent<Transform>();
	t->setPosition(200, 300);
	t->setWidth(400);
	t->setHeight(150);

	pvp->addComponent<RenderImage>(texture_); //añadir textura
	t = pvp->addComponent<Transform>();
	t->setPosition(200, 500);
	t->setWidth(400);
	t->setHeight(150);

	options->addComponent<RenderImage>(texture_); //añadir textura
	t = options->addComponent<Transform>();
	t->setPosition(200, 700);
	t->setWidth(400);
	t->setHeight(150);


}

void MainMenu::render()
{

}

void MainMenu::update()
{
}

void MainMenu::handleInput()
{
	
}
