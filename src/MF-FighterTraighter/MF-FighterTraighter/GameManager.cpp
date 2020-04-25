#include "GameManager.h"
#include "GameStateMachine.h"
#include "App.h"

#include "GameState.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "ControlsMenu.h"
#include "Fight.h"
#include "OptionsMenu.h"
#include "Training.h"
#include "Entity.h"
GameManager::GameManager(App* app) : app_(app)
{
	app_->getStateMachine()->pushState(new MainMenu(app_));
}

void GameManager::pressedStart()
{
	GameState* curState = app_->getStateMachine()->getCurrentState();
	if (dynamic_cast<MainMenu*>(curState)) app_->Exit();
	else if (dynamic_cast<PauseMenu*>(curState)
		|| dynamic_cast<ControlsMenu*>(curState)
		|| dynamic_cast<OptionsMenu*>(curState)) app_->getStateMachine()->popState();
	else if (dynamic_cast<Fight*>(curState)
		|| dynamic_cast<Training*>(curState)) app_->getStateMachine()->pushState(new PauseMenu(app_));
}

void GameManager::playerLost(int player)
{
	GameStateMachine* stateMachine = app_->getStateMachine();
	switch (player)
	{
	case -1:
		break;
	case 0:
		++playerLrounds_;
		break;
	case 1:
		++playerRrounds_;
		break;
	default:
		break;
	}

	if (currentRound_ < totalRounds_ - 1) {
		// Remove the current fight mode
		stateMachine->popState();
		stateMachine->pushState(new Training(app_));
		++currentRound_;
	}
	else {
		currentRound_ = 0;
		playerLrounds_ = 0;
		playerRrounds_ = 0;
		GoBackToMain(stateMachine);
	}

}

void GameManager::trainingEnded()
{
	GameStateMachine* stateMachine = app_->getStateMachine();
	// Remove the current training mode
	stateMachine->popState();
	stateMachine->pushState(new Fight(app_));
}

void GameManager::setPlayerInfo1(Entity* p1, std::string character, std::vector<std::string> abilities, unsigned int ability1Index, unsigned int ability2Index)
{
	player1_.entity = p1;
	player1_.character = character;
	player1_.abilities = abilities;
	player1_.ability1Index = ability1Index;
	player1_.ability2Index = ability2Index;
}

void GameManager::setPlayerInfo2(Entity* p2, std::string character, std::vector<std::string> abilities, unsigned int ability1Index, unsigned int ability2Index)
{
	player2_.entity = p2;
	player2_.character = character;
	player2_.abilities = abilities;
	player2_.ability1Index = ability1Index;
	player2_.ability2Index = ability2Index;
}

void GameManager::GoBackToMain(GameStateMachine* stateMachine)
{
	GameState* currState = stateMachine->getCurrentState();
	while (dynamic_cast<MainMenu*>(currState) == nullptr) {
		stateMachine->popState();
		currState = stateMachine->getCurrentState();
	}
}
