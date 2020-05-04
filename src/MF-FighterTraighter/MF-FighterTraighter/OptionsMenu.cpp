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
#include "NavigationController.h"
#include "ControlsMenu.h"
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
	GameState::init();
	/*Entity* bg = entManager_.addEntity();
	Transform* t = bg->addComponent<Transform>();
	t->setPosition(0, 0);
	t->setWidthHeight(800, 600);
	RenderImage* img = bg->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(7));*/

	Entity* ent = entManager_.addEntity();
	Transform* transform = ent->addComponent<Transform>();
	transform->setWidthHeight(WIDTH_LOGO, HEIGHT_LOGO);
	transform->setPosition(app_->getWindowManager()->getCurResolution().w / 4, POS_Y_LOGO / 2);
	RenderImage* img = ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Logo));

	tuple<Entity*, Entity*> back = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 20), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0),
		Vector2D(100, 30),
		200, 80, 0, GoBackCallback, nullptr, "BACK", 60, TextComponent::TextAlignment::Center);

	tuple<Entity*, Entity*> fullscreen = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -200), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(200, 25),
		400, 50, 0,
		nullptr, fullScreen, "FULLSCREEN", 60, TextComponent::TextAlignment::Center);

	tuple<Entity*, Entity*> controls = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -300), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2), Vector2D(200, 25), 400, 50, 0, GoControlsCallback, nullptr, "Controls", 60);

	tuple<Entity*, Entity*, Entity*, Entity*> resolutionSlider = UIFactory::createSlider(app_, this, 0, 10, 10,
		app_->getAssetsManager()->getTexture(AssetsManager::SliderRegulator), app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 5),
		500, 10, setResolution, "RESOLUTION", 60, "", 60);

	tuple<Entity*, Entity*, Entity*, Entity*> brightSlider = UIFactory::createSlider(app_, this, 0.4, 1, 6,
		app_->getAssetsManager()->getTexture(AssetsManager::SliderRegulator), app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 50), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 5),
		500, 10, SetBright, "BRIGHTNESS", 60, "", 60);

	tuple<Entity*, Entity*, Entity*, Entity*> MusicSlider = UIFactory::createSlider(app_, this, 0, 128, 10,
		app_->getAssetsManager()->getTexture(AssetsManager::SliderRegulator), app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 150), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 5),
		500, 10, SetVolume, "Music Volume", 60, "", 60);

tuple<Entity*, Entity*, Entity*, Entity*> SoundSlider = UIFactory::createSlider(app_, this, 0, 128, 10,
		app_->getAssetsManager()->getTexture(AssetsManager::SliderRegulator), app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 250), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 5),
		500, 10, SetSfxVolume, "Sound Volume", 60, "", 60);

	tuple<Entity*, Entity*> applyButton = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 350), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2), 
		Vector2D(100, 30), 
		200, 60, 0,	nullptr, applySettings, "APPLY", 60, TextComponent::TextAlignment::Center);

	Entity* logic = entManager_.addEntity();
	logic->addComponent<OptionsLogic>
        (std::get<0>(resolutionSlider)->getComponent<Slider>(ecs::UIElement),
		std::get<3>(resolutionSlider)->getComponent<TextComponent>(ecs::TextComponent),
		std::get<0>(brightSlider)->getComponent<Slider>(ecs::UIElement),
		std::get<3>(brightSlider)->getComponent<TextComponent>(ecs::TextComponent),
        std::get<0>(MusicSlider)->getComponent<Slider>(ecs::UIElement),
		std::get<3>(MusicSlider)->getComponent<TextComponent>(ecs::TextComponent),
        std::get<0>(SoundSlider)->getComponent<Slider>(ecs::UIElement),
		std::get<3>(SoundSlider)->getComponent<TextComponent>(ecs::TextComponent));

	Entity* nav = entManager_.addEntity();
	NavigationController* ctrl = nav->addComponent<NavigationController>(1, 8);
	ctrl->SetElementInPos(std::get<0>(back)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl->SetElementInPos(std::get<0>(controls)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	ctrl->SetElementInPos(std::get<0>(fullscreen)->getComponent<UIElement>(ecs::UIElement), 0, 2);	
	ctrl->SetElementInPos(std::get<0>(resolutionSlider)->getComponent<UIElement>(ecs::UIElement), 0, 3);
	ctrl->SetElementInPos(std::get<0>(brightSlider)->getComponent<UIElement>(ecs::UIElement), 0, 4);
	ctrl->SetElementInPos(std::get<0>(MusicSlider)->getComponent<UIElement>(ecs::UIElement), 0, 5);
	ctrl->SetElementInPos(std::get<0>(SoundSlider)->getComponent<UIElement>(ecs::UIElement), 0, 6);
	ctrl->SetElementInPos(std::get<0>(applyButton)->getComponent<UIElement>(ecs::UIElement), 0, 7);
}

void OptionsMenu::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getGameManager()->pressedStart();
	}
	else
		GameState::handleInput();
}


void OptionsMenu::GoBackCallback(App* app) {
	app->getStateMachine()->popState();
}
void OptionsMenu::GoControlsCallback(App* app) {
	app->getStateMachine()->pushState(new ControlsMenu(app));
}

void OptionsMenu::SetBright(App* app, double value)
{
	app->getWindowManager()->setBrightness(value);
	// also save to a config file
}



void OptionsMenu::SetVolume(App* app, double value)
{
	app->getAudioMngr()->setMusicVolume((int)value);

}


void OptionsMenu::SetSfxVolume(App* app, double value)
{
	app->getAudioMngr()->setSFXVolume((int)value);
}

/*
void OptionsMenu::SetVolume(App* app, double value) //CAMBIAR CUANDO TENGAMOS UN SOUND MANAGER/AUDIO MANAGER
{
	SDL_SetWindowBrightness(app->getWindowManager()->getWindow(), value);
	// also save to a config file
}*/

//fullscreen
void OptionsMenu::fullScreen(App* app) {
	bool IsFullscreen = SDL_GetWindowFlags(app->getWindowManager()->getWindow()) & SDL_WINDOW_FULLSCREEN_DESKTOP;
	app->getWindowManager()->setFullscreen(!IsFullscreen);
	// also save to a config file
}

double OptionsMenu::curResolution_ = 0;
void OptionsMenu::setResolution(App* app, double value)
{
	OptionsMenu::curResolution_ = value;
	// also save to a config file
}

void OptionsMenu::applySettings(App* app)
{
	app->getWindowManager()->setResolution(lround(OptionsMenu::curResolution_));
}
