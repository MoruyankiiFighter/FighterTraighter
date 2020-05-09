#include "SkillSelection.h"
#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "NavigationController.h"
#include "InventorySelection.h"

void SkillSelection::init()
{
	//crear fondo ->será el fndo de la pelea i guess???

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
		(app_->getWindowManager()->getCurResolution().w / 6) * 2,(app_->getWindowManager()->getCurResolution().h / 15) * 2.5, 0, GoToNextSubMenu, nullptr, "Continue", 25, TextComponent::TextAlignment::Center);
	std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Center;
	

	//j2
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Background),
		Vector2D(50, 50), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0), Vector2D(app_->getWindowManager()->getCurResolution().w / 2, 0),
		(app_->getWindowManager()->getCurResolution().w / 2) - 100, (app_->getWindowManager()->getCurResolution().h)-100, 0);

	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 2) * 1.5),
		(app_->getWindowManager()->getCurResolution().w / 6) * 2, (app_->getWindowManager()->getCurResolution().h / 15) * 2.5, 0, 
		GoToNextSubMenu, nullptr, "Continue_", 25, TextComponent::TextAlignment::Center);
	std::get<1>(boton2)->getComponent<UITransform>(ecs::Transform)->Center;
	
	if (win1) {
		// Fija ganador

		tuple<Entity*, Entity*> hf_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h / 6) * 2),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h / 6) * 2),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h / 6) * 2),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Fija perdedor

		tuple<Entity*, Entity*> hf_lose = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h/ 6) * 2),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h / 6) * 2),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h/ 6) * 2),
			(app_->getWindowManager()->getCurResolution().w  / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales ganador

		tuple<Entity*, Entity*> hop_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 1, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 1, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 1, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	
		tuple<Entity*, Entity*> hop_win2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 4, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 4, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 4, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	
		// Opcionales perdedor
		tuple<Entity*, Entity*> hop_lose = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	
	
	//nav1

	//winner
	Entity* nav_win = entManager_.addEntity();
	NavigationController* ctrl = nav_win->addComponent<NavigationController>(2, 3, app_->getGameManager()->getPlayerInfo(1).hid);
	ctrl->SetElementInPos(std::get<0>(hop_win)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl->SetElementInPos(std::get<0>(hop_win2)->getComponent<UIElement>(ecs::UIElement), 1, 0);
	ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 1, 1);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 1, 2);

	//loser
	Entity* nav_loser = entManager_.addEntity();
	NavigationController* ctrl_ = nav_loser->addComponent<NavigationController>(1, 3, app_->getGameManager()->getPlayerInfo(2).hid);
	ctrl_->SetElementInPos(std::get<0>(hop_lose)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	ctrl_->SetElementInPos(std::get<0>(hf_lose)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	ctrl_->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	
	}
	else
	{
		
		//gana player 2

		   // Fija ganador
		tuple<Entity*, Entity*> hf_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h / 6) * 2),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h/ 6) * 2),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 8.5, (app_->getWindowManager()->getCurResolution().h / 6) * 2),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		
		// Fija perdedor
		tuple<Entity*, Entity*> hf_lose = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h / 6) * 2),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h/ 6) * 2),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h / 6) * 2),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales ganador
		tuple<Entity*, Entity*> hop_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h/ 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 7, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		tuple<Entity*, Entity*> hop_win2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 10, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 10, (app_->getWindowManager()->getCurResolution().h/ 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 10, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		// Opcionales perdedor
		tuple<Entity*, Entity*> hop_lose = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h/ 12) * 1.7),
			Vector2D((app_->getWindowManager()->getCurResolution().w / 12) * 2.5, (app_->getWindowManager()->getCurResolution().h / 12) * 1.7),
			(app_->getWindowManager()->getCurResolution().w / 12), (app_->getWindowManager()->getCurResolution().w / 12), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

		//winner
		Entity* nav_win = entManager_.addEntity();
		NavigationController* ctrl = nav_win->addComponent<NavigationController>(2, 3, app_->getGameManager()->getPlayerInfo(2).hid);
		ctrl->SetElementInPos(std::get<0>(hop_win)->getComponent<UIElement>(ecs::UIElement), 0, 0);
		ctrl->SetElementInPos(std::get<0>(hop_win2)->getComponent<UIElement>(ecs::UIElement), 1, 0);
		ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 0, 1);
		ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 1, 1);
		ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 0, 2);
		ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 1, 2);

		//loser
		Entity* nav_loser = entManager_.addEntity();
		NavigationController* ctrl_ = nav_loser->addComponent<NavigationController>(1, 3, app_->getGameManager()->getPlayerInfo(1).hid);
		ctrl_->SetElementInPos(std::get<0>(hop_lose)->getComponent<UIElement>(ecs::UIElement), 0, 0);
		ctrl_->SetElementInPos(std::get<0>(hf_lose)->getComponent<UIElement>(ecs::UIElement), 0, 1);
		ctrl_->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 0, 2);
		
	}


}

void SkillSelection::GoToNextSubMenu(App* app)
{
	app->getStateMachine()->pushState(new InventorySelection(app));
}
