#pragma once
#include "Component.h"
#include "Entity.h"
#include "Transform.h"
#include "Texture.h"


using CallBackOnClick = void(App* app);
//callbacks para el menu principal
void ArcadeCallback(App* app);
void OnevsOneCallback(App* app);
void ExitCallback(App* app);
void OptionsCallback(App* app);
//callback para el juego
void PauseCallback(App* app);
//callbacks para el menu pausa
void ContinuePlayingCallback(App* app);
void MovementsCallback(App* app);
void MenuCallback(App* app);


class Button : public Entity
{
private:
	
	Transform* button;
	Texture* buttonTex;
	GameState* state;
	CallBackOnClick* callbackbutton;

public:
	Button(Transform* pos, Texture* Button, GameState* state, CallBackOnClick* call);
	virtual void render();
	virtual void handleEvent(SDL_Event& event);
};



