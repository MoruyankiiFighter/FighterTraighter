#include "TextComponent.h"
#include "Entity.h"

TextComponent::TextComponent(Text* text) : Component(ecs::TextComponent), text_(text), transform_(nullptr)
{
}

void TextComponent::init()
{
	transform_ = entity_->getComponent<Transform>(ecs::Transform);
}

void TextComponent::render()
{
	SDL_Rect dest = SDL_Rect();
	dest.x = transform_->getPosition().getX();
	dest.y = transform_->getPosition().getY();
	dest.w = transform_->getWidth() * transform_->getWMult();
	dest.h = transform_->getHeight() * transform_->getHMult();
	text_->render(dest);
}

void TextComponent::setText(std::string text)
{
	text_->setText(text);
}

void TextComponent::setFont(Font* font)
{
	text_->setFont(font);
}

TextComponent::~TextComponent()
{
}
