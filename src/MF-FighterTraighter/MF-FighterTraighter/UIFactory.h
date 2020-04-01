#pragma once
#include <tuple>
class Entity;
class Texture;
class App;
class GameState;
class Font;
#include "Vector2D.h"
#include <string>

using CallBackOnClick = void(App * app);//method with a reference to app
using SetValueOnClick = void(App * app, double value); //method with a reference to app and a value

class UIFactory
{
public:
	//creates a button with functionality
	static std::tuple<Entity*, Entity*> createButton(App* app, GameState* state, Texture* buttonTex, Font* font, Vector2D position = Vector2D(), double width = 0, double height = 0, double rotation = 0, CallBackOnClick* clickCallback = nullptr, CallBackOnClick* stopClickCallback = nullptr, std::string text = "", int fontSize = 20);

	// Creates a slider with two texts
	static std::tuple<Entity*, Entity*, Entity*, Entity*> createSlider
	(App* app, GameState* state, double min, double max, int steps,
		Texture* texture_, Texture* reg_texture, Font* font,
		Vector2D position, double width, double height,
		SetValueOnClick* valueOnClickCallback = nullptr,
		std::string text = "", int fontSize = 20,
		std::string valueText = "", int valueFontSize = 20);


	static std::tuple<Entity*, Entity*, Entity*, Entity*, Entity*>createWinHabMenu
	//////////////////FondoP1//Hab fija//HabWin1//HabWin2//Extra
	(GameState* state, double width, double height, Texture* wallTexture_, Texture* holeTexture1_, Texture* holeTexture2_, Texture* holeTexture3_, double x, double y, Entity* player);

	static std::tuple<Entity*, Entity*, Entity*, Entity*>createLoseHabMenu
	//////////////////FondoP1//Hab fija//HabWin1//Extra
	(GameState* state, double width, double height, Texture* wallTexture_, Texture* holeTexture1_, Texture* holeTexture2_, double x, double y, Entity* player);

	static std::tuple<Entity*,std::list<Entity*>>createSelectionHabMenu
	(GameState* state, double width, double height, Texture* wallTexture_, double x, double y, Entity* player);

protected:
	UIFactory() = delete;
	~UIFactory() {};
};

