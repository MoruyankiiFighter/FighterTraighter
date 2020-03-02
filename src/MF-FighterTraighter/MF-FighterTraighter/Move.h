#pragma once
#include <string>
#include <vector>
#include "Texture.h"

using namespace std;

enum idMovimiento {
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
