#pragma once
#include "GameState.h"
#include "Texture.h"
class App;
class MainMenu : public GameState
{
public:
	MainMenu(App* app);
	~MainMenu();
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

	Texture* texture_=nullptr;
	Texture* logo_=nullptr;
};
