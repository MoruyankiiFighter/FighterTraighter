#pragma once
#include <list>
#include "SDL.h"
class Entity;
class App;

class GameState
{
public:
	GameState(App* app);
	GameState(const GameState& g) = delete;
	GameState& operator= (const GameState& g) = delete;
	virtual void init();
	virtual void handleInput();
	virtual void update();
	virtual void render();
	virtual void empty();
	virtual ~GameState();
	App* giveMeApp() { return app_; };
protected:
	std::list<Entity*> scene;
	App* app_;
};

