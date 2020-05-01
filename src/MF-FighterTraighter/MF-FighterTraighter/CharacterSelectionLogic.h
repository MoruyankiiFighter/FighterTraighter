#pragma once
#include "Component.h"
#include "TextComponent.h"
#include "NavigationController.h"
class CharacterSelectionLogic: public Component
{
public:

	CharacterSelectionLogic(TextComponent* j1_desc, string aisha_desc, string mkwhoop_desc, string flor_desc, string mock_desc, NavigationController* nav, UIElement* aisha, UIElement* flor, UIElement* mkwhoop, UIElement* mock  ) : Component(ecs::CharacterSelectionLogic),
		desc_(j1_desc), aisha_(aisha),aisha_desc_(aisha_desc),flor_(flor), flor_desc_(flor_desc),mock_(mock),mock_desc_(mock_desc),mkwhoop_(mkwhoop),mkwhoop_desc_(mkwhoop_desc),nav_(nav) { }
	
	void init() override;
	void update() override;
	
	void SetElements();
private:
	TextComponent* desc_=nullptr;
	string aisha_desc_, flor_desc_, mkwhoop_desc_, mock_desc_;
	NavigationController* nav_=nullptr;
	UIElement* aisha_=nullptr;
	UIElement* flor_=nullptr;
	UIElement* mkwhoop_=nullptr;
	UIElement* mock_=nullptr;
};

