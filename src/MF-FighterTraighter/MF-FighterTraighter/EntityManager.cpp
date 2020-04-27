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
	list_.push_back(e);
	return e;
}

void EntityManager::removeEntity(Entity* e)
{
	list_.remove(e);
	delete e;
	e = nullptr;
}

std::list<Entity*>& EntityManager::getScene()
{
	return list_;
}

void EntityManager::empty() {
	for (auto it = list_.begin(); it != list_.end(); ++it) {
		if (*it != nullptr) {
			delete* it;
			*it = nullptr;
		}
	}
	list_.clear();
}
