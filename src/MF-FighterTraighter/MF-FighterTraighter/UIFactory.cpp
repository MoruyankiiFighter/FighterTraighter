#include "UIFactory.h"
#include "GameState.h"

#include "Transform.h"
#include "Button.h"
#include "TextComponent.h"
#include "RenderImage.h"
#include "App.h"

std::tuple<Entity*, Entity*> UIFactory::createButton(App* app, GameState* state, Texture* buttonTex, Font* font, Vector2D position, double width, double height, double rotation, CallBackOnClick* clickCallback, CallBackOnClick* stopClickCallback, string text, int fontSize)
{
	Entity* button = new Entity(); // TODO: use entityManager
	button->setApp(app); // TODO: use entityManager
	button->addComponent<Transform>(position, Vector2D(), width, height, rotation);
	button->addComponent<RenderImage>(buttonTex);
	button->addComponent<Button>(clickCallback, stopClickCallback);
	//state->scene.push_back(button); TODO: use entityManager

	Entity* textEnt = new Entity(); // TODO
	textEnt->setApp(app); // TODO
	textEnt->addComponent<Transform>(position, Vector2D(), width, height, rotation);
	textEnt->addComponent<TextComponent>(text, font, fontSize);
	//state->scene.push_back(textEnt); TODO: use entityManager

	return std::make_tuple(button, textEnt);
}
