#pragma once
#include <string>
#include <vector>
#include "Texture.h"
#include "Entity.h"
#include "PhysicsTransform.h"
using namespace std;
using callBackOnEnd = void();

/*enum idMovimiento {
	Pu�oN = 0,
	Pu�oF = 1,
	PatadaN = 2,
	PatadaF = 3,
	Pu�oNA = 4,
	Pu�oFA = 5,
	PatadaNA = 6,
	PatadaFA = 7,
	Pu�oNC = 8,
	Pu�oFC = 9,
	PatadaNC = 10,
	PatadaFC = 11,
};*/

class Move {
public:
	Move() : endingFrame_(15), animaSheet_(nullptr) {};
	Move(/*string name, idMovimiento id, */int endingFrame, Texture* animSheet,Entity* entity) : 
	/*name_(name), id_(id), */endingFrame_(endingFrame), animaSheet_(animSheet),entity_(entity) {};
	~Move() {};
	void resetIndex() { activeFrame_ = 0; }
	bool update();
	void render();
private:
	int activeFrame_ = 0;
	int endingFrame_ = 15; 
	/*string name_;
	dMovimiento id_;*/
	Texture* animaSheet_;
	callBackOnEnd generateHitbox; //crea hitboxes con da�o, posici�n, escala, empuje y frames de vida
	Entity* entity_;
};
