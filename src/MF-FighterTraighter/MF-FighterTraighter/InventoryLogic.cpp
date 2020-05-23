#include "InventoryLogic.h"
#include "Entity.h"
#include "UITransform.h"
InventoryLogic::InventoryLogic(NavigationController* nav, int player, RenderImage* left, RenderImage* right):
	Component(ecs::InventoryLogic), nav_(nav), player_(player), left_(left), right_(right)
{
}

//Por defecto las dos primeras habilidades escogidas
void InventoryLogic::init()
{
	pressed = false;
	abs_size = app_->getGameManager()->getPlayerInfo(player_).abilities.size();
	ab1_index = 0;
	ab2_index = 1;
	app_->getGameManager()->setFirstHab(ab1_index, player_);
	app_->getGameManager()->setSecondHab(ab2_index, player_);
	left_->setTexture(app_->getAssetsManager()->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(player_).abilities[ab1_index] + 1)));
	right_->setTexture(app_->getAssetsManager()->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(player_).abilities[ab2_index] + 1)));
	ent = new Entity();
	ent->addComponent<Transform>(Vector2D(), Vector2D(), 150, 150, 45);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::SelectionSquare));

}

void InventoryLogic::update()
{
	if (!pressed) {
		//if (nav_->GetPosY() == 0) {
		//	if (app_->getGameManager()->getPlayerInfo(player_).abilities.size() > nav_->GetPosX()) { //revisar esta comprobacion
		//		curr = app_->getGameManager()->getPlayerInfo(player_).abilities[nav_->GetPosX()]; //0 a 5
		//	}
		//}
		//else if (nav_->GetPosY() == 1) {

		//	if (app_->getGameManager()->getPlayerInfo(player_).abilities.size() > 5+ nav_->GetPosX()) {//revisar esta comprobacion
		//		curr = app_->getGameManager()->getPlayerInfo(player_).abilities[(nav_->GetPosX() + 5)]; //5 a 10
		//	}
		//}

		ent->getComponent<Transform>(ecs::Transform)->setPosition
		(nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())->getEntity()->getComponent<UITransform>(ecs::Transform)->getPosition());
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
	/*ab1_index = app_->getGameManager()->getPlayerInfo(player_).ability1Index;
	ab2_index = app_->getGameManager()->getPlayerInfo(player_).ability2Index;*/
	int posY = nav_->GetPosY();
	if ( posY != 2) {//leftBumper
		if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::LeftBumper) && !pressed) {
			int indX = nav_->GetPosX();
			//app_->getGameManager()->setFirstHab(curr, player_);
			if (posY > 0) {
				indX += 5;
			}
			//cout << "Hab " << indX << endl;
			if (indX < abs_size) {
				if (indX == ab2_index) {
					swapIndex();
				}
				else {
					ab1_index = indX;
					left_->setTexture(app_->getAssetsManager()->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(player_).abilities[ab1_index] + 1)));
				}
				app_->getGameManager()->setFirstHab(ab1_index, player_);
			}
		}
		if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightBumper) && !pressed) {
			int indX = nav_->GetPosX();
			if (posY > 0) {
				indX += 5;
			}
			
			if ( indX < abs_size) {
				if (indX == ab1_index)
					swapIndex();
				else {
					ab2_index = indX;
					right_->setTexture(app_->getAssetsManager()->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(player_).abilities[ab2_index] + 1)));
				}
				app_->getGameManager()->setSecondHab(ab2_index, player_);

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


void InventoryLogic::swapIndex() {
	int aux = ab1_index;
	ab1_index = ab2_index;
	ab2_index = aux;
	//actualizar texturas
	left_->setTexture(app_->getAssetsManager()->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(player_).abilities[ab1_index] + 1)));
	right_->setTexture(app_->getAssetsManager()->getTexture((AssetsManager::TextureNames)(AssetsManager::_abilityIcon_start + app_->getGameManager()->getPlayerInfo(player_).abilities[ab2_index] + 1)));
}