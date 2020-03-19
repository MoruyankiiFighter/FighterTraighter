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
	transform->setPosition(WINDOW_WIDTH_ / 4, POS_Y_LOGO/2);
	RenderImage* img = ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(2));
	
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(10, 10), 60, 60, 0, GoBackCallback, nullptr, "<-", 20);
	
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(1), app_->getAssetsManager()->getFont(0),
		Vector2D(WINDOW_WIDTH_ / 4, 300), 150, 50, 0, nullptr, fullScreen, "FULLSCREEN", 20);
	
	
	//slidebar
	b_slider = entManager_.addEntity();
	Transform* tr= b_slider->addComponent<Transform>(Vector2D(WINDOW_WIDTH_ / 4, 230), Vector2D(), 500, 10, 0);
	b_slider->addComponent<Transform>(Vector2D(WINDOW_WIDTH_ / 4, 230), Vector2D(), 500, 10, 0);
	b_slider->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	Slider* b=b_slider->addComponent<Slider>(0.4, 1, 6, SetBright); // min = 0.4 to be able to see

	ent = entManager_.addEntity();
	ent->addComponent<Transform>(Vector2D(WINDOW_WIDTH_ / 4, 220), Vector2D(), 30, 50, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	ent->addComponent<IndexSlider>(tr, b);


	ent = entManager_.addEntity();
	ent->addComponent<Transform>(Vector2D(WINDOW_WIDTH_ / 4, 430), Vector2D(), 500, 10, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	ent->addComponent<Slider>(0, 1,10, SetVolume); // min = 0 (sound), although now it's set to change brightness
	
	ent = entManager_.addEntity();
	ent->addComponent<Transform>(Vector2D(WINDOW_WIDTH_ / 4, 800), Vector2D(), 500, 10, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(4));
	ent->addComponent<Slider>(1,1.2,5, setResolution); 

	Entity* controller = giveMeManager().addEntity();
	transform = controller->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(POS_X_BUTTONS, 500);
	controller->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(3));
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
		SDL_RenderSetLogicalSize(app->getRenderer(), WINDOW_WIDTH_ , WINDOW_HEIGHT_); //para que se redimensionen a su proporcion

	}
}

void setResolution(App* app, double resolution)
{
	if (resolution != 0) {
		SDL_RenderSetLogicalSize(app->getRenderer(),WINDOW_WIDTH_*resolution , WINDOW_HEIGHT_ * resolution); //para que se redimensionen a su proporcion
	}
}
