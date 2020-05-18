#pragma once
#include <vector>
#include <string>
#include "HID.h"

class Entity;
class App;
class GameStateMachine;

class GameManager
{

public:	
enum AbilityID {
	SeismicShock,
	MegatonGrip,
	ExplosiveWillpower,
	AcidSplit,
	Mina,
	ShrugOff,
	MorePower,
	Hookshot,
	Dash,
	VampiricStrike,
	HailBall,
	ReachingStrike,
	FlyingKicks,
	LaserLineal,
	NadoKick
};

	// TODO: Move from here to somewhere else
	enum CharacterID {
		/*None,*/
		F10R,
		Aisha,
		MKWh00p,
		Mockingbird
	};

	struct PlayerInfo {
		CharacterID character;
		std::vector<AbilityID> abilities;
		AbilityID ability1Index;
		AbilityID ability2Index;
		HID* hid;
		virtual ~PlayerInfo() {
			delete hid;
		}
	};
	GameManager(App* app);

	// To update HIDs
	void handleInput();

	// To inform this that start/escape was pressed
	void pressedStart();
	// To inform that player (0 or 1) lost a round, or that it's a draw (-1)
	// Maybe there's something better than an int?
	void playerLost(int player);
	void ResetRounds();
	// To inform that saco has lost all its health
	void trainingEnded();
	void setCharacter(CharacterID char_, int n) {
		if (n == 1) {
			player1_.character = char_;
		}
		else {

			player2_.character = char_;
		}
	}

	void resetCharacters();

	void setPlayerInfo1(Entity* p1, std::string character, std::vector<std::string> abilities, AbilityID ability1Index, AbilityID ability2Index);
	void setPlayerInfo2(Entity* p2, std::string character, std::vector<std::string> abilities, AbilityID ability1Index, AbilityID ability2Index);
	const PlayerInfo& getPlayerInfo(int player) {
		if (player == 1) return player1_;
		return player2_;
	}

	virtual ~GameManager() {
	}
	inline unsigned int getPlayerRounds(int player) {
		if (player == 1) return playerLrounds_;
		return playerRrounds_;
	}
	inline unsigned int getTotalRounds() { return totalRounds_; }

	void GoBackToMain();

protected:
	unsigned int playerLrounds_ = 0;
	unsigned int playerRrounds_ = 0;
	unsigned int totalRounds_ = 3;
	unsigned int currentRound_ = 0;

	PlayerInfo player1_;
	PlayerInfo player2_;

	App* app_;
};

