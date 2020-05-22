#include "InventorySelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "InventoryLogic.h"
#include "NavigationController.h"
#include "InventoryHandler.h"
void InventorySelection::init()
{
	GameState::init();


	Entity* b = entManager_.addEntity();
	b->addComponent<UITransform>(Vector2D(), Vector2D(), Vector2D(), Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h));
	b->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight));

	//j1 fondo submenu
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
		Vector2D(0, 0), Vector2D(50, 50), Vector2D(0, 0), (app_->getWindowManager()->getCurResolution().w / 2.0) - 100.0, app_->getWindowManager()->getCurResolution().h - 100.0, 0);
	
	//j2 fondo submenu
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
		Vector2D(0, 0),
		Vector2D((double)app_->getWindowManager()->getCurResolution().w - 430, 50),
		Vector2D(430.0 + 50.0, 0),
		double(app_->getWindowManager()->getCurResolution().w / 2) - 100, double(app_->getWindowManager()->getCurResolution().h) - 100, 0);
	

	// Texto central
	Entity* text_ = entManager_.addEntity();
	//Vector2D pos, Vector2D anchor, Vector2D pivot, Vector2D size
	text_->addComponent<UITransform>(Vector2D(0, 0), Vector2D((app_->getWindowManager()->getCurResolution().w/2 ), 0), Vector2D((app_->getWindowManager()->getCurResolution().w /2), 0), Vector2D((double)app_->getWindowManager()->getCurResolution().w - 50, ((double)app_->getWindowManager()->getCurResolution().h / 20) +50));
	text_->addComponent<TextComponent>("Selecciona tus habilidades", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 80, TextComponent::TextAlignment::Center);

	//ranuras j1

	Entity* left_j1 = entManager_.addEntity();
	left_j1->addComponent<UITransform>(Vector2D((double)app_->getWindowManager()->getCurResolution().w / 4- 200, 200), Vector2D((app_->getWindowManager()->getCurResolution().w / 4),100), Vector2D((app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	left_j1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
	
	Entity* right_j1 = entManager_.addEntity();
	right_j1->addComponent<UITransform>(Vector2D((double)app_->getWindowManager()->getCurResolution().w / 4 + 100, 200), Vector2D((app_->getWindowManager()->getCurResolution().w / 4),100), Vector2D((app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	right_j1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));

	//ranuras j2
	Entity* left_j2 = entManager_.addEntity();
	left_j2->addComponent<UITransform>(Vector2D(3 * (double)app_->getWindowManager()->getCurResolution().w / 4 - 200, 200), Vector2D((3 * (double)app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D((3 * (double)app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	left_j2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));

	Entity* right_j2 = entManager_.addEntity();
	right_j2->addComponent<UITransform>(Vector2D(3 * (double)app_->getWindowManager()->getCurResolution().w / 4 + 100, 200), Vector2D((3 * (double)app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D((3 * (double)app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	right_j2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));


	//boton
	tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -(90 + 50 + 50)),
		Vector2D(((double)app_->getWindowManager()->getCurResolution().w / 4) * 3, app_->getWindowManager()->getCurResolution().h),
		Vector2D(320, 90),
		640, 180, 0, nullptr, nullptr, "Continue_J2", 80, TextComponent::TextAlignment::Center);
	std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Bottom;

	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -(90 + 50 + 50)),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4, app_->getWindowManager()->getCurResolution().h),
		Vector2D(320, 90),
		640, 180, 0, nullptr, nullptr, "Continue_J1", 80, TextComponent::TextAlignment::Center);
	std::get<1>(boton2)->getComponent<UITransform>(ecs::Transform)->Bottom;



	//hab j1
	Entity* nav_j1 = entManager_.addEntity();

	NavigationController* ctrl = nav_j1->addComponent<NavigationController>(5, 3, app_->getGameManager()->getPlayerInfo(1).hid);

	for (double i = 0; i < 10; i++) {

		tuple <Entity*, Entity*> habj1;

		if (i < app_->getGameManager()->getPlayerInfo(1).abilities.size()) {
			//128
			Entity* habj1 = entManager_.addEntity();
			if (i < 5) { 
				habj1->addComponent<UIElement>();
				habj1->addComponent<UITransform>(
					Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
					Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
					Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
					Vector2D(128, 128));
				habj1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
				ctrl->SetElementInPos((habj1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			}

			else {
				habj1->addComponent<UIElement>();
				habj1->addComponent<UITransform>(
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7), 
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
					Vector2D(128, 128));
				habj1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
				
				ctrl->SetElementInPos((habj1)->getComponent<UIElement>(ecs::UIElement), (i - 5), 1);
			}


			habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()
				->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(1).abilities[i] + 1)));

		}

		else {
			if (i < 5) { //cambiarlo por la mitad del vector
				tuple <Entity*, Entity*> habj1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
					Vector2D(((128) + i * (128)) + 40, (72) * 4.7),
					Vector2D(((128) + i * (128)) + 40, (72) * 4.7),
					Vector2D(((128) + i * (128)) + 40, (72) * 4.7),
					(128), (128), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
				ctrl->SetElementInPos(std::get<0>(habj1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			}

			else {
				tuple <Entity*, Entity*> habj1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
					(128), (128), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
				ctrl->SetElementInPos(std::get<0>(habj1)->getComponent<UIElement>(ecs::UIElement), (i - 5), 1);
			}

		}

	}
	

	for (int i = 0; i < 5; i++) {
		ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), i, 2);
	}



	//hab j2
	Entity* nav_j2 = entManager_.addEntity();
	NavigationController* ctrl_ = nav_j2->addComponent<NavigationController>(5, 3, app_->getGameManager()->getPlayerInfo(2).hid);
	//esto sería un for hasta abilities size para que no pete
	for (double i = 0; i < 10; i++) {

		Entity* habj2 = entManager_.addEntity();
		if (i < app_->getGameManager()->getPlayerInfo(2).abilities.size()) {


			if (i < 5) {

				habj2->addComponent<UIElement>();
				habj2->addComponent<UITransform>(
					Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
					Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
					Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
					Vector2D(128, 128));
				habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
				ctrl_->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), i, 0);

			}
			else {

				habj2->addComponent<UIElement>();
				habj2->addComponent<UITransform>(
					Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
					Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
					Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
					Vector2D(128, 128));
				habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
				ctrl_->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), (i - 5), 1);

			}

			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()
				->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(2).abilities[i] + 1))); //no vas a poder acceder
		}

		else {
			if (i < 5) { //cambiarlo por la mitad del vector
				habj2->addComponent<UIElement>();
				habj2->addComponent<UITransform>(
					Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
					Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
					Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
					Vector2D(128, 128));
				habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
				ctrl_->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), i, 0);

			}
			else {

				habj2->addComponent<UIElement>();
				habj2->addComponent<UITransform>(
					Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
					Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
					Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
					Vector2D(128, 128));
				habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
				ctrl_->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), (i - 5), 1);
			}
			
		}
	}
	for (int i = 0; i < 5; i++) {
			
		ctrl_->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), i, 2);
	}
	// Navigation controller

	Entity* logicJ1 = entManager_.addEntity();
	logicJ1->addComponent<InventoryLogic>(ctrl, 1, left_j1->getComponent<RenderImage>(ecs::RenderImage), right_j1->getComponent<RenderImage>(ecs::RenderImage));

	Entity* logicJ2 = entManager_.addEntity();
	logicJ2->addComponent<InventoryLogic>(ctrl_, 2, left_j2->getComponent<RenderImage>(ecs::RenderImage), right_j2->getComponent<RenderImage>(ecs::RenderImage));

	Entity* ent = entManager_.addEntity();
	ent->addComponent<InventoryHandler>(logicJ1, logicJ2);
}


