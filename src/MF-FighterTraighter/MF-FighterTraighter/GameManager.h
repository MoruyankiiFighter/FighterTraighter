#pragma once
#include <vector>
#include <string>

class Entity;
class App;
class GameStateMachine;

class GameManager
{
protected:
	// CHANGE ME TO SOMETHING PROPER
	struct playerInfo {
		Entity* entity;
		std::string character;
		std::vector<std::string> abilities;
		unsigned int ability1Index;
		unsigned int ability2Index;
	};
public:
	GameManager(App* app);
	// To inform this that start/escape was pressed
	void pressedStart();
	// To inform that player (0 or 1) lost a round, or that it's a draw (-1)
	// Maybe there's something better than an int?
	void playerLost(int player);
	// To inform that saco has lost all its health
	void trainingEnded();
	void setPlayerInfo1(Entity* p1, std::string character, std::vector<std::string> abilities, unsigned int ability1Index, unsigned int ability2Index);
	void setPlayerInfo2(Entity* p2, std::string character, std::vector<std::string> abilities, unsigned int ability1Index, unsigned int ability2Index);
	playerInfo getPlayerInfo(int player) {
		if (player == 1) return player1_;
		return player2_;
	}
protected:
	unsigned int playerLrounds_ = 0;
	unsigned int playerRrounds_ = 0;
	unsigned int totalRounds_ = 100;
	unsigned int currentRound_ = 0;

	// CHANGE ME TO SOMETHING PROPER
	playerInfo player1_;
	playerInfo player2_;

	App* app_;

	void GoBackToMain(GameStateMachine* stateMachine);
};

