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
		title_->setText("AISHA");
		desc_->setText(aisha_desc_);
		image_->setTexture(aisha_texture);
	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==flor_) {
		title_->setText("FLOR");
		desc_->setText(flor_desc_);
		image_->setTexture(flor_texture);

	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==mkwhoop_) {
		title_->setText("MKWHOOP");
		desc_->setText(mkwhoop_desc_);
		image_->setTexture(mkwhoop_texture);

	}
	else if (nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY())==mock_) {
		title_->setText("MOCKINGBIRD");
		desc_->setText(mock_desc_);
		image_->setTexture(mock_texture);

	}
	
}
