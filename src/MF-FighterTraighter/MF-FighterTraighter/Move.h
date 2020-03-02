#pragma once
#include <string>
#include <vector>
#include "Texture.h"

using namespace std;

enum idMovimiento {
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
};

class Move {
public:
	Move(string name, idMovimiento id, Texture* animSheet) : 
	name_(name), id_(id), animaSheet_(animSheet) {};
	~Move() {};

	void update();
	void render();
private:
	int activeFrame_ = 0;
	int index_ = 0;
	string name_;
	idMovimiento id_;
	Texture* animaSheet_;
	SDL_Rect* activeHitbox_ = nullptr;
	vector<SDL_Rect*> hitboxData_;
	vector<Vector2D> frameData_;
};
