#include "PlayerAttacks.h"

PlayerAttacks::PlayerAttacks(AnimationChain* highFist, SDL_Scancode key1, AnimationChain* lowFist, SDL_Scancode key2,
	AnimationChain* highKick, SDL_Scancode key3, AnimationChain* lowKick, SDL_Scancode key4/*,
			 Hability* highKick, SDL_Scancode key5, Hability* lowKick, SDL_Scancode key6*/) : Component(ecs::PlayerAttacks)
{
	attacksList.push_back(highFist);
	attacksList.push_back(lowFist);
	attacksList.push_back(highKick);
	attacksList.push_back(lowKick);
	highFistKey = key1;
	lowFistKey = key2;
	highKickKey = key3;
	lowKickKey = key4;
	/*hability1Key = key5;
	hability2Key = key6;*/

}

PlayerAttacks::~PlayerAttacks() {
	cout << "destruyendo ataques "<<endl;
	//hay que descomentar cuando las animaciones sean diferentes
	//for (int i = 0; i < attacksList.size(); i++) {
		delete attacksList[1];
		attacksList[1] = nullptr;
	//}
	attacksList.clear();
	//delete activeAttack_;
	/*cout << "destruyendo habilidades "<<endl;
	for (int i = 0; i < habilityList.size(); i++) {
		delete habilityList[i];
		habilityList[i] = nullptr;
	}
	habilityList.clear();*/
}
void PlayerAttacks::update()
{
	if (activeAttack_ != nullptr) {
		if (activeAttack_->update()) {
			activeAttack_ = nullptr;
		}
	}
}

void PlayerAttacks::handleInput() {
	if (app_->getInputManager()->isKeyDown(highFistKey) && activeAttack_ == nullptr) {
		activeAttack_ = attacksList[0];
	}
	else if (app_->getInputManager()->isKeyDown(lowFistKey)) {
		activeAttack_ = attacksList[1];
	}
	else if (app_->getInputManager()->isKeyDown(highKickKey)) {
		activeAttack_ = attacksList[2];
	}
	else if (app_->getInputManager()->isKeyDown(lowKickKey)) {
		activeAttack_ = attacksList[3];
	}
	/*else if (app_->getInputManager()->isKeyDown(hability1Key)) {
		habilityList[0]->makeAttack();
	}
	else if (app_->getInputManager()->isKeyDown(hability2Key)) {
		habilityList[1]->makeAttack();
	}*/
}

/*
void Attacks::addFirstHability(Hability* hab) {
	if(!habilityList.empty())
		habilityList.pop_front();
	habilityList.push_front(hab);
}

void Attacks::addFirstHability(Hability* hab) {
	if (!habilityList.size==2)
		habilityList.pop_back(hab);
	habilityList.push_back(hab);
}
*/