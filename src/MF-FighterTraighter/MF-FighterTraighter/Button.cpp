#include "Button.h"
#include "Entity.h"
#include "Transform.h"

void Button::init()
{
	render_ = entity_->getComponent<RenderImage>(ecs::RenderImage);
}

void Button::handleInput()
{
	if (app_->getInputManager()->isMouseButtonPressed(app_->getInputManager()->Left)) {
		cout << "click";
		SDL_Point p = { app_->getInputManager()->getMousePosX(),app_->getInputManager()->getMousePosY() };

		if (SDL_PointInRect(&p, &render_->getDestRect())) {
			cout << "arcade";
		}

		//app_->PlayArcade();
	}

}