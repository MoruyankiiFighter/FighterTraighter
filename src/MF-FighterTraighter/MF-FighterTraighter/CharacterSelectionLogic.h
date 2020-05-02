#pragma once
#include "Component.h"
#include "TextComponent.h"
#include "NavigationController.h"
#include "RenderImage.h"
class CharacterSelectionLogic: public Component
{
public:

	CharacterSelectionLogic(TextComponent* j_desc, RenderImage* im, string aisha_desc, string mkwhoop_desc, string flor_desc, string mock_desc, NavigationController* nav, UIElement* aisha, UIElement* flor, UIElement* mkwhoop, UIElement* mock, Texture* aishatexture, Texture* flortexture, Texture* mkwhooptexture, Texture* mocktexture  ) : Component(ecs::CharacterSelectionLogic),
		desc_(j_desc), aisha_(aisha),aisha_desc_(aisha_desc),flor_(flor), flor_desc_(flor_desc),mock_(mock),mock_desc_(mock_desc),mkwhoop_(mkwhoop),mkwhoop_desc_(mkwhoop_desc),nav_(nav),
		aisha_texture(aishatexture), flor_texture(flortexture), mkwhoop_texture(mkwhooptexture), mock_texture(mocktexture), image_(im) { }
	
	void init() override;
	void update() override;
	
	void SetElements();
private:

	TextComponent* desc_=nullptr;
	RenderImage* image_ = nullptr;
	string aisha_desc_, flor_desc_, mkwhoop_desc_, mock_desc_;
	NavigationController* nav_=nullptr;

	UIElement* aisha_=nullptr;
	UIElement* flor_=nullptr;
	UIElement* mkwhoop_=nullptr;
	UIElement* mock_=nullptr;

	Texture* aisha_texture = nullptr;
	Texture* flor_texture = nullptr;
	Texture* mkwhoop_texture = nullptr;
	Texture* mock_texture = nullptr;
};

