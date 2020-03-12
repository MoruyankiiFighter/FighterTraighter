#include "Move.h"
#include "hitbox.h"
bool Move::update()
{
	if (activeFrame_ == endingFrame_) {
		hitbox(10,1,entity_->getComponent<PhysicsTransform>(ecs::Transform)->getBody());
		std::cout << "Puum" << endl;
		return true;
	}
	else {
		activeFrame_++;
		return false;
	}
}

void Move::render()
{
	//Renderizar seg�n activeFrame_, por lo que todas tendr�n que tener frames reptidos en lo que a dibujo se refiere
	//animaSheet_->render()
}
