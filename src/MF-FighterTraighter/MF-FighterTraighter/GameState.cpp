#include "GameState.h"
#include "Entity.h"
#include "App.h"

GameState::GameState(App* app) : app_(app){

}
void GameState::init()
{
}

void GameState::handleInput()
{
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->handleInput();
	}
}

void GameState::update()
{
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->update();
	}
}

void GameState::render()
{
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->render();
	}
}

void GameState::empty()
{
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		delete* it;
	}
	scene.clear();
}

GameState::~GameState()
{
	empty();
}
