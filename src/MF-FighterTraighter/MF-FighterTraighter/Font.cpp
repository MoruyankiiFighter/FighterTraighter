#include "Font.h"
#include "AssetsExceptions.h"

Font::Font() : font(nullptr), fontSize_(), path_(), symbolWidth_()
{
}

//destructor
Font::~Font()
{
	ClearFont();
}

//change font size, returns false if the fontsize is equals to the size that we want to change
bool Font::setFontSize(int size)
{
	if (fontSize_ != size) {
		Loadfont(path_, size, symbolWidth_);
		return true;
	}
	return false;
}

//changes the font
void Font::changeFont(std::string path)
{
	if (path_ != path) {
		Loadfont(path, fontSize_, symbolWidth_);
	}
}

// Width of every character
void Font::setSymbolWidth(int symbolWidth)
{
	symbolWidth_ = symbolWidth;
}

// Loads a font using these args
void Font::Loadfont(std::string path, int size, int symbolWidth)
{
	if (font != nullptr) ClearFont();
	font = TTF_OpenFont(path.c_str(), size);
	if (font == nullptr) throw new AssetsExceptions::FontException("Unable to load font: ", path);
	path_ = path;
	fontSize_ = size;
	symbolWidth_ = symbolWidth;
}

//deletes the font
void Font::ClearFont()
{
	TTF_CloseFont(font);
}
