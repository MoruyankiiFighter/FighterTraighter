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

	//methods overrided from the component class
	void init() override;
	void render() override;

	//set the different values of the textcomponent
	void setText(std::string text);
	void setSize(int size);
	void setFont(Font* font);

protected:
	Transform* transform_=nullptr;
	Text* text_=nullptr;
	Font* font_ = nullptr;

	std::string textString_="";
	int textSize_=0;
};

