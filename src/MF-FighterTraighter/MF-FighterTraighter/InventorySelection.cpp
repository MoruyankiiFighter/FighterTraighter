#include "InventorySelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "InventoryLogic.h"
#include "NavigationController.h"
void InventorySelection::init()
{
	GameState::init();
	//crear fondo ->ser� el fndo de la pelea i guess???


	//ESTO ES PARA DEPURAR
	for (int i = 0; i < 3; i++) {
		app_->getGameManager()->addHability(app_->getGameManager()->MegatonGrip, 1);
		app_->getGameManager()->addHability(app_->getGameManager()->SeismicShock, 1);
	}

	for (int i = 0; i < 5; i++) {
		app_->getGameManager()->addHability(app_->getGameManager()->MegatonGrip, 2);
		app_->getGameManager()->addHability(app_->getGameManager()->AcidSplit, 2);
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
/*
	UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 4) - 200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
		Vector2D(80, 80),
		(160), (160), 0, nullptr, nullptr, "Boton L1", 25, TextComponent::TextAlignment::Center);
	*//*UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, 0),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 4) + 200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
		Vector2D(80, 80),
		(160), (160), 0, nullptr, nullptr, "Boton R1", 25, TextComponent::TextAlignment::Center);*/
	
	Entity* left_j1 = entManager_.addEntity();
	left_j1->addComponent<UITransform>(Vector2D(app_->getWindowManager()->getCurResolution().w / 4- 200, 200), Vector2D((app_->getWindowManager()->getCurResolution().w / 4),100), Vector2D((app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	left_j1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
	
	Entity* right_j1 = entManager_.addEntity();
	right_j1->addComponent<UITransform>(Vector2D(app_->getWindowManager()->getCurResolution().w / 4 + 100, 200), Vector2D((app_->getWindowManager()->getCurResolution().w / 4),100), Vector2D((app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	right_j1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));

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

	Entity* left_j2 = entManager_.addEntity();
	left_j2->addComponent<UITransform>(Vector2D(3*app_->getWindowManager()->getCurResolution().w / 4 - 200, 200), Vector2D((3*app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D((3*app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	left_j2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));

	Entity* right_j2 = entManager_.addEntity();
	right_j2->addComponent<UITransform>(Vector2D(3*app_->getWindowManager()->getCurResolution().w / 4 + 100, 200), Vector2D((3*app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D((3*app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	right_j2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));


	//hab j1
	Entity* nav_j1 = entManager_.addEntity();

	NavigationController* ctrl = nav_j1->addComponent<NavigationController>(5, 3, app_->getGameManager()->getPlayerInfo(1).hid);

	for (int i = 0; i < 10; i++) {

		tuple <Entity*, Entity*> habj1;

		if (i < app_->getGameManager()->getPlayerInfo(1).abilities.size()) {
			//128
			Entity* habj1 = entManager_.addEntity();
			if (i < 5) { //cambiarlo por la mitad del vector
				/*tuple <Entity*, Entity*> habj1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Doping), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
					Vector2D(((128) + i * (128)) + 40, (72) * 4.7),
					Vector2D(((128) + i * (128)) + 40, (72) * 4.7),
					Vector2D(((128) + i * (128)) + 40, (72) * 4.7),
					(128), (128), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);*/
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
				
				ctrl->SetElementInPos((habj1)->getComponent<UIElement>(ecs::UIElement), i - 5, 1);
			}


			switch (app_->getGameManager()->getPlayerInfo(1).abilities[i])
			{
			case GameManager::MegatonGrip:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::M_Grip_ico));
				break;

			case GameManager::SeismicShock:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::S_Sock_ico));
				break;

			case GameManager::ExplosiveWillpower:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Ex_Will_ico));
				break;

			case GameManager::AcidSplit:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Acid_ico));
				break;

			case GameManager::Mina:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Mina_ico));
				break;

			case GameManager::ShrugOff:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::ShrugOff_ico));
				break;

			case GameManager::MorePower:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::MorePower_ico));
				break;
			case GameManager::Hookshot:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Hook_ico));
				break;
			case GameManager::Dash:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Dash_ico));
				break;
			case GameManager::VampiricStrike:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Vampiric_ico));
				break;
			case GameManager::HailBall:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::HailBall_ico));
				break;
			case GameManager::ReachingStrike:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Reach_ico));
				break;
			case GameManager::FlyingKicks:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::FlyingKicks_ico));
				break;
			case GameManager::LaserLineal:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::L_Lineal_ico));
				break;
			case GameManager::NadoKick:
				habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Nado_ico));
				break;

			default:
				break;
			}





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
				ctrl->SetElementInPos(std::get<0>(habj1)->getComponent<UIElement>(ecs::UIElement), i - 5, 1);
			}

		}

	}
	

	for (int i = 0; i < 5; i++) {
		ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), i, 2);
	}

	Entity* logicJ1 = entManager_.addEntity();
	logicJ1->addComponent<InventoryLogic>(ctrl, 1, left_j1->getComponent<RenderImage>(ecs::RenderImage), right_j1->getComponent<RenderImage>(ecs::RenderImage));


	// inv j1


	//hab j2
	Entity* nav_j2 = entManager_.addEntity();
	NavigationController* ctrl_ = nav_j2->addComponent<NavigationController>(5, 3, app_->getGameManager()->getPlayerInfo(2).hid);

	for (int i = 0; i < 10; i++) {

		if (i < app_->getGameManager()->getPlayerInfo(2).abilities.size()) {

			Entity* habj2=entManager_.addEntity();
		if (i < 5) { //cambiarlo por la mitad del vector
			
			habj2->addComponent<UIElement>();
			habj2->addComponent<UITransform>(
				Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
				Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
				Vector2D(((128) + (i) * (128)) + 1000, (72) * 4.7),
				Vector2D(128, 128));
			habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
			ctrl->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), i, 0);

		}
		else {
			/*tuple <Entity*, Entity*> habj2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Doping), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
				Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
				Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
				Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
				(128), (128), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
			ctrl_->SetElementInPos(std::get<0>(habj2)->getComponent<UIElement>(ecs::UIElement), i - 5, 1);*/
		
			habj2->addComponent<UIElement>();
			habj2->addComponent<UITransform>(
				Vector2D(((128) + (i-5) * (128)) + 1000, (72) * 6.7),
				Vector2D(((128) + (i-5) * (128)) + 1000, (72) * 6.7),
				Vector2D(((128) + (i-5) * (128)) + 1000, (72) * 6.7),
				Vector2D(128, 128));
			habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::Player));
			ctrl->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), i-5, 1);

		}

		switch (app_->getGameManager()->getPlayerInfo(2).abilities[i])
		{
		case GameManager::MegatonGrip:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::M_Grip_ico));
			break;

		case GameManager::SeismicShock:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::S_Sock_ico));
			break;

		case GameManager::ExplosiveWillpower:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Ex_Will_ico));
			break;

		case GameManager::AcidSplit:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Acid_ico));
			break;

		case GameManager::Mina:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Mina_ico));
			break;

		case GameManager::ShrugOff:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::ShrugOff_ico));
			break;

		case GameManager::MorePower:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::MorePower_ico));
			break;
		case GameManager::Hookshot:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Hook_ico));
			break;
		case GameManager::Dash:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Dash_ico));
			break;
		case GameManager::VampiricStrike:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Vampiric_ico));
			break;
		case GameManager::HailBall:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::HailBall_ico));
			break;
		case GameManager::ReachingStrike:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Reach_ico));
			break;
		case GameManager::FlyingKicks:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::FlyingKicks_ico));
			break;
		case GameManager::LaserLineal:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::L_Lineal_ico));
			break;
		case GameManager::NadoKick:
			habj2->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Nado_ico));
			break;

		default:
			break;
		}

	}

	else {
	if (i < 5) { //cambiarlo por la mitad del vector
		tuple <Entity*, Entity*> habj2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Doping), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(((128) + i * (128)) + 1000, (72) * 4.7),
			Vector2D(((128) + i * (128)) + 1000, (72) * 4.7),
			Vector2D(((128) + i * (128)) + 1000, (72) * 4.7),
			(128), (128), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		ctrl_->SetElementInPos(std::get<0>(habj2)->getComponent<UIElement>(ecs::UIElement), i, 0);
	}

	else {
		tuple <Entity*, Entity*> habj2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Player), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
			Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
			Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
			(128), (128), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
		ctrl_->SetElementInPos(std::get<0>(habj2)->getComponent<UIElement>(ecs::UIElement), i - 5, 1);
		}
	}
	}
	for (int i = 0; i < 5; i++) {
			
			ctrl_->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), i, 2);
	}
	// Navigation controller

	//Entity* logicJ2 = entManager_.addEntity();
	//logicJ2->addComponent<InventoryLogic>(ctrl_, 2, left_j2->getComponent<RenderImage>(ecs::RenderImage), right_j2->getComponent<RenderImage>(ecs::RenderImage));

}

void InventorySelection::GoToFight(App* app)
{
	app->getStateMachine()->pushState(new Fight(app));
}
