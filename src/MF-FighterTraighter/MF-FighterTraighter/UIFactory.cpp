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
	reg_->addComponent<RenderImage>(sides_texture);
	reg_->addComponent<IndexSlider>(slider);


	return std::make_tuple(slider, left_, right_, reg_);;
}

std::tuple<Entity*, Entity*, Entity*, Entity*, Entity*> 
UIFactory::createWinHabMenu(GameState* state, double width, double height, 
	Texture* wallTexture_, Texture* holeTexture1_, Texture* holeTexture2_, Texture* holeTexture3_, double x, double y, Entity* player1)
{
	Entity* wall_ = state->giveMeManager().addEntity();
	wall_->addComponent<Transform>(Vector2D(x,y), Vector2D(), width, height, 0);//ojo a la posicion fija CAMBIAR EN TODOS
	wall_->addComponent<RenderImage>(wallTexture_);

	Entity* hole1 = state->giveMeManager().addEntity();
	hole1->addComponent<Transform>(Vector2D(x + 300, y + 300), Vector2D(), width, height, 0);
	hole1->addComponent<RenderImage>(holeTexture1_);//pedir al saco la textura de la habilidad opcional 1
	Entity* hole2 = state->giveMeManager().addEntity();
	hole2->addComponent<Transform>(Vector2D(x + 300, y + 500), Vector2D(), width, height, 0);
	hole2->addComponent<RenderImage>(holeTexture2_);//pedir al saco la textura de la habilidad opcional 2
	Entity* hole3 = state->giveMeManager().addEntity();
	hole3->addComponent<Transform>(Vector2D(x + 500, y + 400), Vector2D(), width, height, 0);
	hole3->addComponent<RenderImage>(holeTexture3_);//pedir al saco la textura de la habilidad fija
	Entity* extra = state->giveMeManager().addEntity();
	

	return std::make_tuple(wall_, hole1, hole2, hole3, extra);
}

std::tuple<Entity*, Entity*, Entity*, Entity*>
UIFactory::createLoseHabMenu(GameState* state, double width, double height, Texture* wallTexture_, Texture* holeTexture1_, Texture* holeTexture3_, double x, double y, Entity* player2)
{
	Entity* wall_ = state->giveMeManager().addEntity();
	wall_->addComponent<Transform>(Vector2D(100, 100), Vector2D(), width, height, 0);//ojo a la posicion fija CAMBIAR EN TODOS
	wall_->addComponent<RenderImage>(wallTexture_);

	Entity* hole1 = state->giveMeManager().addEntity();
	hole1->addComponent<Transform>(Vector2D(300, 300), Vector2D(), width, height, 0);
	hole1->addComponent<RenderImage>(holeTexture1_);//pedir al saco la textura de la habilidad opcional 1
	
	Entity* hole3 = state->giveMeManager().addEntity();
	hole3->addComponent<Transform>(Vector2D(500, 400), Vector2D(), width, height, 0);
	hole3->addComponent<RenderImage>(holeTexture3_);//pedir al saco la textura de la habilidad fija

	Entity* extra = state->giveMeManager().addEntity();


	return std::make_tuple(wall_, hole1, hole3, extra);
	
}

std::tuple<Entity*,std::list<Entity*>> 
UIFactory::createSelectionHabMenu(GameState* state, double width, double height, Texture* wallTexture_, double x, double y, Entity* player)
{
	Entity* wall_ = state->giveMeManager().addEntity();
	wall_->addComponent<Transform>(Vector2D(x, y), Vector2D(), width, height, 0);
	wall_->addComponent<RenderImage>(wallTexture_);

	std::list<Entity*>hab;

	


	return std::make_tuple(wall_, hab);
}


