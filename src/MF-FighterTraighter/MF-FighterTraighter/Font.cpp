#include "Font.h"

Font::Font() : font(nullptr)
{
}

void Font::Loadfont(std::string path, int size)
{
	if (font == nullptr) ClearFont();
	TTF_OpenFont(path.c_str(), size);
}

void Font::ClearFont()
{
	TTF_CloseFont(font);
}

Font::~Font() 
{
	ClearFont();
}
