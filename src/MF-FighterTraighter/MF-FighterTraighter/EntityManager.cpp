#include "EntityManager.h"
#include "Entity.h"

EntityManager::~EntityManager()
{
	empty();
}

Entity* EntityManager::addEntity()
{
	Entity* e = new Entity(); // Until we have factories
	e->setApp(app_);
	scene.push_back(e);
	return e;
}

void EntityManager::removeEntity(Entity* e)
{
	scene.remove(e);
	delete e;
}

std::list<Entity*>& EntityManager::getScene()
{
	return scene;
}

void EntityManager::empty() {
	for (auto it = scene.begin(); it != scene.end(); ++it) {
		delete* it;
	}
	scene.clear();
}
