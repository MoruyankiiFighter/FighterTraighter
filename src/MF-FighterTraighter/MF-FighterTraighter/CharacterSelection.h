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
	
	string mkwhoop_desc= "MKW00P: \n  Tiene un playstyle lento pero poderoso, \n con golpes contundentes y de alto empuje.\n Tiene una vida alta.";
	string aisha_desc= "Aisha: \n Tiene un playstyle balanceado, ni muy rápido ni muy lento,\n con movimientos que brillan sobre todo en el aire. \n Tiene una vida media.";
	string flor_desc= "F10R: \n Es capaz de atacar desde muy lejos, \n evitando que sus oponentes se acerquen, tiene el rol de zoner. \n Tiene una vida media-baja.";
	string mock_desc = "MockingBird: \n Sus ataques son rápidos pero de poco daño, \n promoviendo un playstyle de hacer combos mezclándolos. \n Tiene una vida baja.";

};

