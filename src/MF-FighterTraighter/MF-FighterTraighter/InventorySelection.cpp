#include "InventorySelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "NavigationController.h"
void InventorySelection::init()
{

	Entity* b = entManager_.addEntity();
	b->addComponent<UITransform>(Vector2D(), Vector2D(), Vector2D(), Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h));
	b->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight));

	//j1
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D(0, 0), Vector2D(0, 0), Vector2D(0, 0), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h, 0);


	//crear habilidades
	Entity* text_ = entManager_.addEntity();
	//Vector2D pos, Vector2D anchor, Vector2D pivot, Vector2D size
	text_->addComponent<UITransform>(Vector2D(0, 0), Vector2D((app_->getWindowManager()->getCurResolution().w * 2) / 4, 0), Vector2D((app_->getWindowManager()->getCurResolution().w * 2) / 4, 0), Vector2D(app_->getWindowManager()->getCurResolution().w - (2 * 25), (app_->getWindowManager()->getCurResolution().h / 20) + (2 * 25)));
	text_->addComponent<TextComponent>("Elige tu habilidad", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 25, TextComponent::TextAlignment::Center);

	//boton

	tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 12, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 12, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 12, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		(app_->getWindowManager()->getCurResolution().w / 6) * 2, (app_->getWindowManager()->getCurResolution().h / 15) * 2.5, 0, nullptr, nullptr, "Continue", 25, TextComponent::TextAlignment::Center);
	std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Center;


	//j2
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D(50, 50), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0),
		(app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);

	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		(app_->getWindowManager()->getCurResolution().w / 6) * 2, (app_->getWindowManager()->getCurResolution().h / 15) * 2.5, 0,
		nullptr, nullptr, "Continue_", 25, TextComponent::TextAlignment::Center);
	std::get<1>(boton2)->getComponent<UITransform>(ecs::Transform)->Center;


	/*for(int i=0, i<app_->getGameManager()->get.....abilities.size()) 
		crear mierda
	*/

}
