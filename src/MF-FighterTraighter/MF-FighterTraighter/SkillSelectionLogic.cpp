#include "SkillSelectionLogic.h"

SkillSelectionLogic::SkillSelectionLogic(NavigationController* nav, int player, const vector<GameManager::AbilityID>& v):Component(ecs::OptionsLogic), nav_(nav), player_(player)
{
}

SkillSelectionLogic::~SkillSelectionLogic()
{
}

void SkillSelectionLogic::init()
{
	
}

void SkillSelectionLogic::update()
{
	
}

void SkillSelectionLogic::render()
{
}

void SkillSelectionLogic::handleInput()
{
	if (app_->getGameManager()->getPlayerInfo(player_).hid->ButtonPressed(HID::RightPad_Down)) {
		
		if (nav_->GetPosY() == 0) {
			curr = v_[nav_->GetPosX()];
			op = curr;
		}
		else if (nav_->GetPosY() == 1) {
			curr = v_[nav_->GetPosY() + 1];
		}


		app_->getGameManager()->addHability(curr, player_);

	}
}
