#pragma once
#include <tuple>
class Entity;
class Texture;
class App;
class GameState;
class Font;
#include "Vector2D.h"
#include <string>

using CallBackOnClick = void(App * app);

using SetValueOnClick = void(App * app, double value);

class UIFactory
{
public:
	static std::tuple<Entity*, Entity*> createButton(App* app, GameState* state, Texture* buttonTex, Font* font, Vector2D position = Vector2D(), double width = 0, double height = 0, double rotation = 0, CallBackOnClick* clickCallback = nullptr, CallBackOnClick* stopClickCallback = nullptr, std::string text = "", int fontSize = 20);

	static std::tuple<Entity*> createSlider(App* app, GameState* state, double min,double max ,int steps, Texture* texture_, Vector2D position = Vector2D(), double width = 0, double height = 0, double rotation = 0, SetValueOnClick* clickCallback = nullptr, SetValueOnClick* stopClickCallback = nullptr);

protected:
	UIFactory() = delete;
	~UIFactory() {};
};

