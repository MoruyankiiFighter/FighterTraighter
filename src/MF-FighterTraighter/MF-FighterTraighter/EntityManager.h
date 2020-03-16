#pragma once
#include <list>
class App;
class Entity;

class EntityManager
{
public:
	EntityManager(App* app) : app_(app) {};
	virtual ~EntityManager();

	Entity* addEntity();
	void removeEntity(Entity* e);
	void empty();
	std::list<Entity*>& getScene();
private:
	App* app_;
	std::list<Entity*> scene;
	//EntityManager(EntityManager&) {};
	//EntityManager& operator= (EntityManager&) { return EntityManager(nullptr); };
};

