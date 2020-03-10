#pragma once
#include "Component.h"
#include "Text.h"
#include "Transform.h"
class TextComponent :
	public Component
{
public:
	TextComponent(Text* text);
	void init() override;
	void render() override;

	void setText(std::string text);
	void setFont(Font* font);

	virtual ~TextComponent();
protected:
	Transform* transform_;
	Text* text_;
};

