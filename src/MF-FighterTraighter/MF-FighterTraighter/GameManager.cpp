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
#include "KeyboardHID.h"
#include "GamepadHID.h"

GameManager::GameManager(App* app) : app_(app)
{
	app_->getStateMachine()->pushState(new MainMenu(app_));
	// TODO: Move this elsewhere
	player1_.hid = new KeyboardHID(app_->getInputManager());
	player1_.character = MKWh00p;
	player2_.hid = new GamepadHID(app_->getInputManager(), 0);
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
	if (((totalRounds_ / 2)  < playerLrounds_) || ((totalRounds_ / 2)  < playerRrounds_)) {
		currentRound_ = 0;
		playerLrounds_ = 0;
		playerRrounds_ = 0;
		GoBackToMain(stateMachine);
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

void GameManager::trainingEnded()
{
	GameStateMachine* stateMachine = app_->getStateMachine();
	//hacerlo random y tener en cuenta la seleccion de habilidades
	/*player1_.abilities.push_back(MegatonGrip);
	player1_.abilities.push_back(SeismicShock);	
	player2_.abilities.push_back(MegatonGrip);
	player2_.abilities.push_back(SeismicShock);	//hacerlo random */
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

void GameManager::GoBackToMain(GameStateMachine* stateMachine)
{
	GameState* currState = stateMachine->getCurrentState();
	while (dynamic_cast<MainMenu*>(currState) == nullptr) {
		stateMachine->popState();
		currState = stateMachine->getCurrentState();
	}
}
