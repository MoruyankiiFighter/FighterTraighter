#include "Move.h"

void Move::update()
{
	if (activeHitbox_ == nullptr) {
		if (frameData_[index_].getX() == activeFrame_) {
			activeHitbox_ = hitboxData_[index_];
		}
	}
	else if (frameData_[index_].getX() == activeFrame_) {
		delete activeHitbox_;
		activeHitbox_ = nullptr;
		index_++;
	}

	if (index_ > hitboxData_.size()) {
		//Movimiento acabado
		//Player->returnControl();
	}
	activeFrame_++;
}

void Move::render()
{
	//Renderizar según activeFrame_, por lo que todas tendrán que tener frames reptidos en lo que a dibujo se refiere
	//animaSheet_->render()
}
