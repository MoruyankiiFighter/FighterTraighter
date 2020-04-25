#pragma once
#include "Component.h"
#include "TextComponent.h"
class CharacterSelectionLogic: public Component
{
public:
	CharacterSelectionLogic(Texture* J1_character, Texture* J2_character, TextComponent* j1_text, TextComponent* j2_text): Component(ecs::OptionsLogic),
		j1_char_(J1_character), j2_char_(J2_character), j1_text_(j1_text), j2_text_(j2_text){}
	~CharacterSelectionLogic();

	void init() override;
	void update() override;
	void SetElements();
private:
	Texture* j1_char_;
	Texture * j2_char_;
	TextComponent* j1_text_;
	TextComponent* j2_text_;
};

