#include "CharacterSelectionLogic.h"

void CharacterSelectionLogic::init()
{
	desc_->setText("");
}

void CharacterSelectionLogic::update()
{
	SetElements();
}

void CharacterSelectionLogic::SetElements()
{
	if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==aisha_) {
		desc_->setText(aisha_desc_);
	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==flor_) {
		desc_->setText(flor_desc_);
	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==mkwhoop_) {
		desc_->setText(mkwhoop_desc_);
	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==mock_) {
		desc_->setText(mock_desc_);
	}
	
}
