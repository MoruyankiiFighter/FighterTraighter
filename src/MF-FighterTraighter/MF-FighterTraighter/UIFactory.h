#pragma once
#include <tuple>
#include "Entity.h"
#include "Texture.h"

using CallBackOnClick = void(App * app);

class UIFactory
{
public:
	static std::tuple<Entity*, Entity*> createButton(App* app, GameState* state, Texture* buttonTex, Font* font, Vector2D buttonPos = Vector2D(), double width = 0, double height = 0, double rotation = 0, CallBackOnClick* clickCallback = nullptr, CallBackOnClick* stopClickCallback = nullptr, string text = "", int fontSize = 20);
protected:
	UIFactory() {};
};

