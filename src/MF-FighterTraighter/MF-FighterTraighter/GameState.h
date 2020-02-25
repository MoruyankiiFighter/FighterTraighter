#pragma once
#include <list>
#include "SDL.h"
class Entity;
class App;

class GameState
{
public:
	GameState(App* app, SDL_Renderer* rend);
	GameState(const GameState& g) = delete;
	GameState& operator= (const GameState& g) = delete;
	virtual void init();
	virtual void handleInput();
	virtual void update();
	virtual void render() const;
	virtual void empty();
	virtual ~GameState();
protected:
	std::list<Entity*> scene;
	App* app_;
	SDL_Renderer* rend_;
};

