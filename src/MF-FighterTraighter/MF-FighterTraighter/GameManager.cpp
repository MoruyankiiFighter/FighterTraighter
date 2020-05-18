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
#include "CharacterSelection.h"
#include "KeyboardHID.h"
#include "GamepadHID.h"

GameManager::GameManager(App* app) : app_(app)
{
	app_->getStateMachine()->pushState(new MainMenu(app_));
	resetCharacters();

	// TODO: Move this elsewhere
	player1_.hid = new KeyboardHID(app_->getInputManager());
	//player1_.character = F10R;
	player1_.character = MKWh00p;

	player2_.hid = new KeyboardHID(app_->getInputManager());//keyboard too
	//player2_.hid = new GamepadHID(app_->getInputManager(), 0);
	player2_.character = F10R;
}

void GameManager::handleInput()
{
	player1_.hid->updateInput();
	player2_.hid->updateInput();
}

void GameManager::pressedStart()
{
	GameState* curState = app_->getStateMachine()->getCurrentState();
	if (dynamic_cast<MainMenu*>(curState)) { 
		app_->Exit(); 
	}
	else if (dynamic_cast<PauseMenu*>(curState)
		|| dynamic_cast<ControlsMenu*>(curState)
		|| dynamic_cast<OptionsMenu*>(curState)
		|| dynamic_cast<CharacterSelection*>(curState)) app_->getStateMachine()->popState();
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
		++playerRrounds_;
		break;
	case 1:
		++playerLrounds_;
		break;
	default:
		break;
	}
	if (((totalRounds_ / 2) < playerLrounds_) || ((totalRounds_ / 2) < playerRrounds_)) {
		ResetRounds();
		GoBackToMain();
	}
	else {
		stateMachine->popState();
		stateMachine->pushState(new Training(app_));
		++currentRound_;
	}
	/*if (currentRound_ < totalRounds_ - 1) {
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
	}*/

}

void GameManager::ResetRounds()
{
	currentRound_ = 0;
	playerLrounds_ = 0;
	playerRrounds_ = 0;
}

//winner = 0; player1 wins
//winner = 1; player2 wins
void GameManager::trainingEnded(int winner)
{
	cout << "Player " << winner + 1 << " wins the training!" << endl;
	GameStateMachine* stateMachine = app_->getStateMachine();
	PlayerInfo *pWin = nullptr, 
				*pLose = nullptr;
	if (winner == 0) {
		pWin = &player1_;
		pLose = &player2_;
	}
	else {
		pWin = &player2_;
		pLose = &player1_;
	}
	
	//the wining player chooses 1 and gets other random
	//por ahora tiene las dos random, habr�a usar el estado de selecci�n de habilidades aqu�
	pWin->abilities.push_back((AbilityID)app_->getRandGen()->nextInt(level1_flag, max_level_flag));
	pWin->abilities.push_back((AbilityID)app_->getRandGen()->nextInt(level1_flag, max_level_flag));
	//the losing player, gets random lvl sth 
	pLose->abilities.push_back((AbilityID)app_->getRandGen()->nextInt(level1_flag, max_level_flag));
	pLose->abilities.push_back((AbilityID)app_->getRandGen()->nextInt(level1_flag, max_level_flag));
	// Remove the current training mode
	stateMachine->popState();
	stateMachine->pushState(new Fight(app_));
}

void GameManager::setPlayerInfo1(Entity* p1, std::string character, std::vector<std::string> abilities, AbilityID ability1Index, AbilityID ability2Index)
{
	//player1_.character = character;
	//player1_.abilities = abilities;
	player1_.ability1Index = ability1Index;
	player1_.ability2Index = ability2Index;
}

void GameManager::setPlayerInfo2(Entity* p2, std::string character, std::vector<std::string> abilities, AbilityID ability1Index, AbilityID ability2Index)
{
	//player2_.character = character;
	//player2_.abilities = abilities;
	player2_.ability1Index = ability1Index;
	player2_.ability2Index = ability2Index;
}

void GameManager::resetCharacters()
{
	player1_.character = F10R;
	player2_.character = F10R;
}

void GameManager::GoBackToMain()
{
	resetCharacters();
	ResetRounds();
	GameState* currState = app_->getStateMachine()->getCurrentState();
	while (dynamic_cast<MainMenu*>(currState) == nullptr) {
		app_->getStateMachine()->popState();
		currState = app_->getStateMachine()->getCurrentState();
	}
}
