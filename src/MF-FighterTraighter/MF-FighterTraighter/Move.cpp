#include "Move.h"

bool Move::update()
{
	if (activeFrame_ == endingFrame_) {
		if(generateHitbox_ != nullptr) generateHitbox_();
		else std::cout << "Puum" << endl;
		return true;
	}
	else {
		activeFrame_++;
		return false;
	}
}

void Move::render()
{
	//Renderizar según activeFrame_, por lo que todas tendrán que tener frames reptidos en lo que a dibujo se refiere
	//animaSheet_->render()
}
