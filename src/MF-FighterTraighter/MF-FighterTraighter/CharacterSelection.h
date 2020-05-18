#pragma once
#include "GameState.h"
#include "App.h"
class CharacterSelection: public GameState
{

public:

	//constructor
	CharacterSelection(App* app) : GameState(app) { init(); }
	virtual ~CharacterSelection() {}
	void init() override;
	void handleInput() override;
private:
	
	string mkwhoop_desc= "MKW00P: Tiene un playstyle lento pero poderoso, con golpes contundentes y de alto empuje. Tiene una vida alta.";
	string aisha_desc= "Aisha: Tiene un playstyle balanceado, ni muy rápido ni muy lento, con movimientos que brillan sobre todo en el aire. Tiene una vida media.";
	string flor_desc= "F10R: Es capaz de atacar desde muy lejos, evitando que sus oponentes se acerquen, tiene el rol de zoner. Tiene una vida media-baja.";
	string mock_desc = "MockingBird: Sus ataques son rápidos pero de poco daño, promoviendo un playstyle de hacer combos mezclándolos. Tiene una vida baja.";

};

