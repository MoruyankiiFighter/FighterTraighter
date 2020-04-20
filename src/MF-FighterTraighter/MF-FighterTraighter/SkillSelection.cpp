#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"

void SkillSelection::init()
{
	// Fondo?

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::FSGente),
		Vector2D(0, 0),Vector2D(0,0),Vector2D(0,0), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);
	
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D(-100, 0),Vector2D(app_->getWindowManager()->getCurResolution().w/2,0),Vector2D((app_->getWindowManager()->getCurResolution().w / 2)-100 ,0), (app_->getWindowManager()->getCurResolution().w /2)-100, app_->getWindowManager()->getCurResolution().h, 0);

	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo),
		Vector2D(100, 0),Vector2D(app_->getWindowManager()->getCurResolution().w/2,0),Vector2D(0,0), app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h, 0);

	//// Paneles de fondo

	//UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo), 
	//	Vector2D(50, 50), Vector2D()(app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);

	//UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::SubMenuFondo), 
	//	Vector2D((app_->getWindowManager()->getCurResolution().w / 2) + 50, 50), (app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);
	//// Texto informativo


	}

void SkillSelection::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getStateMachine()->popState();
	}
	else
		GameState::handleInput();
}

void SkillSelection::createFirstMenu()
{

	Entity* texto_ = entManager_.addEntity();
	texto_->addComponent<Transform>(Vector2D((app_->getWindowManager()->getCurResolution().w / 2) - 425, 50), Vector2D(0, 0),
		(app_->getWindowManager()->getCurResolution().w / 2) - 200, 100, 0);
	texto_->addComponent<TextComponent>("Elige tu habilidad", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 75, TextComponent::TextAlignment::Center);

	// boton de cambio de estado

	tuple < Entity*, Entity*> options = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(-600, 400), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		300, 100, 0, nullptr, nullptr, "Continue", 50, TextComponent::TextAlignment::Center);

	tuple < Entity*, Entity*> exit = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(((app_->getWindowManager()->getCurResolution().h / 4) * 3) - 25, 400), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		300, 100, 0, nullptr, nullptr, "Acept", 50, TextComponent::TextAlignment::Center);

	if (win1) {
		// Fija ganador

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(-(app_->getWindowManager()->getCurResolution().w / 4) - (75), (app_->getWindowManager()->getCurResolution().h / 2) - 175), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Fija perdedor

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 4) - (75), (app_->getWindowManager()->getCurResolution().h / 2) - 175), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales ganador

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(-(app_->getWindowManager()->getCurResolution().w / 4) - (75 + 225), (app_->getWindowManager()->getCurResolution().h / 2) - 400), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(-(app_->getWindowManager()->getCurResolution().w / 4) - 75 + 225, (app_->getWindowManager()->getCurResolution().h / 2) - 400), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales perdedor

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 4) - (75), (app_->getWindowManager()->getCurResolution().h / 2) - 400), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	}
	else {
		// Fija ganador

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 4) - (75), (app_->getWindowManager()->getCurResolution().h / 2) - 175), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Fija perdedor

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(-(app_->getWindowManager()->getCurResolution().w / 4) - (75), (app_->getWindowManager()->getCurResolution().h / 2) - 175), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales ganador

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 4) - (75 + 225), (app_->getWindowManager()->getCurResolution().h / 2) - 400), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Hielo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 4) - 75 + 225, (app_->getWindowManager()->getCurResolution().h / 2) - 400), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales perdedor

		UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(-(app_->getWindowManager()->getCurResolution().w / 4) - (75), (app_->getWindowManager()->getCurResolution().h / 2) - 400), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
			150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	}

}

void SkillSelection::createInventoryMenu()
{

	Entity* texto_ = entManager_.addEntity();
	texto_->addComponent<Transform>(Vector2D((app_->getWindowManager()->getCurResolution().w / 2) - 425, 50), Vector2D(0, 0),
		(app_->getWindowManager()->getCurResolution().w / 2) - 200, 100, 0);
	texto_->addComponent<TextComponent>(" ... ", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 75, TextComponent::TextAlignment::Center);

	// boton de cambio de estado

	//j1
	tuple < Entity*, Entity*> options = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(-600, 400), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		300, 100, 0, nullptr, nullptr, "Go to fight", 50, TextComponent::TextAlignment::Center);

	//j2
	tuple < Entity*, Entity*> exit = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(((app_->getWindowManager()->getCurResolution().h / 4) * 3) - 25, 400), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, app_->getWindowManager()->getCurResolution().h / 2),
		Vector2D(250, 75),
		300, 100, 0, nullptr, nullptr, "Go to fight too", 50, TextComponent::TextAlignment::Center);


	//habilidades j1
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Pollo), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 4) - (75), (app_->getWindowManager()->getCurResolution().h / 2) - 175), Vector2D((app_->getWindowManager()->getCurResolution().w / 2), 0), Vector2D(0, 0),
		150, 150, 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);


	//habilidades j2



}
