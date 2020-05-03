#pragma once
#include "GameState.h"
#include "App.h"
class CharacterSelection: public GameState
{

public:

	//constructor
	CharacterSelection(App* app) : GameState(app) { init(); }

	void init() override;


	//callbacks
	static void setAisha(App* app);
	static void setFlor(App* app);
	static void setGanonbot(App* app);
	static void setMockingBird(App* app);
	static void setRandomCharacter(App* app);

	static void GoToFight(App* app);


private:
	
	string mkwhoop_desc= " Tiene un playstyle lento pero poderoso de golpes potentes";
	string aisha_desc= " Tiene un playstyle balanceado con movimientos que brillan en el aire. ";
	string flor_desc= "Es capaz de atacar desde muy lejos, evitando que se acerquen.";
	string mock_desc = " Sus ataques son rápidos pero de poco daño, promoviendo un playstyle de hacer combos. ";

};

