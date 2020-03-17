#pragma once
#include <list>
#include "SDL.h"
class Entity;
class App;

class GameState
{
public:
	//constructor
	GameState(App* app);
	//default constructor
	GameState(const GameState& g) = delete;
	GameState& operator= (const GameState& g) = delete;
	//destructor
	virtual ~GameState();
	//init everything (entitys and add or get components)
	virtual void init();
	
	//handle the input
	virtual void handleInput();
	
	//update
	virtual void update();
	
	//render
	virtual void render();
	
	//clean the list of entitys
	virtual void empty();
	
	//returns the app pointer
	App* giveMeApp() { return app_; };
protected:
	std::list<Entity*> scene;
	App* app_=nullptr;
};

