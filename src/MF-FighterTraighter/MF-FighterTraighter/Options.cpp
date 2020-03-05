#include "Options.h"
#include <iostream>
#include "Entity.h"
#include "InputManager.h"


#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"

#include "App.h"
#include "consts.h"
Options::Options(App* app): GameState(app)
{
	std::cout << "Options";
}

Options::~Options()
{
}

void Options::init()
{
	Entity* options_logo=new Entity();

	Transform* t_logo = options_logo->addComponent<Transform>(); 
	t_logo->setPosition(WINDOW_WIDTH_ / 2, 200);
	t_logo->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);


	Entity* fullscreen = new Entity();

	Transform* button_ = fullscreen->addComponent<Transform>();
	
	Entity* audiovolume= new Entity(); //boton que se deslizará
	Entity* botonmas = new Entity();
	Entity* botonmenos = new Entity();


	Entity* backtomenu=new Entity;
}

void Options::update()
{
}

void Options::render()
{
}
