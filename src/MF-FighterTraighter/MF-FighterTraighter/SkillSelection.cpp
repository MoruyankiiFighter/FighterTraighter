#include "SkillSelection.h"
#include "UIFactory.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
#include "Fight.h"
#include "NavigationController.h"
#include "InventorySelection.h"
#include "SkillSelectionLogic.h"
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
	

	////j1 fondo submenu
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
		Vector2D(0, 0), 
		Vector2D(50, 50), 
		Vector2D(0, 0), 
		(app_->getWindowManager()->getCurResolution().w / 2)-100, app_->getWindowManager()->getCurResolution().h-100, 0);
	
	////j2 fondo submenu
	UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
		Vector2D(0, 0),
		Vector2D(app_->getWindowManager()->getCurResolution().w-430, 50),
		Vector2D(430+50,0),
		(app_->getWindowManager()->getCurResolution().w / 2)-100, (app_->getWindowManager()->getCurResolution().h)-100, 0);
	



	GameManager::AbilityID abi1 = (GameManager::AbilityID)app_->getRandGen()->nextInt(GameManager::level1_flag, GameManager::max_level_flag);
	//El jugador que gana obtiene 3 habilidades aleatorias, 2 de ellas las tiene que elegir, la otra es aleatoria
	Entity* nav_j1 = entManager_.addEntity();
	NavigationController* nav = nav_j1->addComponent<NavigationController>(2, 1, app_->getGameManager()->getPlayerInfo(winner_).hid);

	for (int i = 0; i < 3; i++) {
		do {
			//nueva habilidad
			abi1 = (GameManager::AbilityID)app_->getRandGen()->nextInt(GameManager::level1_flag, GameManager::max_level_flag);
		} while (checkAbility(abi1, winner_));

		AssetsManager::TextureNames abrand = (AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + abi1 + 1);
		

		Entity* ab1 = entManager_.addEntity();
		ab1->addComponent<UIElement>();
		//pos,ancla,pivot, tamano
		if (winner_ == 1) {
			if (i < 2) {
				ab1->addComponent<UITransform>(
					Vector2D(0, 0),
					Vector2D((i * 300)+300, (app_->getWindowManager()->getCurResolution().h / 2) - 300),
					Vector2D(80, 80),
					Vector2D(160, 160));

				ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
				nav->SetElementInPos((ab1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			}
			else {
				ab1->addComponent<UITransform>(
					Vector2D(0, 0),
					Vector2D(app_->getWindowManager()->getCurResolution().w / 4, (app_->getWindowManager()->getCurResolution().h / 2)),
					Vector2D(80, 80),
					Vector2D(160, 160));

				ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
				//nav->SetElementInPos((ab1)->getComponent<UIElement>(ecs::UIElement), i-1, 1);
				app_->getGameManager()->addHability(abi1, winner_);
			}
		}
		else {
			if (i < 2) {
				ab1->addComponent<UITransform>(
					Vector2D(50,0),
					Vector2D((app_->getWindowManager()->getCurResolution().w/2)+(i*300)+300, (app_->getWindowManager()->getCurResolution().h / 2)-300),
					Vector2D(80, 80),
					Vector2D(160, 160));

				ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
				nav->SetElementInPos((ab1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			}
			else {
				ab1->addComponent<UITransform>(
					Vector2D(0,0),
					Vector2D((app_->getWindowManager()->getCurResolution().w / 4)*3, (app_->getWindowManager()->getCurResolution().h / 2)),
					Vector2D(80, 80),
					Vector2D(160, 160));

				ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
				//nav->SetElementInPos((ab1)->getComponent<UIElement>(ecs::UIElement), i-1, 1);
				app_->getGameManager()->addHability(abi1, winner_);
			}
		}
	}
	Entity* text = UIFactory::createText(app_, this, 
		Vector2D(0, 0),
		Vector2D((app_->getWindowManager()->getCurResolution().w / 2), app_->getWindowManager()->getCurResolution().h - 200),
		Vector2D(320, 90),
		app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), ("Player " + to_string(winner_) + " chooses!"),
		60, TextComponent::Center, 300, 100, 500);

	Entity* log = entManager_.addEntity();

	if (winner_ == 1) {
		log->addComponent<SkillSelectionLogic>(nav, winner_, generatedAbs_1);
	}
	else {
		log->addComponent<SkillSelectionLogic>(nav, winner_, generatedAbs_2);

	}
	
	//Entity* nav_j2 = entManager_.addEntity();
	//NavigationController* nav2 = nav_j2->addComponent<NavigationController>(1, 3, app_->getGameManager()->getPlayerInfo(loser).hid);
	//El jugador que pierde obtiene 2 habilidades aleatorias y no elige
	for (int i = 0; i < 2; i++) {
		do {
			//nueva habilidad
			abi1 = (GameManager::AbilityID)app_->getRandGen()->nextInt(GameManager::level1_flag, GameManager::max_level_flag);
		} while (checkAbility(abi1, loser));//comprobamos que es adecuada
		AssetsManager::TextureNames abrand = (AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + abi1 + 1);
		Entity* ab1 = entManager_.addEntity();
		if (winner_ == 1) {
			
			ab1->addComponent<UIElement>();
			ab1->addComponent<UITransform>(
				Vector2D(0, 0),
				Vector2D((app_->getWindowManager()->getCurResolution().w / 4) * 3, (app_->getWindowManager()->getCurResolution().h / 2)+(300*(i-1))),
				Vector2D(80, 80),
				Vector2D(160, 160));
			ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
			app_->getGameManager()->addHability(abi1, loser);
			//nav2->SetElementInPos((ab1)->getComponent<UIElement>(ecs::UIElement), 0, i);
		}
		else {
			ab1->addComponent<UIElement>();
			ab1->addComponent<UITransform>(
				Vector2D(0, 0),
				Vector2D((app_->getWindowManager()->getCurResolution().w / 4), (app_->getWindowManager()->getCurResolution().h / 2) + (300 * (i - 1))),
				Vector2D(80, 80),
				Vector2D(160, 160));
			ab1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(abrand));
			app_->getGameManager()->addHability(abi1, loser);
			//nav2->SetElementInPos((ab1)->getComponent<UIElement>(ecs::UIElement), 0, i);
		}

	}


}

void SkillSelection::GoToNextSubMenu(App* app)
{
	//app->getGameManager()->addHability(op_, winner);
	//app->getStateMachine()->popState();
	//no esta del todo bien
	//app->getStateMachine()->pushState(new InventorySelection(app));
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
	if (player == 1) {	//player1
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

void SkillSelection::handleInput() {	
	if (app_->getInputManager()->pressedStart()) {
		app_->getGameManager()->pressedStart();
	}
	else
		GameState::handleInput();
}