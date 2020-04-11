#pragma once
#include <list>
#include "SDL.h"
#include "EntityManager.h"
class Entity;
class App;

class GameState
{
public:
	//constructor
	GameState(App* app);
	GameState(const GameState& g) = delete;
	GameState& operator= (const GameState& g) = delete;
	
	//destructor
	virtual ~GameState();

	//basic methods that other states will have with the basic functionality
	
	//method where we create the entitys and add functionality
	virtual void init();
	//updates the different components
	virtual void update();
	//render the component if it's needed
	virtual void render();
	//handle the input
	virtual void handleInput();
	
	// deletes the entitys of the list
	virtual void empty();
	
	//return app
	App* getApp() { return app_; };

	//return the entity mangaer of the scene
	EntityManager& getEntityManager() { return entManager_; };
protected:
	EntityManager entManager_;
	App* app_=nullptr;
};

