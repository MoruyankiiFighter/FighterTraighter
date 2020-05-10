#include "InventorySelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "NavigationController.h"
void InventorySelection::init()
{
	GameState::init();
	//crear fondo ->será el fndo de la pelea i guess???

	Entity* b = entManager_.addEntity();
	b->addComponent<UITransform>(Vector2D(), Vector2D(), Vector2D(), Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h));
	b->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight));

	//j1 fondo submenu
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
		Vector2D(50, 50), Vector2D(50, 50), Vector2D(50, 50), (app_->getWindowManager()->getCurResolution().w / 2) - 100, app_->getWindowManager()->getCurResolution().h - 100, 0);
	//j2 fondo submenu
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 2) + 50, 0 + 50),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 2) + 50, 0 + 50),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 2) + 50, 0 + 50),
		(app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);


	// Texto central
	Entity* text_ = entManager_.addEntity();
	//Vector2D pos, Vector2D anchor, Vector2D pivot, Vector2D size
	text_->addComponent<UITransform>(Vector2D(0, 0), Vector2D((app_->getWindowManager()->getCurResolution().w * 2) / 4, 0), Vector2D((app_->getWindowManager()->getCurResolution().w * 2) / 4, 0), Vector2D(app_->getWindowManager()->getCurResolution().w - (2 * 25), (app_->getWindowManager()->getCurResolution().h / 20) + (2 * 25)));
	text_->addComponent<TextComponent>("Elige tu habilidad", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 80, TextComponent::TextAlignment::Center);

	//boton
	tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		(app_->getWindowManager()->getCurResolution().w / 6) * 2, (app_->getWindowManager()->getCurResolution().h / 15) * 2.5, 0,
		nullptr, nullptr, "Continue_J2", 80, TextComponent::TextAlignment::Center);
	std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Bottom;

	//j2
	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 12, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 12, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 12, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		(app_->getWindowManager()->getCurResolution().w / 6) * 2, (app_->getWindowManager()->getCurResolution().h / 15) * 2.5, 0,nullptr, nullptr, "Continue_J1", 80, TextComponent::TextAlignment::Center);
	std::get<1>(boton2)->getComponent<UITransform>(ecs::Transform)->Bottom;
	
	//habilidades j1
	for (int i = 0; i < app_->getGameManager()->getPlayerInfo(1).abilities.size() / 2; i++) {
		for (int j = 0; j < app_->getGameManager()->getPlayerInfo(1).abilities.size() / 2; j++) {

		}
	}
	
	for (int i = 0; i < app_->getGameManager()->getPlayerInfo(2).abilities.size() / 2; i++) {
		for (int j = 0; j < app_->getGameManager()->getPlayerInfo(2).abilities.size() / 2; j++) {

		}
	}

}
