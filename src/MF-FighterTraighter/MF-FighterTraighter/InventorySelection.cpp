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
	
	
	

	// Texto central
	Entity* text_ = entManager_.addEntity();
	//Vector2D pos, Vector2D anchor, Vector2D pivot, Vector2D size
	text_->addComponent<UITransform>(Vector2D(0, 0), Vector2D((app_->getWindowManager()->getCurResolution().w/2 ), 0), Vector2D((app_->getWindowManager()->getCurResolution().w /2), 0), Vector2D((double)app_->getWindowManager()->getCurResolution().w - 50, ((double)app_->getWindowManager()->getCurResolution().h / 20) +50));
	text_->addComponent<TextComponent>("Prepare for the fight!", app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black), 80, TextComponent::TextAlignment::Center);

	//ranuras j1

	Entity* left_j1 = entManager_.addEntity();

	left_j1->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(1).hid);
	left_j1->addComponent<UITransform>(Vector2D((double)app_->getWindowManager()->getCurResolution().w / 4- 200, 200), Vector2D((app_->getWindowManager()->getCurResolution().w / 4),100), Vector2D((app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	left_j1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
	
	Entity* right_j1 = entManager_.addEntity();

	right_j1->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(1).hid);
	right_j1->addComponent<UITransform>(Vector2D((double)app_->getWindowManager()->getCurResolution().w / 4 + 100, 200), Vector2D((app_->getWindowManager()->getCurResolution().w / 4),100), Vector2D((app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
	right_j1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
	
	tuple <Entity*, Entity*> boton2 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
		Vector2D(0, -(90 + 50 + 50)),
		Vector2D(app_->getWindowManager()->getCurResolution().w / 4, app_->getWindowManager()->getCurResolution().h),
		Vector2D(320, 90),
		640, 180, 0, nullptr, nullptr, "Continue_J1", 80, TextComponent::TextAlignment::Center);
	std::get<1>(boton2)->getComponent<UITransform>(ecs::Transform)->Bottom;

	


	//in arcade, generate abilities here
	if (numPlayer_ == 1) {
		if (app_->getGameManager()->getPlayerRounds(1) < 5) {
			GameManager::AbilityID abi1 = (GameManager::AbilityID)app_->getRandGen()->nextInt(GameManager::level1_flag, GameManager::max_level_flag);
			//crear las dos habildiades y meterselas en el vector, solo si rounds es menor que 5
			for (int i = 0; i < 2; i++) {
				do {
					//new ability
					abi1 = (GameManager::AbilityID)app_->getRandGen()->nextInt(GameManager::level1_flag, GameManager::max_level_flag);
				} while (checkAbility(abi1));//check if it correct
				app_->getGameManager()->addHability(abi1, 1);

			}
		}
	}



	//hab j1
	Entity* nav_j1 = entManager_.addEntity();

	NavigationController* ctrl = nav_j1->addComponent<NavigationController>(5, 3, app_->getGameManager()->getPlayerInfo(1).hid);

	for (double i = 0; i < 10; i++) {

		
			Entity* habj1 = entManager_.addEntity();
		if (i < app_->getGameManager()->getPlayerInfo(1).abilities.size()) {
			//128
			if (i < 5) { 
				habj1->addComponent<UIElement>();
				habj1->addComponent<UITransform>(
					Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
					Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
					Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
					Vector2D(128, 128));
				habj1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
				ctrl->SetElementInPos((habj1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			}

			else {
				habj1->addComponent<UIElement>();
				habj1->addComponent<UITransform>(
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7), 
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
					Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
					Vector2D(128, 128));
				habj1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
				
				ctrl->SetElementInPos((habj1)->getComponent<UIElement>(ecs::UIElement), (i - 5), 1);
			}


			habj1->getComponent<RenderImage>(ecs::RenderImage)->setTexture(app_->getAssetsManager()
				->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(1).abilities[i] + 1)));

		}

		else {
			if (i < 5) {

			habj1->addComponent<UIElement>();
			habj1->addComponent<UITransform>(
				Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
				Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
				Vector2D(((128) + (i) * (128)) + 40, (72) * 4.7),
				Vector2D(128, 128));
			habj1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
			ctrl->SetElementInPos((habj1)->getComponent<UIElement>(ecs::UIElement), i, 0);
			}

			else {
			habj1->addComponent<UIElement>();
			habj1->addComponent<UITransform>(
				Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
				Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
				Vector2D(((128) + (i - 5) * (128)) + 40, (72) * 6.7),
				Vector2D(128, 128));
			habj1->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));

			ctrl->SetElementInPos((habj1)->getComponent<UIElement>(ecs::UIElement), (i - 5), 1);
			}

		}

	}
	

	for (int i = 0; i < 5; i++) {
		ctrl->SetElementInPos(std::get<0>(boton2)->getComponent<UIElement>(ecs::UIElement), i, 2);
	}

	// Navigation controller

	Entity* logicJ1 = entManager_.addEntity();
	logicJ1->addComponent<InventoryLogic>(ctrl, 1, left_j1->getComponent<RenderImage>(ecs::RenderImage), right_j1->getComponent<RenderImage>(ecs::RenderImage));


	if (numPlayer_ == 2) {
		//j2 fondo submenu
		UIFactory::createPanel(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Celda1),
			Vector2D(0, 0),
			Vector2D((double)app_->getWindowManager()->getCurResolution().w - 430, 50),
			Vector2D(430.0 + 50.0, 0),
			double(app_->getWindowManager()->getCurResolution().w / 2) - 100, double(app_->getWindowManager()->getCurResolution().h) - 100, 0);

		//boton
		tuple <Entity*, Entity*> boton1 = UIFactory::createButton(app_, this, app_->getAssetsManager()->getTexture(AssetsManager::Button), app_->getAssetsManager()->getFont(AssetsManager::Roboto_Black),
			Vector2D(0, -(90 + 50 + 50)),
			Vector2D(((double)app_->getWindowManager()->getCurResolution().w / 4) * 3, app_->getWindowManager()->getCurResolution().h),
			Vector2D(320, 90),
			640, 180, 0, nullptr, nullptr, "Continue_J2", 80, TextComponent::TextAlignment::Center);
		std::get<1>(boton1)->getComponent<UITransform>(ecs::Transform)->Bottom;

		//ranuras j2
		Entity* left_j2 = entManager_.addEntity();
		left_j2->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(2).hid);
		left_j2->addComponent<UITransform>(Vector2D(3 * (double)app_->getWindowManager()->getCurResolution().w / 4 - 200, 200), Vector2D((3 * (double)app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D((3 * (double)app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
		left_j2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));

		Entity* right_j2 = entManager_.addEntity();
		right_j2->addComponent<UIElement>(app_->getGameManager()->getPlayerInfo(2).hid);
		right_j2->addComponent<UITransform>(Vector2D(3 * (double)app_->getWindowManager()->getCurResolution().w / 4 + 100, 200), Vector2D((3 * (double)app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D((3 * (double)app_->getWindowManager()->getCurResolution().w / 4), 100), Vector2D(100, 100));
		right_j2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));

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
					habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
					ctrl_->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), i, 0);

				}
				else {

					habj2->addComponent<UIElement>();
					habj2->addComponent<UITransform>(
						Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
						Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
						Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
						Vector2D(128, 128));
					habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
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
					habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
					ctrl_->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), i, 0);

				}
				else {

					habj2->addComponent<UIElement>();
					habj2->addComponent<UITransform>(
						Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
						Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
						Vector2D(((128) + (i - 5) * (128)) + 1000, (72) * 6.7),
						Vector2D(128, 128));
					habj2->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::EmptyHability));
					ctrl_->SetElementInPos((habj2)->getComponent<UIElement>(ecs::UIElement), (i - 5), 1);
				}

			}
		}
		for (int i = 0; i < 5; i++) {

			ctrl_->SetElementInPos(std::get<0>(boton1)->getComponent<UIElement>(ecs::UIElement), i, 2);
		}

		Entity* logicJ2 = entManager_.addEntity();
		logicJ2->addComponent<InventoryLogic>(ctrl_, 2, left_j2->getComponent<RenderImage>(ecs::RenderImage), right_j2->getComponent<RenderImage>(ecs::RenderImage));

		Entity* ent = entManager_.addEntity();

		ent->addComponent<InventoryHandler>(logicJ1, logicJ2);
	}

	//playing arcade
	else {
		Entity* ent = entManager_.addEntity();
		ent->addComponent<InventoryHandler>(logicJ1, nullptr);
	}
}



void InventorySelection::handleInput()
{
	if (app_->getInputManager()->pressedStart()) {
		app_->getGameManager()->pressedStart();
	}
	else
		GameState::handleInput();

}

bool InventorySelection::checkAbility(GameManager::AbilityID newAb)
{
	
	//generated abilities here
	for (int i = 0; i < generatedAbs_1.size(); i++) {
		if (newAb == generatedAbs_1[i])
			return true;
	}
	std::vector<GameManager::AbilityID> aux = app_->getGameManager()->getPlayerInfo(1).abilities;
	//player1 abilities
	for (int i = 0; i < aux.size(); i++) {
		if (newAb == aux[i])
			return true;
	}
	generatedAbs_1.push_back(newAb);
	return false;
}
