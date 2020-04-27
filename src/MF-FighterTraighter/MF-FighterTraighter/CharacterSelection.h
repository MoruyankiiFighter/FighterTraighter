#pragma once
#include "GameState.h"
class CharacterSelection: public GameState
{

public:
	//constructor
	CharacterSelection(App* app) : GameState(app) { init(); }
	
	void init() override;
	void handleInput() override {}


private:
	const double ancho = app_->getWindowManager()->getCurResolution().w, alto = app_->getWindowManager()->getCurResolution().h;
	int factorLetra = 25;
	int letra = int(std::sqrt((ancho * ancho) + (alto * alto)) / factorLetra);
	std::vector <string> descriptions {" MKW00P: Tiene un playstyle lento pero poderoso, con golpes contundentes y de alto empuje. Tiene una vida alta.",
								   "F10R: Es capaz de atacar desde muy lejos, evitando que sus oponentes se acerquen, tiene el rol de zoner. Tiene una vida media-baja.",
								   "Aisha: Tiene un playstyle balanceado, ni muy r�pido ni muy lento, con movimientos que brillan sobre todo en el aire. Tiene una vida media.",
								   "MockingBird: Sus ataques son r�pidos pero de poco da�o, promoviendo un playstyle de hacer combos mezcl�ndolos. Tiene una vida baja." };
};

