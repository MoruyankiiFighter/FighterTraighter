#include "CharacterSelectionLogic.h"

::~CharacterSelectionLogic()
{

}

void CharacterSelectionLogic::init()
{
	desc_->setText("");
	curNavX = nav_->GetPosX();
	curNavY = nav_->GetPosY();
	SetElements();
	chose = false;

}

void CharacterSelectionLogic::update()
{
	// If nothing changed, don't do anything
	if (curNavX == nav_->GetPosX() && curNavY == nav_->GetPosY()) return;
	SetElements();

}

void CharacterSelectionLogic::handleInput()
{
	if (app_->getGameManager()->getPlayerInfo(playerNumber_).hid->ButtonPressed(HID::RightPad_Down)) {
		cout << "you chose character  " <<playerNumber_<< endl;
	
		chose = true;

		UIElement* e = nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY());
		if (e == aisha_) {
			
			// Not implemented
			//app_->getGameManager()->setCharacter(app_->getGameManager()->Aisha, n);
		}
		else if (e == flor_) {
		
			app_->getGameManager()->setCharacter(app_->getGameManager()->F10R, playerNumber_);
		}
		else if (e == mkwhoop_) {
		
			app_->getGameManager()->setCharacter(app_->getGameManager()->MKWh00p, playerNumber_);
		}
		else if (e == mock_) {
			app_->getGameManager()->setCharacter(app_->getGameManager()->Mockingbird, playerNumber_);
		}
		else if (e == random_) {
			
			int n = 3;
			//generate a random
			
			switch (n) {
			
			case 0:
				n = 1;
				//another random cause it's Aisha case 
				break;
			case 1:
				app_->getGameManager()->setCharacter(app_->getGameManager()->F10R, playerNumber_);
				break;
			case 2:
				app_->getGameManager()->setCharacter(app_->getGameManager()->MKWh00p, playerNumber_);
				break;
			case 3:
				app_->getGameManager()->setCharacter(app_->getGameManager()->Mockingbird, playerNumber_);
				break;
			}
		}

		curNavX = nav_->GetPosX();
		curNavY = nav_->GetPosY();
	}

	if (app_->getGameManager()->getPlayerInfo(playerNumber_).hid->ButtonPressed(HID::RightPad_Right)&& chose) {
		cout << "you quit your character";
		chose = false;
	}
}

void CharacterSelectionLogic::SetElements()
{

	UIElement* e = nav_->GetElementInPos(nav_->GetPosX(), nav_->GetPosY());
	if (e == aisha_) {
		desc_->setText(aisha_desc_);
		image_->setTexture(aisha_texture);
	}
	else if (e == flor_) {
		desc_->setText(flor_desc_);
		image_->setTexture(flor_texture);
	}
	else if (e == mkwhoop_) {
		desc_->setText(mkwhoop_desc_);
		image_->setTexture(mkwhoop_texture);

	}
	else if (e == mock_) {
		desc_->setText(mock_desc_);
		image_->setTexture(mock_texture);
	}
	else if (e == random_) {
		// TODO: select a random character, and present the random splash art and description
		// the selection will be done when the game is started
		int n = 3;

		//generate a random
		desc_->setText(" ");
		image_->setTexture(random_texture); //add random texture

	}

	curNavX = nav_->GetPosX();
	curNavY = nav_->GetPosY();
}
