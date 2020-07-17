#pragma once
#include "GameState.h"
#include "App.h"
class CharacterSelection : public GameState
{

public:

	//constructor
	CharacterSelection(App* app, int numPlayer) : GameState(app), numPlayer_(numPlayer) { init(); }
	virtual ~CharacterSelection() {}
	void init() override;
	void handleInput() override;
private:
	int numPlayer_;
	string mkwhoop_desc = "MKW00P: Has a slow and powerful playstyle, with hard hits and high push and a lot of life points.";
	string aisha_desc = "Aisha: Has a balanced playstyle, not specially fast or slow, focusing on aerial attacks. Has average life points.";
	string flor_desc = "F10R: It's a long ranged character, able to keep itself away from its enemy. It has average life points.";
	string mock_desc = "MockingBird: Has fast attacks that are not very powerful. His playstyle is about combos and speed. His life points are low.";
};

