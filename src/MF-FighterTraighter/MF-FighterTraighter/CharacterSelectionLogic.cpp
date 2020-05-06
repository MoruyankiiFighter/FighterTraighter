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
		image_->setTexture(aisha_texture);
	
	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==flor_) {
		desc_->setText(flor_desc_);
		image_->setTexture(flor_texture);

	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==mkwhoop_) {
		desc_->setText(mkwhoop_desc_);
		image_->setTexture(mkwhoop_texture);

	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==mock_) {
		desc_->setText(mock_desc_);
		image_->setTexture(mock_texture);

	}
	
}
