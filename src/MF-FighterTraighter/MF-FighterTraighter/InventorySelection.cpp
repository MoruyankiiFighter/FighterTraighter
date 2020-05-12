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
	//crear fondo ->ser� el fndo de la pelea i guess???


	//ESTO ES PARA DEPURAR
	for (int i = 0; i < 3; i++) {
		app_->getGameManager()->addHability(app_->getGameManager()->MegatonGrip, 1);
	}

	for (int i = 0; i < 8; i++) {
		app_->getGameManager()->addHability(app_->getGameManager()->MegatonGrip, 2);
	}
	//


	Entity* b = entManager_.addEntity();
	b->addComponent<UITransform>(Vector2D(), Vector2D(), Vector2D(), Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h));
	b->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight));

	//j1 fondo submenu
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
		Vector2D(0, 0), Vector2D(50, 50), Vector2D(0, 0), (app_->getWindowManager()->getCurResolution().w / 2) - 100, app_->getWindowManager()->getCurResolution().h - 100, 0);
	
	//j2 fondo submenu
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
		Vector2D(0, 0),
		Vector2D(app_->getWindowManager()->getCurResolution().w - 430, 50),
		Vector2D(430 + 50, 0),
		(app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h) - 100, 0);
	

	// Texto central
	Entity* text_ = entManager_.addEntity();
	//Vector2D pos, Vector2D anchor, Vector2D pivot, Vector2D size
	text_->addComponent<UITransform>(Vector2D(0, 0), Vector2D((app_->getWindowManager()->getCurResolution().w/2 ), 0), Vector2D((app_->getWindowManager()->getCurResolution().w /2), 0), Vector2D(app_->getWindowManager()->getCurResolution().w - 50, (app_->getWindowManager()->getCurResolution().h / 20) +50));
	text_->addComponent<TextComponent>("Selecciona tus habilidades", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 80, TextComponent::TextAlignment::Center);

	//ranuras j1

	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 4) - 200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
		Vector2D(80, 80),
		(160), (160), 0, nullptr, nullptr, "Boton L1", 25, TextComponent::TextAlignment::Center);
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 4) + 200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
		Vector2D(80, 80),
		(160), (160), 0, nullptr, nullptr, "Boton R1", 25, TextComponent::TextAlignment::Center);


	//boton
	tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -(90 + 50 + 50)),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 4) * 3, app_->getWindowManager()->getCurResolution().h),
		Vector2D(320, 90),
		640, 180, 0, GoToFight, nullptr, "Continue_J2", 80, TextComponent::TextAlignment::Center);
	std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Bottom;

	//j2
	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -(90 + 50 + 50)),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4, app_->getWindowManager()->getCurResolution().h),
		Vector2D(320, 90),
		640, 180, 0, GoToFight, nullptr, "Continue_J1", 80, TextComponent::TextAlignment::Center);
	std::get<1>(boton2)->getComponent<UITransform>(ecs::Transform)->Bottom;

	//ranuras j2

	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0),
		Vector2D(((app_->getWindowManager()->getCurResolution().w / 4) * 3) - 200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
		Vector2D(80, 80),
		(160), (160), 0, nullptr, nullptr, "Boton L2", 25, TextComponent::TextAlignment::Center);
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0),
		Vector2D(((app_->getWindowManager()->getCurResolution().w / 4) * 3) + 200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
		Vector2D(80, 80),
		(160), (160), 0, nullptr, nullptr, "Boton R2", 25, TextComponent::TextAlignment::Center);

	/*for(int i=0, i<app_->getGameManager()->get.....abilities.size())
		crear mierda
	*/

	//hab j1
	Entity* nav_j1 = entManager_.addEntity();

	NavigationController* ctrl = nav_j1->addComponent<NavigationController>(5, 3, app_->getGameManager()->getPlayerInfo(1).hid);

	for (int i = 0; i < 10; i++) {

		tuple <Entity*, Entity*> habj1;

		if (i < app_->getGameManager()->getPlayerInfo(1).abilities.size()) {


			if (i < 5) { //cambiarlo por la mitad del vector
				tuple <Entity*, Entity*> habj1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Doping), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
					(app_->getWindowManager()->getCurResolution().w / 15), (app_->getWindowManager()->getCurResolution().w / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
				ctrl->SetElementInPos(std::get<0>(habj1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			}
			else {
				tuple <Entity*, Entity*> habj1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Doping), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
					(app_->getWindowManager()->getCurResolution().w / 15), (app_->getWindowManager()->getCurResolution().w / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
				ctrl->SetElementInPos(std::get<0>(habj1)->getComponent<UIElement>(ecs::UIElement), i - 5, 1);
			}
		}

		else {
			if (i < 5) { //cambiarlo por la mitad del vector
				tuple <Entity*, Entity*> habj1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
					(app_->getWindowManager()->getCurResolution().w / 15), (app_->getWindowManager()->getCurResolution().w / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
				ctrl->SetElementInPos(std::get<0>(habj1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			}

			else {
				tuple <Entity*, Entity*> habj1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
					Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 40, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
					(app_->getWindowManager()->getCurResolution().w / 15), (app_->getWindowManager()->getCurResolution().w / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
				ctrl->SetElementInPos(std::get<0>(habj1)->getComponent<UIElement>(ecs::UIElement), i - 5, 1);
			}

		}

	}

	for (int i = 0; i < 5; i++) {
		ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), i, 2);
	}
	// inv j1


	//hab j2
	Entity* nav_j2 = entManager_.addEntity();
	NavigationController* ctrl_ = nav_j2->addComponent<NavigationController>(5, 3, app_->getGameManager()->getPlayerInfo(2).hid);

	for (int i = 0; i < 10; i++) {

		if (i < app_->getGameManager()->getPlayerInfo(2).abilities.size()) {


		if (i < 5) { //cambiarlo por la mitad del vector
			tuple <Entity*, Entity*> habj2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Doping), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
				Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
				Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
				Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
				(app_->getWindowManager()->getCurResolution().w / 15), (app_->getWindowManager()->getCurResolution().w / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
			ctrl_->SetElementInPos(std::get<0>(habj2)->getComponent<UIElement>(ecs::UIElement), i, 0);
		}
		else {
			tuple <Entity*, Entity*> habj2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Doping), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
				Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
				Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
				Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
				(app_->getWindowManager()->getCurResolution().w / 15), (app_->getWindowManager()->getCurResolution().w / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
			ctrl_->SetElementInPos(std::get<0>(habj2)->getComponent<UIElement>(ecs::UIElement), i - 5, 1);
		}
	}

	else {
	if (i < 5) { //cambiarlo por la mitad del vector
		tuple <Entity*, Entity*> habj2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Doping), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
			Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
			Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + i * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 4.7),
			(app_->getWindowManager()->getCurResolution().w / 15), (app_->getWindowManager()->getCurResolution().w / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		ctrl_->SetElementInPos(std::get<0>(habj2)->getComponent<UIElement>(ecs::UIElement), i, 0);
	}

	else {
		tuple <Entity*, Entity*> habj2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
			Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
			Vector2D(((app_->getWindowManager()->getCurResolution().w / 15) + (i - 5) * (app_->getWindowManager()->getCurResolution().w / 15)) + 1000, (app_->getWindowManager()->getCurResolution().h / 15) * 6.7),
			(app_->getWindowManager()->getCurResolution().w / 15), (app_->getWindowManager()->getCurResolution().w / 15), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		ctrl_->SetElementInPos(std::get<0>(habj2)->getComponent<UIElement>(ecs::UIElement), i - 5, 1);
		}
	}
	}
	for (int i = 0; i < 5; i++) {
			
			ctrl_->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), i, 2);
	}
	// Navigation controller
}

void InventorySelection::SetFirstSkill(App* app, int n)
{
	//comprobar que la hab asignada sea diferente a la segunda pra evitar hab repetidas
	app->getGameManager()->setFirstHab(app->getGameManager()->ExplosiveWillpower, n); //provisional
	
}

void InventorySelection::SetSecondSkill(App* app, int n)
{

	//comprobar que la hab asignada sea diferente a la primera para evitar hab repetidas
	app->getGameManager()->setSecondHab(app->getGameManager()->ExplosiveWillpower, n); //provisional
	
}

void InventorySelection::GoToFight(App* app)
{
	app->getStateMachine()->pushState(new Fight(app));
}
