#include "Texture.h"

void Texture::clean() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
	width = height = fWidth = fHeight = nCols = nRows = 0;
}

void Texture::load(string filename, int cols, int rows) {
	SDL_Surface* tempSurface = IMG_Load(filename.c_str());
	if (tempSurface == nullptr); //Excepción
	clean();
	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (texture == nullptr); //Excepción

	nCols = cols;
	nRows = rows;
	width = tempSurface->w;
	height = tempSurface->h;
	fWidth = width / cols;
	fHeight = height / rows;

	SDL_FreeSurface(tempSurface);
}

void Texture::render(const SDL_Rect& rect, SDL_RendererFlip flip) const{
	SDL_Rect srcRect;
	srcRect.x = 0; srcRect.y = 0;
	srcRect.w = width; srcRect.h = height;
	SDL_RenderCopyEx(renderer, texture, &srcRect, &rect, 0, 0, flip);
}

void Texture::renderFrame(const SDL_Rect& destRect, int row, int col, int angle, SDL_RendererFlip flip) const {
	SDL_Rect srcRect;
	srcRect.x = fWidth * col; srcRect.y = fHeight * row;
	srcRect.w = fWidth; srcRect.h = fHeight;
	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, angle, 0, flip);
}