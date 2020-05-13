#include "CharacterSelectionHandler.h"
#include "Entity.h"
#include "UITransform.h"
#include "Fight.h"

void CharacterSelectionHandler::update()
{
	j1_ = log1->getComponent<CharacterSelectionLogic>(ecs::CharacterSelectionLogic)->getChosen();
	j2_ = log2->getComponent<CharacterSelectionLogic>(ecs::CharacterSelectionLogic)->getChosen();

	if (j1_ && j2_) {
		cout<<"A pegarse de ostias";
	}

	
}

void CharacterSelectionHandler::handleInput()
{

}
