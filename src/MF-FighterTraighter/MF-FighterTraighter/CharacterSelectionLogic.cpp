#include "CharacterSelectionLogic.h"

CharacterSelectionLogic::~CharacterSelectionLogic()
{

}

void CharacterSelectionLogic::init()
{
	desc_->setText("");
	curNavX = nav_->GetPosX();
	curNavY = nav_->GetPosY();
}

void CharacterSelectionLogic::update()
{
	SetElements();
}

void CharacterSelectionLogic::SetElements()
{
	// If nothing changed, don't do anything
	if (curNavX == nav_->GetPosX() && curNavY == nav_->GetPosY()) return; 

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
		app_->getGameManager()->setCharacter(app_->getGameManager()->F10R, playerNumber_);
	}
	else if (e == mkwhoop_) {
		desc_->setText(mkwhoop_desc_);
		image_->setTexture(mkwhoop_texture);
		app_->getGameManager()->setCharacter(app_->getGameManager()->MKWh00p, playerNumber_);
	}
	else if (e == mock_) {
		desc_->setText(mock_desc_);
		image_->setTexture(mock_texture);
		app_->getGameManager()->setCharacter(app_->getGameManager()->Mockingbird, playerNumber_);
	}
	else if (e == random_) {
		// TODO: select a random character, and present the random splash art and description
		// the selection will be done when the game is started
		int n = 3;

		//generate a random
		desc_->setText(" ");
		image_->setTexture(random_texture); //add random texture

		switch (n) {
		case 0:
			n = 1;
			//another random cause it's Aisha case 
			break;
		case 1:
			app_->getGameManager()->setCharacter(app_->getGameManager()->F10R, n);
			break;
		case 2:
			app_->getGameManager()->setCharacter(app_->getGameManager()->MKWh00p, n);
			break;
		case 3:
			app_->getGameManager()->setCharacter(app_->getGameManager()->Mockingbird, n);
			break;
		}
	}

	curNavX = nav_->GetPosX();
	curNavY = nav_->GetPosY();
}
