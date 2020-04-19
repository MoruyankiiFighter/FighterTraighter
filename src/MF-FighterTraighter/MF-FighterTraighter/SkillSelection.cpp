#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"

void SkillSelection::init()
{
	// Fondo?

	// Paneles de fondo

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo), 
		Vector2D(50, 50), (app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo), 
		Vector2D((app_->getWindowManager()->getCurResolution().w / 2) + 50, 50), (app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);

	// boton de cambio de estado


	tuple < Entity*, Entity*> options = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(-300, 300), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		500, 150, 0, nullptr, nullptr, "Continue", 150, TextComponent::TextAlignment::Center);

	tuple < Entity*, Entity*> exit = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(300, 300), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		500, 150, 0, nullptr, nullptr, "Acept", 150, TextComponent::TextAlignment::Center);


	//UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//	Vector2D(0, 0), Vector2D((((app_->getWindowManager()->getCurResolution().w / 2) / 2)) - 150, ((app_->getWindowManager()->getCurResolution().h) - 225)), Vector2D(0, 75),
	//	300, 75, 0, nullptr, nullptr, "Continue", 25, TextComponent::TextAlignment::Center);

	//UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//	Vector2D(0, 0), Vector2D((((app_->getWindowManager()->getCurResolution().w / 4) * 3)) - 150, ((app_->getWindowManager()->getCurResolution().h) - 225)), Vector2D(0, 150),
	//	300, 75, 0, nullptr, nullptr, "Continue2", 25, TextComponent::TextAlignment::Center);
}

void SkillSelection::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->popState();
	}
	else
		GameState::handleInput();
}