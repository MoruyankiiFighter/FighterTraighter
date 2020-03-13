#include "Move.h"
#include "Fight.h"
bool Move::update()
{ 
	
	if (activeFrame_ == endingFrame_) {
		hitbox_=new hitbox(10,1,entity_->getComponent<PhysicsTransform>(ecs::Transform)->getBody());
		/*std::cout << "Puum" << endl;
		hitbox_->update();*/
		static_cast<Fight*>(entity_->getApp()->getStateMachine()->getCurrentState())->destroyHitbox(entity_->getComponent<PhysicsTransform>(ecs::Transform)->getBody(),hitbox_);
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
