#pragma once
#include <string>
#include "SDL_ttf.h"

class Font
{
public:
	Font();
	Font(const Font&) = delete;
	Font operator=(const Font&) = delete;
	Font(std::string path, int file) { Loadfont(path, file); }

	void setFontSize(int size);
	void changeFont(std::string path);
	void Loadfont(std::string path, int size);
	inline TTF_Font* getFont() { return font; }

	void ClearFont();
	virtual ~Font();
protected:
	TTF_Font* font;
	int fontSize_;
	std::string path_;
};

