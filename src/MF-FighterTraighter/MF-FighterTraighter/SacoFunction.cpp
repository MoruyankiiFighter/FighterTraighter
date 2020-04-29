#include "SacoFunction.h"

void SacoFunction::update()
{
	cout << "compruebo si saco sigue con vida" << endl;
	if (entity_->getComponent<Health>(ecs::Health)->getHealth() <= 0) {
		//llama al metodo de dame habilidades
		player->addAbilityInventory("Counter");
		player->addAbilityInventory("Shell Power");
	}
}
