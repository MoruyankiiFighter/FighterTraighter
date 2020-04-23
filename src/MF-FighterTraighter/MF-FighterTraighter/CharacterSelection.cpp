#include "CharacterSelection.h"

#include "Entity.h"

#include "RenderImage.h"
#include "Transform.h"
#include "Button.h"
#include "TextComponent.h"
#include "NavigationController.h"

#include "Font.h"
void CharacterSelection::init()
{
	// background

	Entity* background_ = entManager_.addEntity();
	background_->addComponent<Transform>(Vector2D(), Vector2D(), app_->getWindowManager()->getCurResolution().w, app_->getWindowManager()->getCurResolution().h,0);
	background_->addComponent<RenderImage>(); //añadir textura

	//panel


	//icons of the character

	//artwork of the character


	//Entitys


	Entity* navEnt = entManager_.addEntity();
	NavigationController* nav = navEnt->addComponent<NavigationController>(5, 2);

	//logic of that for changing the artwork of each player 
}
