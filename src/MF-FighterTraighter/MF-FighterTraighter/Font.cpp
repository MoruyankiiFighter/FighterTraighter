#include "Font.h"

Font::Font() : font(nullptr), fontSize_(), path_()
{
}

void Font::setFontSize(int size)
{
	if (fontSize_ != size) {
		ClearFont();
		Loadfont(path_, size);
	}
}

void Font::changeFont(std::string path)
{
	if (path_ != path) {
		ClearFont();
		Loadfont(path, fontSize_);
	}
}

void Font::Loadfont(std::string path, int size)
{
	if (font != nullptr) ClearFont();
	font = TTF_OpenFont(path.c_str(), size);
	if (font == nullptr) throw "Error"; // CHANGE TO PROPER EXCEPTION
	path_ = path;
	fontSize_ = size;
}

void Font::ClearFont()
{
	TTF_CloseFont(font);
}

Font::~Font() 
{
	ClearFont();
}
