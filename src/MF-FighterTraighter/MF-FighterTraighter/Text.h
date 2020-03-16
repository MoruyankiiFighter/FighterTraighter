#pragma once
#include "Texture.h"
#include "Font.h"
class Text :
	protected Texture
{
public:
	//constructor
	Text(SDL_Renderer* rend);
	Text(SDL_Renderer* rend, std::string text, Font* font);
	Text(const Text&) = delete;

	//destructor
	virtual ~Text();
	
	//create the text
	void createText(Font* font, std::string text);
	
	Text operator=(const Text&) = delete;
	
	//set the string text into a new text
	void setText(std::string text);
	
	//set the size
	void setSize(int size);
	
	//set the font
	void setFont(Font* font);

	//render the string with their font
	void render(const SDL_Rect& dest) const;

	
protected:
	std::string text_ = "";
	Font* font_ = nullptr;
};

