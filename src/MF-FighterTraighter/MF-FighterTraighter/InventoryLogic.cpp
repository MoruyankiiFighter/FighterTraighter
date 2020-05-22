#include "InventoryLogic.h"
#include "Entity.h"
#include "UITransform.h"
InventoryLogic::InventoryLogic(NavigationController* nav, int player, RenderImage* left, RenderImage* right):
	Component(ecs::InventoryLogic), nav_(nav), player_(player), left_(left), right_(right)
{
}

void InventoryLogic::init()
{
	pressed = false;
	ent = new Entity();
	ent->addComponent<Transform>(Vector2D(), Vector2D(), 100, 100, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::SelectionSquare));

}

void InventoryLogic::update()
{
	if (!pressed) {
		if (nav_->GetPosY() == 0) {
			if (app_->getGameManager()->getPlayerInfo(player_).abilities.size() > nav_->GetPosX()) { //revisar esta comprobacion
				curr = app_->getGameManager()->getPlayerInfo(player_).abilities[nav_->GetPosX()]; //0 a 5
			}
		}
		else if (nav_->GetPosY() == 1) {

			if (app_->getGameManager()->getPlayerInfo(player_).abilities.size() > 5+ nav_->GetPosX()) {//revisar esta comprobacion
				curr = app_->getGameManager()->getPlayerInfo(player_).abilities[(nav_->GetPosX() + 5)]; //5 a 10
			}
		}

		ent->getComponent<Transform>(ecs::Transform)->setPosition
		(nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())->getEntity()->getComponent<UITransform>(ecs::Transform)->getPosition());
		cout << ent->getComponent<Transform>(ecs::Transform)->getPosition().getX()<<endl;
	}
}

void InventoryLogic::render()
{
	if (!pressed&& nav_->GetPosY()<2) {
		ent->render();
	}
}

void InventoryLogic::handleInput()
{
	if (nav_->GetPosY() != 2) {
		if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::LeftBumper) && app_->getGameManager()->getPlayerInfo(player_).ability2Index != curr && !pressed) {
			app_->getGameManager()->setFirstHab(curr, player_);

			cout << "hab1 equipada ";
			if (left_ != nullptr) {
				switch (curr)
				{
				case GameManager::MegatonGrip:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::M_Grip_ico));
					break;

				case GameManager::SeismicShock:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::S_Sock_ico));
					break;

				case GameManager::ExplosiveWillpower:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Ex_Will_ico));
					break;

				case GameManager::AcidSplit:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Acid_ico));
					break;

				case GameManager::Mina:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Mina_ico));
					break;

				case GameManager::ShrugOff:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::ShrugOff_ico));
					break;

				case GameManager::MorePower:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::MorePower_ico));
					break;
				case GameManager::Hookshot:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Hook_ico));
					break;
				case GameManager::Dash:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Dash_ico));
					break;
				case GameManager::VampiricStrike:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Vampiric_ico));
					break;
				case GameManager::HailBall:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::HailBall_ico));
					break;
				case GameManager::ReachingStrike:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Reach_ico));
					break;
				case GameManager::FlyingKicks:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::FlyingKicks_ico));
					break;
				case GameManager::LaserLineal:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::L_Lineal_ico));
					break;
				case GameManager::NadoKick:
					left_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Nado_ico));
					break;
				}
			}
		}
		if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightBumper) && app_->getGameManager()->getPlayerInfo(player_).ability1Index != curr && !pressed) {
			app_->getGameManager()->setSecondHab(curr, player_);
			cout << "hab2 equipada ";
			if (right_ != nullptr) {
				switch (curr)
				{
				case GameManager::MegatonGrip:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::M_Grip_ico));
					break;

				case GameManager::SeismicShock:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::S_Sock_ico));
					break;

				case GameManager::ExplosiveWillpower:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Ex_Will_ico));
					break;

				case GameManager::AcidSplit:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Acid_ico));
					break;

				case GameManager::Mina:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Mina_ico));
					break;

				case GameManager::ShrugOff:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::ShrugOff_ico));
					break;

				case GameManager::MorePower:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::MorePower_ico));
					break;
				case GameManager::Hookshot:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Hook_ico));
					break;
				case GameManager::Dash:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Dash_ico));
					break;
				case GameManager::VampiricStrike:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Vampiric_ico));
					break;
				case GameManager::HailBall:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::HailBall_ico));
					break;
				case GameManager::ReachingStrike:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Reach_ico));
					break;
				case GameManager::FlyingKicks:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::FlyingKicks_ico));
					break;
				case GameManager::LaserLineal:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::L_Lineal_ico));
					break;
				case GameManager::NadoKick:
					right_->setTexture(app_->getAssetsManager()->getTexture(AssetsManager::Nado_ico));
					break;
				}
			}
		}
	}
	else 
	{
		if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Down) && !pressed) {
			pressed = true;
			cout << "waiting for fight";
		}
		
		else if (pressed && app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Right)) {
			pressed = false;
			cout << "Canceled";
		}
	}
}
