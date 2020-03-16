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
	
	//return true if fontSize is changed
	bool setFontSize(int size);
	
	//changes the font
	void changeFont(std::string path);
	
	//load the font
	void Loadfont(std::string path, int size);
	
	//returns the font
	inline TTF_Font* getFont() { return font; }
	
	//clears the font
	void ClearFont();
protected:
	TTF_Font* font=nullptr;
	unsigned int fontSize_=0;
	std::string path_=nullptr;
};

