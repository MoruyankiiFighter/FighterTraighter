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

	// Create hitboxes
	void addHitbox(Vector2D pos, int width, int height, int time, int damage, int hitstun, Vector2D knockBack,
		b2Body* body, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, bool guardBreaker = false);
	void addHurtbox(b2Fixture* fixt) { mainHurtboxes.push_back(fixt); }

	// deletes the entitys of the list
	virtual void empty();

	//return app
	App* getApp() { return app_; };

	//return the entity mangaer of the scene
	EntityManager& getEntityManager() { return entManager_; };
protected:
	EntityManager entManager_;
	App* app_ = nullptr;

	vector<b2Fixture*> mainHurtboxes;	//to get the main fixtures of the players and the punching bag to check overlaps
	array<list<b2Fixture*>, 2> hitboxGroups_;	// hitboxes groups that players use (max 2 players)
	list<pair<list<b2Fixture*>::iterator, uint>> hitboxRemove_pair_;

	SDLDebugDraw* debugInstance = nullptr; //utilizar solo si estamos debuggeando
};

