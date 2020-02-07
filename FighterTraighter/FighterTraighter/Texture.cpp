#include "Texture.h"
#include <exception>
#include <assert.h>

void Texture::clean() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

void Texture::load(string filename, int cols, int rows) {
	SDL_Surface* tempSurface = IMG_Load(filename.c_str());
	if (tempSurface == nullptr) throw "Unable to load " + filename; // TODO: change to proper exception
	clean();
	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	//assert(texture == nullptr); // For debugging

	nCols = cols;
	nRows = rows;
	width = tempSurface->w;
	height = tempSurface->h;
	fWidth = width / cols;
	fHeight = height / rows;

	SDL_FreeSurface(tempSurface);
}

// Render whole image, or first frame
void Texture::render(const SDL_Rect& destRect, SDL_RendererFlip flip) const{
	render(destRect, 0, 0, 0, flip);
}

// Render only a frame, or at an angle
void Texture::render(const SDL_Rect& destRect, int row, int col, int angle, SDL_RendererFlip flip) const {
	SDL_Rect srcRect;
	srcRect.x = fWidth * col; srcRect.y = fHeight * row;
	srcRect.w = fWidth; srcRect.h = fHeight;
	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, angle, 0, flip);
}