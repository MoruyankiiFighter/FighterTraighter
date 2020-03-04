#pragma once
#include <string>
#include <vector>
#include "Texture.h"

using namespace std;
using callBackOnEnd = void();

/*enum idMovimiento {
	PuñoN = 0,
	PuñoF = 1,
	PatadaN = 2,
	PatadaF = 3,
	PuñoNA = 4,
	PuñoFA = 5,
	PatadaNA = 6,
	PatadaFA = 7,
	PuñoNC = 8,
	PuñoFC = 9,
	PatadaNC = 10,
	PatadaFC = 11,
};*/

class Move {
public:
	Move(/*string name, idMovimiento id, */int endingFrame, Texture* animSheet) : 
	/*name_(name), id_(id), */endingFrame_(endingFrame), animaSheet_(animSheet) {};
	~Move() {};

	bool update();
	void render();
private:
	int activeFrame_ = 0;
	int endingFrame_ = 15; 
	/*string name_;
	dMovimiento id_;*/
	Texture* animaSheet_;
	callBackOnEnd generateHitbox; //crea hitboxes con daño, posición, escala, empuje y frames de vida
};
