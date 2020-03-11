#pragma once
#include "Component.h"
#include "Text.h"
#include "Transform.h"
class TextComponent :
	public Component
{
public:
	TextComponent(std::string text, Font* font, int size);
	void init() override;
	void render() override;

	void setText(std::string text);
	void setSize(int size);
	void setFont(Font* font);

	virtual ~TextComponent();
protected:
	Transform* transform_;
	Text* text_;
	std::string textString_;
	int textSize_;
	Font* font_;
};

