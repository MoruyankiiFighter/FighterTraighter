#pragma once
#include "GameState.h"
#include "App.h"
class CharacterSelection: public GameState
{

public:

	//constructor
	CharacterSelection(App* app) : GameState(app) { init(); }
	
	void init() override;

private:
	double ancho = app_->getWindowManager()->getCurResolution().w, alto = app_->getWindowManager()->getCurResolution().h;
	int factorLetra = 25;
	int letra = int(std::sqrt((ancho * ancho) + (alto * alto)) / factorLetra);
	/*std::vector <std::string> descriptions {" ,
								   "F10R: Es capaz de atacar desde muy lejos, evitando que sus oponentes se acerquen, tiene el rol de zoner. Tiene una vida media-baja.",
								   "Aisha: Tiene un playstyle balanceado, ni muy rápido ni muy lento, con movimientos que brillan sobre todo en el aire. Tiene una vida media.",
								   "MockingBird: Sus ataques son rápidos pero de poco daño, promoviendo un playstyle de hacer combos mezclándolos. Tiene una vida baja." };*/

	string mkwhoop_desc= "MKW00P: \n  Tiene un playstyle lento pero poderoso, \n con golpes contundentes y de alto empuje.\n Tiene una vida alta.";

	string aisha_desc= "Aisha: \n Tiene un playstyle balanceado, ni muy rápido ni muy lento,\n con movimientos que brillan sobre todo en el aire. \n Tiene una vida media.";

	string flor_desc= "F10R: \n Es capaz de atacar desde muy lejos, \n evitando que sus oponentes se acerquen, tiene el rol de zoner. \n Tiene una vida media-baja.";

	string mock_desc = "MockingBird: \n Sus ataques son rápidos pero de poco daño, \n promoviendo un playstyle de hacer combos mezclándolos. \n Tiene una vida baja.";

};

