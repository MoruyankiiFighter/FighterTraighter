#include "Button.h"
#include "Entity.h"
#include "Transform.h"

void Button::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(app_->getInputManager()->Left)) {
		cout << "click";
		app_->PlayArcade();
	}

}