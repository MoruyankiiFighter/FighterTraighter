#include "GameState.h"
#include "Entity.h"

void GameState::init()
{
}

void GameState::update()
{
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->update();
	}
}

void GameState::render() const
{
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		(*it)->draw();
	}
}

void GameState::empty()
{
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		delete* it;
	}
}

GameState::~GameState()
{
	empty();
}
