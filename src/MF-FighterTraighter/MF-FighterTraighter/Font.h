#pragma once
#include <string>
#include "SDL_ttf.h"

class Font
{
public:
	Font();
	Font(std::string path, int file) { Loadfont(path, file); }
	void Loadfont(std::string path, int size);
	void ClearFont();
	virtual ~Font();
protected:
	TTF_Font* font;
};

