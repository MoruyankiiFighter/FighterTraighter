#include "CharacterSelectionHandler.h"
#include "Entity.h"
#include "UITransform.h"
#include "Fight.h"

void CharacterSelectionHandler::init()
{
	
}

void CharacterSelectionHandler::update()
{
	j1_ = log1->getComponent<CharacterSelectionLogic>(ecs::CharacterSelectionLogic)->getChosen();
	j2_ = log2->getComponent<CharacterSelectionLogic>(ecs::CharacterSelectionLogic)->getChosen();
}

void CharacterSelectionHandler::handleInput()
{
	if (j1_ && j2_) {
	#if  DEBUG
		cout << "a darse de ostias"<<endl;

	#endif //  DEBUG

		app_->getStateMachine()->pushState(new Fight(app_));
	}
}


