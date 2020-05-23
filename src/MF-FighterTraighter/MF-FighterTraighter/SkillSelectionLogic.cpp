#include "SkillSelectionLogic.h"
#include "Entity.h"
#include "RenderImage.h"
#include "UITransform.h"
SkillSelectionLogic::SkillSelectionLogic(NavigationController* nav, int player, vector<GameManager::AbilityID> v):Component(ecs::OptionsLogic), nav_(nav), player_(player), v_(v)
{

}

SkillSelectionLogic::~SkillSelectionLogic()
{
	delete ent;
}

void SkillSelectionLogic::init()
{
	pressed = false;
	op = v_[0];
	ent = new Entity();
	ent->addComponent<Transform>(Vector2D(), Vector2D(), 170, 170, 0);
	ent->addComponent<RenderImage>(app_->getAssetsManager()->getTexture(AssetsManager::SelectionSquare));
}

void SkillSelectionLogic::update()
{
	if (!pressed) {
		if (nav_->GetPosY() == 0) {
			if (v_.size() > nav_->GetPosX()) { //revisar esta comprobacion
				curr = v_[nav_->GetPosX()]; //0 a 2
			} 
		}
		//}
		//else if (nav_->GetPosY() == 1) {

		//	if (v_.size() > 1 + nav_->GetPosX()) {//revisar esta comprobacion
		//		curr = v_[(nav_->GetPosY() + 1)]; //2
		//	}
		//}

		ent->getComponent<Transform>(ecs::Transform)->setPosition
		(nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())->getEntity()->getComponent<UITransform>(ecs::Transform)->getPosition());
		//cout << ent->getComponent<Transform>(ecs::Transform)->getPosition().getX()<<endl;
	}
}

void SkillSelectionLogic::render()
{
	if (!pressed) {
		ent->render();
	}
}

void SkillSelectionLogic::handleInput()
{
	if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Down)) {
		// estamos en la fila 0 y escogemos la habilidad opcional
		if (nav_->GetPosY() == 0) {
			op = v_[nav_->GetPosX()];
		}

		//app_->getGameManager()->addHability(curr, player_);

	}
	if (nav_->GetPosY() == 2 && app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Down) && !pressed) {
		pressed = true;
		cout << "waiting for fight";
	}

	else if (pressed && app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Right)) {
		pressed = false;
		cout << "Canceled";
	}
}
