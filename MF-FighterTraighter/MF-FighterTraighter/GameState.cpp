#include "GameState.h"
#include "Entity.h"

GameState::GameState() {

}
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
	scene.clear();
}

GameState::~GameState()
{
	empty();
}
