#pragma once
#include <string>
#include "SDL_ttf.h"

class Font
{
public:
	//constructor
	Font();
	Font(const Font&) = delete;
	Font operator=(const Font&) = delete;
	Font(std::string path, int size, int symbolWidth) { Loadfont(path, size, symbolWidth); }

	//destructor
	virtual ~Font();

	//change the font size to size
	bool setFontSize(int size);
	
	//change the current font to the path one
	void changeFont(std::string path);
	void setSymbolWidth(int symbolWidth);
	void Loadfont(std::string path, int size, int symbolWidth);
	inline TTF_Font* getFont() const { return font; }
	inline int getSymbolWidth() const { return symbolWidth_; }

	void ClearFont();

protected:
	TTF_Font* font;
	int fontSize_;
	std::string path_;
	int symbolWidth_;
};

