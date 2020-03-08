#include "Attacks.h"

Attacks::Attacks(Attack* highFist, SDL_Scancode key1, Attack* lowFist, SDL_Scancode key2,
					Attack* highKick, SDL_Scancode key3, Attack* lowKick, SDL_Scancode key4/*,
			 Hability* highKick, SDL_Scancode key5, Hability* lowKick, SDL_Scancode key6*/) : Component(ecs::Attacks)
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

Attacks::~Attacks() {
	cout << "destruyendo ataques "<<endl;
	for (int i = 0; i < attacksList.size(); i++) {
		delete attacksList[i];
		attacksList[i] = nullptr;
	}
	attacksList.clear();

	/*cout << "destruyendo habilidades "<<endl;
	for (int i = 0; i < habilityList.size(); i++) {
		delete habilityList[i];
		habilityList[i] = nullptr;
	}
	habilityList.clear();*/
}
void Attacks::handleInput() {
	if (app_->getInputManager()->isKeyDown(highFistKey)) {
		if (attacksList[0]->canAttack()) {
			attacksList[0]->makeAttack();
			cout << "PUÑO ALTO" << endl;
		}
	}
	else if (app_->getInputManager()->isKeyDown(lowFistKey)) {
		attacksList[1]->makeAttack();
		std::cout << "PUÑO BAJO" << endl;

	}
	else if (app_->getInputManager()->isKeyDown(highKickKey)) {
		attacksList[2]->makeAttack();
		cout << "PATADA ALTA" << endl;

	}
	else if (app_->getInputManager()->isKeyDown(lowKickKey)) {
		attacksList[3]->makeAttack();
		cout << "PATADA BAJA" << endl;

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