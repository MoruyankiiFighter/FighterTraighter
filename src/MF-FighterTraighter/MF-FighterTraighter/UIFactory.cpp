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

std::tuple<Entity*, Entity*, Entity*, Entity*> UIFactory::createSlider
	(App* app, GameState* state, double min, double max, int steps, 
	Texture* texture_, Texture* sides_texture, Texture* reg_texture, 
	Vector2D position, double width, double height, double sides_width, double sides_height,
	SetValueOnClick* clickCallback, SetValueOnClick* stopClickCallback, CallBackOnClick* left, CallBackOnClick* right, 
	std::string text_left, std::string text_right, int fontSize)
{
	Entity* slider = state->giveMeManager().addEntity();
	slider->addComponent<Transform>(position, Vector2D(), width, height, 0);
	slider->addComponent<RenderImage>(texture_);
	slider->addComponent<Slider>(min, max, steps, clickCallback);

	Entity* left_ = state->giveMeManager().addEntity();
	left_->addComponent<Transform>(Vector2D(position.getX()-sides_width/2,position.getY()-sides_height/2), Vector2D(), sides_width, sides_height, 0);
	left_->addComponent<RenderImage>(sides_texture);
	left_->addComponent<Button>(left, nullptr);

	Entity* right_ = state->giveMeManager().addEntity();
	right_->addComponent<Transform>(Vector2D(position.getX() + width-sides_width/2 , position.getY()-sides_height/2), Vector2D(), sides_width, sides_height, 0);
	right_->addComponent<RenderImage>(sides_texture);
	right_->addComponent<Button>(right, nullptr);

	Entity* reg_ = state->giveMeManager().addEntity();

	reg_->addComponent<Transform>(position, Vector2D(), sides_width / 2, sides_height, 0);
	//reg_->addComponent<RenderImage>(sides_texture);

	return std::make_tuple(slider, left_, right_, reg_);;
}
