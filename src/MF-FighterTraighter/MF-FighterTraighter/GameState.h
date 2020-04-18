#pragma once
#include <list>
#include "SDL.h"
#include "EntityManager.h"
#include "SDLDebugDraw.h"
#include <Box2D/Box2D.h>
#include <vector>
#include <array>
#include <utility>
#include "Vector2D.h"
class Entity;
class App;

class GameState
{
public:
	//	Collision filters for the b2d collision
	enum CollisionFilters : uint16 {
		BOUNDARY = 0x0001,
		PLAYER_1 = 0x0002,
		PLAYER_2 = 0x0004,
		P_BAG = 0x0008,
		WALLS = 0x0010,
		EVERYTHING = 0xFFFF,
	};
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
		b2Body* body, uint16 id, uint16 cBits = 0x0001, uint16 mBits = 0xFFFF, bool guardBreaker = false);
	void addHurtbox(b2Fixture* fixt) { mainHurtboxes.push_back(fixt); }

	void resetGroup(int group);
	void clearHitboxes();
	// deletes the entitys of the list
	virtual void empty();

	//return app
	App* getApp() { return app_; };

	//return the entity mangaer of the scene
	EntityManager& getEntityManager() { return entManager_; };
protected:
	void RemoveHitbox();
	void UpdateHitboxes();

	EntityManager entManager_;
	App* app_ = nullptr;

	std::vector<b2Fixture*> mainHurtboxes;	//to get the main fixtures of the players and the punching bag to check overlaps
	std::array<std::list<b2Fixture*>, 2> hitboxGroups_;	// hitboxes groups that players use (max 2 players)
	std::list<std::pair<std::list<b2Fixture*>::iterator, unsigned int>> hitboxRemove_pair_;
};

