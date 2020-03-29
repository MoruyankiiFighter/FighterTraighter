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
#include "IndexSlider.h"

//create a button with their callbacks
std::tuple<Entity*, Entity*> UIFactory::createButton
	(App* app, GameState* state, Texture* buttonTex, 
	Font* font, Vector2D position, double width, double height, double rotation, 
	CallBackOnClick* clickCallback, CallBackOnClick* stopClickCallback, std::string text, int fontSize)
{
	Entity* button = state->getEntityManager().addEntity();
	button->addComponent<Transform>(position, Vector2D(), width, height, rotation);
	button->addComponent<RenderImage>(buttonTex);
	button->addComponent<Button>(clickCallback, stopClickCallback);

	Entity* textEnt = state->getEntityManager().addEntity();
	textEnt->addComponent<Transform>(position, Vector2D(), width, height, rotation);
	textEnt->addComponent<TextComponent>(text, font, fontSize);

	return std::make_tuple(button, textEnt);
}

// create the structure of  slider (bar, buttons and the index)
std::tuple<Entity*, Entity*, Entity*, Entity*> UIFactory::createSlider
	(App* app, GameState* state, double min, double max, int steps, 
	Texture* texture_, Texture* reg_texture, Font* font,
	Vector2D position, double width, double height,
	SetValueOnClick* valueOnClickCallback,
	std::string text, int fontSize,
	std::string valueText, int valueFontSize)
{
	Entity* slider = state->getEntityManager().addEntity();
	slider->addComponent<Transform>(position, Vector2D(), width, height, 0);
	slider->addComponent<RenderImage>(texture_);
	slider->addComponent<Slider>(min, max, steps, valueOnClickCallback);

	Entity* reg_ = state->getEntityManager().addEntity();
	reg_->addComponent<Transform>(position, Vector2D(), 25, height * 5, 0);
	reg_->addComponent<RenderImage>(reg_texture);
	reg_->addComponent<IndexSlider>(slider);
	
	Entity* text_ = state->getEntityManager().addEntity();
	text_->addComponent<Transform>(Vector2D(position.getX(), position.getY() - fontSize - 20), Vector2D(), width, fontSize, 0);
	text_->addComponent<TextComponent>(text, font, fontSize);
	
	Entity* ValueText_ = state->getEntityManager().addEntity();
	ValueText_->addComponent<Transform>(Vector2D(position.getX() + width + 10, position.getY() - fontSize / 2), Vector2D(), width, fontSize, 0);
	ValueText_->addComponent<TextComponent>(valueText, font, valueFontSize);

	return std::make_tuple(slider, reg_, text_, ValueText_);
}
