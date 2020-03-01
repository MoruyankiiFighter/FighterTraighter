#include "Button.h"
#include "Entity.h"
#include "Transform.h"

void Button::handleInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
		SDL_Point point = { event.button.x, event.button.y };
		Transform* trans = entity_->getComponent<Transform>(ecs::Transform);
		Vector2D pos = trans->getPosition();
		SDL_Rect collRect = { pos.getX(), pos.getY(), trans->getWidth(), trans->getHeight() };
		if (SDL_PointInRect(&point, &collRect) == SDL_TRUE) {
			funct_("texto");
		};
	};
}