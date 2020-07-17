#pragma once
#include "Component.h"
#include "NavigationController.h"
#include "ButtonControl.h"
class ControlsOptionsLogic :
	public Component
{
public:
	ControlsOptionsLogic(NavigationController* player1Nav,
		NavigationController* player2Nav,
		std::vector<std::tuple<Entity*, Entity*>> player1Buttons,
		std::vector<std::tuple<Entity*, Entity*>> player2Buttons,
		std::vector<Entity*> keyIdentifierTexts,
		Entity* player1Text,
		Entity* player2Text) :
		Component(ecs::ControlsOptionsLogic),
		player1Nav_(player1Nav),
		player2Nav_(player2Nav),
		player1Buttons_(player1Buttons),
		player2Buttons_(player2Buttons),
		keyIdentifierTexts_(keyIdentifierTexts),
		player1Text_(player1Text),
		player2Text_(player2Text) {
			keyTexts[0] = "Start";
			keyTexts[1] = "Select";
			keyTexts[2] = "LEFT";
			keyTexts[3] = "UP";
			keyTexts[4] = "RIGHT";
			keyTexts[5] = "DOWN";
			keyTexts[6] = "NORMAL KICK";
			keyTexts[7] = "STRONG KICK";
			keyTexts[8] = "NORMAL PUNCH";
			keyTexts[9] = "STRONG PUNCH";
			keyTexts[10] = "ABILITY ONE";
			keyTexts[11] = "ABILITY TWO";
			keyTexts[12] = "CLICK LEFTJOY";
			keyTexts[13] = "CLICK RIGHTJOY";
			keyTexts[14] = "GUARD";
			keyTexts[15] = "GUARDBREAK";
	}
	virtual ~ControlsOptionsLogic() {}

	void init() override;
	void update() override;

	void setEnabled(bool e);
	void setElements();

protected:
	NavigationController* player1Nav_;
	NavigationController* player2Nav_;

	std::vector<std::tuple<Entity*, Entity*>> player1Buttons_;
	std::vector<std::tuple<Entity*, Entity*>> player2Buttons_;
	std::vector<Entity*> keyIdentifierTexts_;
	Entity* player1Text_;
	Entity* player2Text_;
	string keyTexts[16];

	bool enabled = false;
};

