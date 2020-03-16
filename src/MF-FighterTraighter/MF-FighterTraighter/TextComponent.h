#pragma once
#include "Component.h"
#include "Text.h"
#include "Transform.h"
class TextComponent :
	public Component
{
public:
	//constructor
	TextComponent(std::string text, Font* font, int size);
	
	//destructor
	virtual ~TextComponent();

	//methods overrided from component
	void init() override;
	void render() override;


	//set the text in a new text
	void setText(std::string text);
	
	//changes the size 
	void setSize(int size);
	
	//changes the font
	void setFont(Font* font);

protected:
	Transform* transform_=nullptr;
	Text* text_=nullptr;
	Font* font_ = nullptr;

	std::string textString_=nullptr;
	int textSize_=0;
};

