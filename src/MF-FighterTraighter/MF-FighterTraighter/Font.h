#pragma once
#include <string>
#include "SDL_ttf.h"

class Font
{
public:
	Font();
	Font(const Font&) = delete;
	Font operator=(const Font&) = delete;
	Font(std::string path, int size, int symbolWidth) { Loadfont(path, size, symbolWidth); }

	bool setFontSize(int size);
	void changeFont(std::string path);
	void setSymbolWidth(int symbolWidth);
	void Loadfont(std::string path, int size, int symbolWidth);
	inline TTF_Font* getFont() const { return font; }
	inline int getSymbolWidth() const { return symbolWidth_; }

	void ClearFont();
	virtual ~Font();
protected:
	TTF_Font* font;
	int fontSize_;
	std::string path_;
	int symbolWidth_;
};

