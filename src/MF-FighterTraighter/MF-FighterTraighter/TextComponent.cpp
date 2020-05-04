#include "TextComponent.h"
#include "Entity.h"

TextComponent::TextComponent(std::string text, Font* font, int size, TextAlignment alignment) : Component(ecs::TextComponent),
text_(nullptr), transform_(nullptr), textString_(text), textSize_(size), font_(font), alignment_(alignment)
{
}

void TextComponent::init()
{
	transform_ = entity_->getComponent<Transform>(ecs::Transform);
	font_->setFontSize(textSize_);
	text_ = new Text(app_->getRenderer(), textString_, font_, longText_);
}

void TextComponent::render()
{
	SDL_Rect dest;
	int destWidth = textString_.length() * transform_->getWMult() * textSize_ * font_->getWidthRatio();
	switch (alignment_)
	{
	case TextComponent::Left:
		dest.x = transform_->getPosition().getX();
		break;
	case TextComponent::Center:
		dest.x = transform_->getPosition().getX() + (transform_->getWidth() * transform_->getWMult() - destWidth) / 2;
		break;
	case TextComponent::Right:
		dest.x = transform_->getPosition().getX() + (transform_->getWidth() * transform_->getWMult() - destWidth);
		break;
	default:
		break;
	}
	int lines = int((text_->getHeight() / textSize_) / transform_->getHMult())*2;
	
	dest.y = transform_->getPosition().getY();
	dest.w = destWidth;
	dest.h = textSize_ * transform_->getHMult()*(lines);
	text_->render(dest);
}

void TextComponent::setText(std::string text)
{
	if (text != textString_) {
		text_->setText(text);
		textString_ = text;
	}
}

void TextComponent::setSize(int size)
{
	if (size != textSize_) {
		text_->setSize(size);
		textSize_ = size;
	}
}

void TextComponent::setFont(Font* font)
{
	if (font != font_) {
		text_->setFont(font);
		font_ = font;
	}
}

TextComponent::~TextComponent()
{
	delete text_;
}
