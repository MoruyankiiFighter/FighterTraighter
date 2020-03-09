#pragma once
#include "Texture.h"
class Text :
	protected Texture
{
public:
	Text(std::string text);
	Text(const Text&) = delete;
	Text operator=(const Text&) = delete;

	void setText(std::string text);
	void render(const SDL_Rect& rect) const;

	virtual ~Text();
protected:
	std::string text_;
};

