#pragma once
#include "GameState.h"
#include "Texture.h"
class App;
//callbacks para el menu principal
void ArcadeCallback(App* app);
void OneVsOneCallback(App* app);
void OptionsCallback(App* app);
void ExitCallback(App* app);

class MainMenu : public GameState
{
public:
	MainMenu(App* app);
	virtual ~MainMenu();
	void init();
	virtual void render() override;
	virtual void update() override;
	void handleInput();

	//Funciones botones
	void OnButtClick(string text);

private:
	Entity* arcade;
	Entity* pvp;
	Entity* options;
	Entity* exit;
};
