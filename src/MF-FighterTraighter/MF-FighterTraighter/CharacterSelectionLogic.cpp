#include "CharacterSelectionLogic.h"

CharacterSelectionLogic::~CharacterSelectionLogic()
{

}

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
	UIElement* e = nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY());
	if (e == aisha_) {
		desc_->setText(aisha_desc_);
		image_->setTexture(aisha_texture);
		// Not implemented
		//app_->getGameManager()->setCharacter(app_->getGameManager()->Aisha, n);
	}
	else if (e == flor_) {
		desc_->setText(flor_desc_);
		image_->setTexture(flor_texture);
		app_->getGameManager()->setCharacter(app_->getGameManager()->F10R, n);
	}
	else if (e == mkwhoop_) {
		desc_->setText(mkwhoop_desc_);
		image_->setTexture(mkwhoop_texture);
		app_->getGameManager()->setCharacter(app_->getGameManager()->MKWh00p, n);
	}
	else if (e == mock_) {
		desc_->setText(mock_desc_);
		image_->setTexture(mock_texture);
		app_->getGameManager()->setCharacter(app_->getGameManager()->Mockingbird, n);
	}
	else if (e == random_) {
		// TODO: select a random character, and present the random splash art and description
		// the selection will be done when the game is started

		// for now,
		desc_->setText(mock_desc_);
		image_->setTexture(mock_texture);
		app_->getGameManager()->setCharacter(app_->getGameManager()->Mockingbird, n);
	}
}
