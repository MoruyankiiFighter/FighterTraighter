#pragma once
#include "GameState.h"
#include "App.h"

class SkillSelection: public GameState
{
public:
	SkillSelection(App* app) : GameState(app) { init(); }

	void init() override;
	void handleInput() override;
	
	void createFirstMenu();

	void createInventoryMenu();

private:
//	vector<Entity*> hab_; //todas las habilidades que genere el saco????
	bool win1 = true;
	const double ancho = app_->getWindowManager()->getCurResolution().w, alto = app_->getWindowManager()->getCurResolution().h;
	int factorLetra = 25;
	int letra = int( std::sqrt((ancho * ancho) + (alto * alto)) / factorLetra);
	string texto1 = "Esto es una descripcion de la habilidad"" seleccionada, tiene muuuuucho texto";
};

