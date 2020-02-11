#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>

using namespace std;

class Texture {
private:
	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;

	int width = 0;
	int height = 0;

	int fWidth = 0;
	int fHeight = 0;

	int nCols = 0;
	int nRows = 0;

public:
	Texture(SDL_Renderer* rend) : renderer(rend) {};
	Texture(SDL_Renderer* rend, string fileName, int cols, int fils) : renderer(rend) {
		load(fileName, nCols, nRows);
	};
	Texture(Texture& tex) = delete; // No copy constructor
	Texture operator=(Texture& tex) = delete; // No assignment operator
	~Texture() { clean(); };

	void load(string filename, int cols, int fils);
	void clean();
	void render(const SDL_Rect& rect, SDL_RendererFlip flip = SDL_FLIP_NONE) const; 
	void render(const SDL_Rect& destRect, int row, int col, int angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE) const;
};