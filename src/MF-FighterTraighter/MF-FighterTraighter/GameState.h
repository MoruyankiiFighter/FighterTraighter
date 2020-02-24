#pragma once
#include <list>
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
	virtual void render() const;
	virtual void empty();
	virtual ~GameState();
protected:
	std::list<Entity*> scene;
	App* app_;
};

