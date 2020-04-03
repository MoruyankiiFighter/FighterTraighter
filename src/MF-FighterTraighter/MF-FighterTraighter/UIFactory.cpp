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

Entity* UIFactory::createPanel(App* app, GameState* state, Texture* texture_, Vector2D position, double width, double height, double rotation)
{
	Entity* panel = state->getEntityManager().addEntity();
	panel->addComponent<Transform>(position, Vector2D(), width, height, rotation);
	panel->addComponent<RenderImage>(texture_);
	//a�adir tema de UIComponent para las resoluciones

	return panel;
}

std::tuple<Entity*, Entity*, Entity*, Entity*, Entity*> 
UIFactory::createWinHabMenu(App* app, GameState* state, double width, double height, 
	Texture* wallTexture_, Texture* holeTexture1_, Texture* holeTexture2_, Texture* holeTexture3_, double x, double y, Entity* player1)
{
	
	Entity* wall_ = createPanel(app, state, wallTexture_, Vector2D(x, y), width, height);
	//habilitys are like buttons, in input manager we have to change the events (for now are just buttons)

	Entity* hab1;
	Entity* hab2;
	Entity* hab3;

	Entity* extra;
	return std::make_tuple(wall_, hab1,hab2,hab3,extra);
}

std::tuple<Entity*, Entity*, Entity*>
UIFactory::createLoseHabMenu(GameState* state, double width, double height, Texture* wallTexture_, Texture* holeTexture1_, double x, double y, Entity* player2)
{
	Entity* wall_ = state->getEntityManager().addEntity();
	wall_->addComponent<Transform>(Vector2D(100, 100), Vector2D(), width, height, 0);//ojo a la posicion fija CAMBIAR EN TODOS
	wall_->addComponent<RenderImage>(wallTexture_);

	Entity* hole1 = state->getEntityManager().addEntity();
	hole1->addComponent<Transform>(Vector2D(300, 300), Vector2D(), width, height, 0);
	hole1->addComponent<RenderImage>(holeTexture1_);//pedir al saco la textura de la habilidad opcional 1
	
	Entity* hole3 = state->getEntityManager().addEntity();
	hole3->addComponent<Transform>(Vector2D(500, 400), Vector2D(), width, height, 0);
	hole3->addComponent<RenderImage>(holeTexture3_);//pedir al saco la textura de la habilidad fija

	Entity* extra = state->getEntityManager().addEntity();


	return std::make_tuple(wall_, hole1, extra);
	
}

//std::tuple<Entity*,std::list<Entity*>> 
//UIFactory::createSelectionHabMenu(GameState* state, double width, double height, Texture* wallTexture_, double x, double y, Entity* player)
//{
//	Entity* wall_ = state->getEntityManager().addEntity();
//	wall_->addComponent<Transform>(Vector2D(x, y), Vector2D(), width, height, 0);
//	wall_->addComponent<RenderImage>(wallTexture_);
//
//	std::list<Entity*>hab;
//	//hab = player->getHabilitiesList();
//	//pedir al player su lista de habilidades
//
//	for (int i = 0; i < hab.size(); i++) {
//		Entity* num_ = state->getEntityManager().addEntity();
//		num_->addComponent<Transform>(Vector2D(x, y), Vector2D(), width, height, 0);
//		num_->addComponent<RenderImage>(/*hab[i].getRender()*/);
//	}
//
//
//	return std::make_tuple(wall_, hab);
//}
//
//
