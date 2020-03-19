#include "GameState.h"
#include "Entity.h"
#include "App.h"

GameState::GameState(App* app) : app_(app), entManager_(app) {

}
void GameState::init()
{
	
}

void GameState::handleInput()
{
	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		(*it)->handleInput();
	}
}

void GameState::update()
{
	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		(*it)->update();
	}
}

void GameState::render()
{
	SDL_RenderClear(app_->getRenderer());

	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		(*it)->render();
	}

	SDL_RenderPresent(app_->getRenderer());
}

void GameState::empty()
{
	for (auto it = entManager_.getScene().begin(); it != entManager_.getScene().end(); ++it) {
		delete* it;
	}
	entManager_.getScene().clear();
}

GameState::~GameState()
{
	empty();
}
