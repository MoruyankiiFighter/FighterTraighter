#include "UIFactory.h"
#include "GameState.h"
#include "EntityManager.h"
#include "Entity.h"

#include "Texture.h"

#include "Transform.h"
#include "Button.h"
#include "TextComponent.h"
#include "RenderImage.h"
#include "App.h"
#include "Slider.h"

std::tuple<Entity*, Entity*> UIFactory::createButton(App* app, GameState* state, Texture* buttonTex, Font* font, Vector2D position, double width, double height, double rotation, CallBackOnClick* clickCallback, CallBackOnClick* stopClickCallback, std::string text, int fontSize)
{
	Entity* button = state->giveMeManager().addEntity();
	button->addComponent<Transform>(position, Vector2D(), width, height, rotation);
	button->addComponent<RenderImage>(buttonTex);
	button->addComponent<Button>(clickCallback, stopClickCallback);

	Entity* textEnt = state->giveMeManager().addEntity();
	textEnt->addComponent<Transform>(position, Vector2D(), width, height, rotation);
	textEnt->addComponent<TextComponent>(text, font, fontSize);

	return std::make_tuple(button, textEnt);
}

std::tuple<Entity*> UIFactory::createSlider(App* app, GameState* state, double min, double max, int steps, Texture* texture_, Vector2D position, double width, double height, double rotation, SetValueOnClick* clickCallback, SetValueOnClick* stopClickCallback)
{
	Entity* slider = state->giveMeManager().addEntity();
	slider->addComponent<Transform>(position, Vector2D(), width, height, rotation);
	slider->addComponent<RenderImage>(texture_);
	slider->addComponent<Slider>(min, max, steps, clickCallback);

	return std::make_tuple(slider);
}
