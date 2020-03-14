#include "Move.h"
#include "Fight.h"
#include "creatorBody.h"
bool Move::update()
{ 
	
	if (activeFrame_ == endingFrame_) {
		//hitbox_=new hitbox(10,1,entity_->getComponent<PhysicsTransform>(ecs::Transform)->getBody());
		std::cout << "Puum" << endl;
		entity_->getComponent<creatorBody>(ecs::CreatorBody)->createHitbox({ 200,0 }, 50, 50, 10, 50, { 0,0 });
		//hitbox_->update();
		//static_cast<Fight*>(entity_->getApp()->getStateMachine()->getCurrentState())->destroyHitbox(entity_->getComponent<PhysicsTransform>(ecs::Transform)->getBody(),hitbox_);
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
