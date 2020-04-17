#pragma once
#include <vector>
#include <string>
class App;

class GameManager
{
protected:
	// CHANGE ME TO SOMETHING PROPER
	struct playerInfo {
		std::string character;
		std::vector<std::string> abilities;
		unsigned int ability1Index;
		unsigned int ability2Index;
	};
public:
	GameManager(App* app) : app_(app) {}
	// To inform this that start/escape was pressed
	void pressedStart();
	// To inform that player (0 or 1) lost a round, or that it's a draw (-1)
	void playerLost(int player);
protected:
	unsigned int playerLrounds_ = 0;
	unsigned int playerRrounds_ = 0;
	unsigned int totalRounds_ = 0;
	unsigned int currentRound_ = 0;

	// CHANGE ME TO SOMETHING PROPER
	playerInfo player1_;
	playerInfo player2_;

	App* app_;
};

