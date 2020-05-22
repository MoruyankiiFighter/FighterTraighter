#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "NavigationController.h"
#include "InventorySelection.h"
//#include "GameManager.h"

void SkillSelection::init()
{
	GameState::init();
	//crear fondo ->ser� el fndo de la pelea i guess???

	
	//Background
	Entity* b = entManager_.addEntity();
	b->addComponent<UITransform>(Vector2D(), Vector2D(), Vector2D(), Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h));
	b->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight));


	//GameStateMachine* stateMachine = app_->getStateMachine();
	//GameManager::PlayerInfo *pWin = nullptr,
	//						*pLose = nullptr;
	int loser = 1;
	if (winner_ == 1) 
		loser = 2;
	//	pWin = &player1_;
	//	pLose = &player2_;
	//}
	//else {
	//	pWin = &player2_;
	//	pLose = &player1_;
	//}

	////the wining player chooses 1 and gets other random
	////por ahora tiene las dos random, habr�a usar el estado de selecci�n de habilidades aqu�
	//pWin->abilities.push_back((AbilityID)app_->getRandGen()->nextInt(level1_flag, max_level_flag));
	//pWin->abilities.push_back((AbilityID)app_->getRandGen()->nextInt(level1_flag, max_level_flag));
	////the losing player, gets random lvl sth 
	//pLose->abilities.push_back((AbilityID)app_->getRandGen()->nextInt(level1_flag, max_level_flag));
	//pLose->abilities.push_back((AbilityID)app_->getRandGen()->nextInt(level1_flag, max_level_flag));

	//GameManager::AbilityID


	//generate abilities
	//vector<GameManager::AbilityID> hab;
	//player 1 abilities
	GameManager::AbilityID abi1 = (GameManager::AbilityID)app_->getRandGen()->nextInt(GameManager::level1_flag, GameManager::max_level_flag);
	//El jugador que gana obtiene 3 habilidades aleatorias, 2 de ellas las tiene que elegir, la otra es aleatoria
	Entity* nav_j1 = entManager_.addEntity();
	//NavigationController* ctrl = nav_j1->addComponent<NavigationController>(2, 2, app_->getGameManager()->getPlayerInfo(1).hid);

	for (int i = 0; i < 3; i++) {
		do {
			//nueva habilidad
			abi1 = (GameManager::AbilityID)app_->getRandGen()->nextInt(GameManager::level1_flag, GameManager::max_level_flag);
		} while (checkAbility(abi1, winner_));//comprobamos que es adecuada
		AssetsManager::TextureNames abrand = (AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + abi1 + 1);
		Entity* ab1 = entManager_.addEntity();
		if (i < 2) {
			ab1->addComponent<UIElement>();
			ab1->addComponent<UITransform>(
				Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
				Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
				Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
				Vector2D(128, 128));
			ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
			//ctrl->SetElementInPos((ab1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			//						esto aqui no
			//			app_->getGameManager()->addHability(abi1, winner_);

		}
		else {
			ab1->addComponent<UIElement>();
			ab1->addComponent<UITransform>(
				Vector2D(((128) + (i - 2) * (128)) + 40, (72) * 6.7),
				Vector2D(((128) + (i - 2) * (128)) + 40, (72) * 6.7),
				Vector2D(((128) + (i - 2) * (128)) + 40, (72) * 6.7),
				Vector2D(128, 128));
			ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
			app_->getGameManager()->addHability(abi1, winner_);

			//ctrl->SetElementInPos((ab1)->getComponent<UIElement>(ecs::UIElement), i - 2, 1);
		}
	}
	//El jugador que pierde obtiene 2 habilidades aleatorias y no elige
	for (int i = 0; i < 2; i++) {
		do {
			//nueva habilidad
			abi1 = (GameManager::AbilityID)app_->getRandGen()->nextInt(GameManager::level1_flag, GameManager::max_level_flag);
		} while (checkAbility(abi1, loser));//comprobamos que es adecuada
		AssetsManager::TextureNames abrand = (AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + abi1 + 1);
		Entity* ab1 = entManager_.addEntity();
		ab1->addComponent<UIElement>();
		ab1->addComponent<UITransform>(
			Vector2D((800 ) + 40,  500 + 200 * i),
			Vector2D(((128) + (i) * (256)) + 40, (72) * 4.7 ),
			Vector2D(((128) + (i) * (256)) + 40, (72) * 4.7 ),
			Vector2D(128, 128));
		ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
		app_->getGameManager()->addHability(abi1, loser);

	}

	//hab.push_back(abi2);


	


	////entities
	//Entity* b = entManager_.addEntity();
	//b->addComponent<UITransform>(Vector2D(), Vector2D(), Vector2D(), Vector2D(app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h));
	//b->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::BackgroundFight));

	////j1 fondo submenu
	//UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
	//	Vector2D(0, 0), Vector2D(50, 50), Vector2D(0, 0), (app_->getWindowManager()->getCurResolution().w / 2)-100, app_->getWindowManager()->getCurResolution().h-100, 0);
	////j2 fondo submenu
	//UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
	//	Vector2D(0, 0),
	//	Vector2D(app_->getWindowManager()->getCurResolution().w-430, 50),
	//	Vector2D(430+50,0),
	//	(app_->getWindowManager()->getCurResolution().w / 2)-100, (app_->getWindowManager()->getCurResolution().h)-100, 0);
	//

	//// Texto central
	//Entity* text_ = entManager_.addEntity();
	////Vector2D pos, Vector2D anchor, Vector2D pivot, Vector2D size
	//text_->addComponent<UITransform>(Vector2D(0, 0), Vector2D((app_->getWindowManager()->getCurResolution().w) / 2, 0), 
	//	Vector2D((app_->getWindowManager()->getCurResolution().w /2), 0), 
	//	Vector2D(app_->getWindowManager()->getCurResolution().w - 50, 104));
	//text_->addComponent<TextComponent>("Elige tu habilidad", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 80, TextComponent::TextAlignment::Center);

	////boton
	//tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//	Vector2D(0, -190),
	//	Vector2D((app_->getWindowManager()->getCurResolution().w /4)*3, app_->getWindowManager()->getCurResolution().h),
	//	Vector2D(320, 90),
	//	640, 180, 0, GoToNextSubMenu, nullptr, "Continue_J2", 80, TextComponent::TextAlignment::Center);
	//std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Bottom;

	////j2
	//tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//	Vector2D(0, -190),
	//	Vector2D(app_->getWindowManager()->getCurResolution().w / 4, app_->getWindowManager()->getCurResolution().h),
	//	Vector2D(320,90), 
	//	640, 180, 0, GoToNextSubMenu, nullptr, "Continue_J1", 80, TextComponent::TextAlignment::Center);
	//std::get<1>(boton2)->getComponent<UITransform>(ecs::Transform)->Bottom;
	//
	//if (win1) {
	//	// Fija ganador

	//	tuple<Entity*, Entity*> hf_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Vampiric_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0,-100),
	//		Vector2D((app_->getWindowManager()->getCurResolution().w / 4), (app_->getWindowManager()->getCurResolution().h / 2)),
	//		Vector2D(80,80),
	//		(160), (160), 0, nullptr, nullptr, "fijawin", 0, TextComponent::TextAlignment::Center);

	//	// fija perdedor
	//	tuple<Entity*, Entity*> hop_lose = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::M_Grip_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0, -100),
	//		Vector2D(((app_->getWindowManager()->getCurResolution().w / 4) * 3), (app_->getWindowManager()->getCurResolution().h / 2)),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "fijalose", 0, TextComponent::TextAlignment::Center);

	//	// Opcionales ganador

	//	tuple<Entity*, Entity*> hop_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::HailBall_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0, 0),
	//		Vector2D((app_->getWindowManager()->getCurResolution().w / 4)-200, (app_->getWindowManager()->getCurResolution().h / 2)-300),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "opwin", 0, TextComponent::TextAlignment::Center);
	//
	//	tuple<Entity*, Entity*> hop_win2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Acid_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0, 0),
	//		Vector2D((app_->getWindowManager()->getCurResolution().w / 4) + 200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "opwin2", 0, TextComponent::TextAlignment::Center);

	//	//opcional perdedor

	//	tuple<Entity*, Entity*> hf_lose = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0, 0),
	//		Vector2D(((app_->getWindowManager()->getCurResolution().w / 4)*3), (app_->getWindowManager()->getCurResolution().h / 2)-300),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "oplose", 0, TextComponent::TextAlignment::Center);
	//
	//
	////nav1

	////winner
	//Entity* nav_win = entManager_.addEntity();
	//NavigationController* ctrl = nav_win->addComponent<NavigationController>(2, 3, app_->getGameManager()->getPlayerInfo(1).hid);
	//ctrl->SetElementInPos(std::get<0>(hop_win)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	//ctrl->SetElementInPos(std::get<0>(hop_win2)->getComponent<UIElement>(ecs::UIElement), 1, 0);
	//
	//ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	//ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 1, 1);
	//
	//ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	//ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 1, 2);

	////loser
	//Entity* nav_loser = entManager_.addEntity();
	//NavigationController* ctrl_ = nav_loser->addComponent<NavigationController>(1, 3, app_->getGameManager()->getPlayerInfo(2).hid);
	//ctrl_->SetElementInPos(std::get<0>(hf_lose)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	//ctrl_->SetElementInPos(std::get<0>(hop_lose)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	//ctrl_->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	//
	//}
	//else
	//{
	//	
	//	//gana player 2

	//	   // Fija ganador j2
	//	tuple<Entity*, Entity*> hf_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::HailBall_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0, -100),
	//		Vector2D(((app_->getWindowManager()->getCurResolution().w / 4) * 3), (app_->getWindowManager()->getCurResolution().h / 2)),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);
	//	
	//	// Fija perdedor j1
	//	tuple<Entity*, Entity*> hf_lose = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Acid_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0, -100),
	//		Vector2D((app_->getWindowManager()->getCurResolution().w / 4), (app_->getWindowManager()->getCurResolution().h / 2)),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

	//	// Opcionales ganador j2
	//	tuple<Entity*, Entity*> hop_win = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Dash_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0,0),
	//		Vector2D(((app_->getWindowManager()->getCurResolution().w / 4) * 3)-200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

	//	tuple<Entity*, Entity*> hop_win2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Mina_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0,0),
	//		Vector2D(((app_->getWindowManager()->getCurResolution().w / 4) * 3)+200, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

	//	// Opcionales perdedor j1
	//	tuple<Entity*, Entity*> hop_lose = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Ex_Will_ico), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
	//		Vector2D(0, 0),
	//		Vector2D(((app_->getWindowManager()->getCurResolution().w / 4)), (app_->getWindowManager()->getCurResolution().h / 2) - 300),
	//		Vector2D(80, 80),
	//		(160), (160), 0, nullptr, nullptr, "", 0, TextComponent::TextAlignment::Center);

	//	//winner
	//	Entity* nav_win = entManager_.addEntity();
	//	NavigationController* ctrl = nav_win->addComponent<NavigationController>(2, 3, app_->getGameManager()->getPlayerInfo(2).hid);
	//	ctrl->SetElementInPos(std::get<0>(hop_win)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	//	ctrl->SetElementInPos(std::get<0>(hop_win2)->getComponent<UIElement>(ecs::UIElement), 1, 0);
	//	ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	//	ctrl->SetElementInPos(std::get<0>(hf_win)->getComponent<UIElement>(ecs::UIElement), 1, 1);
	//	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	//	ctrl->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), 1, 2);

	//	//loser
	//	Entity* nav_loser = entManager_.addEntity();
	//	NavigationController* ctrl_ = nav_loser->addComponent<NavigationController>(1, 3, app_->getGameManager()->getPlayerInfo(1).hid);
	//	ctrl_->SetElementInPos(std::get<0>(hop_lose)->getComponent<UIElement>(ecs::UIElement), 0, 0);
	//	ctrl_->SetElementInPos(std::get<0>(hf_lose)->getComponent<UIElement>(ecs::UIElement), 0, 1);
	//	ctrl_->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), 0, 2);
	//	
	//}


}

