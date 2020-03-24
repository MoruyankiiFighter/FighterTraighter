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
	Font(std::string path, int size) { Loadfont(path, size); }

	//destructor
	virtual ~Font();

	//change the font size to size
	bool setFontSize(int size);
	
	//change the current font to the path one
	void changeFont(std::string path);
	
	//load the font
	void Loadfont(std::string path, int size);
	
	//returns the current font
	inline TTF_Font* getFont() { return font; }
	
	//deletes the font
	void ClearFont();

protected:
	TTF_Font* font; //current font
	int fontSize_; //current size
	std::string path_; //path of the font
};

