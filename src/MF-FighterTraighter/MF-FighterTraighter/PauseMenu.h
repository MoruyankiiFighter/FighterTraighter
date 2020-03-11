#pragma once
#include "GameState.h"
#include "Texture.h"
#include <string>

//callbacks para el menu de pausa
void ContinuePlayingCallback(App* app);
void MovementsCallback(App* app);
void MenuCallback(App* app);
void OptionsCallback(App* app);

class PauseMenu: public GameState
{

public:
	PauseMenu(App* app) : GameState(app) {
		std::cout << "Pausado" << endl;
		init();
	};
	~PauseMenu() {}

	void init();
	virtual void render() override;
	virtual void update() override;
	void handleInput();
};

