#pragma once
#include <list>
class App;
class Entity;

class EntityManager
{
public:
	//constructor
	EntityManager(App* app) : app_(app) { };
	//destructor
	virtual ~EntityManager();

	//add entity to the entity list
	Entity* addEntity();
	
	//remove the entity e from the list
	void removeEntity(Entity* e);

	//deletes all the entities of the list
	void empty();

	//return the list
	std::list<Entity*>& getScene();
private:

	App* app_=nullptr;
	std::list<Entity*> list_ = std::list<Entity*>(); //list of the entities
};

