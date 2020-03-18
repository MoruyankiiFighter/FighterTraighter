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
	scene_.push_back(e);
	return e;
}

void EntityManager::removeEntity(Entity* e)
{
	scene_.remove(e);
	delete e;
}

std::list<Entity*>& EntityManager::getScene()
{
	return scene_;
}

void EntityManager::empty() {
	for (auto it = scene_.begin(); it != scene_.end(); ++it) {
		delete* it;
	}
	scene_.clear();
}