void SkillSelection::GoToNextSubMenu(App* app)
{
	app->getStateMachine()->pushState(new InventorySelection(app));
}

void SkillSelection::Pressed1(App* app)
{
}

void SkillSelection::Pressed2(App* app)
{
}

//introduce la habilidad en el vector de habilidades generadas segun el jugador
//y sus habilidades ya disponibles
bool SkillSelection::checkAbility(GameManager::AbilityID newAb, int player) {

	std::vector<GameManager::AbilityID> aux = app_->getGameManager()->getPlayerInfo(player).abilities;
	if (player == 0) {	//player1
		//player1 generated abilities
		for (int i = 0; i < generatedAbs_1.size(); i++) {
			if (newAb == generatedAbs_1[i])
				return true;
		}

		//player1 abilities
		for (int i = 0; i < aux.size(); i++) {
			if (newAb == aux[i])
				return true;
		}
		generatedAbs_1.push_back(newAb);
		return false;
	}
	else {
		for (int i = 0; i < generatedAbs_2.size(); i++) {
			if (newAb == generatedAbs_2[i])
				return true;
		}

		//player2 abilities
		for (int i = 0; i < aux.size(); i++) {
			if (newAb == aux[i])
				return true;
		}	
		generatedAbs_2.push_back(newAb);
		return false;
	}
	
}