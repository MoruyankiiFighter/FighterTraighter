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
	virtual void init();
	virtual void handleInput();
	virtual void update();
	virtual void render();
	
	// deletes the entitys of the list
	virtual void empty();
	
	//return app
	App* getApp() { return app_; };

	//return the entity mangaer of the scene
	EntityManager& getEntityManager() { return entManager_; };
protected:
	EntityManager entManager_;
	App* app_=nullptr;
	bool handled = false;//to avoid errors when we popState
};

