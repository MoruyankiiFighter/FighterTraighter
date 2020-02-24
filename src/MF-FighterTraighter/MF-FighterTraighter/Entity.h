#pragma once
#include <vector>
#include "Component.h"
class Entity
{

public:
	Entity();
	~Entity();

	template<typename T, typename ... TArgs>
	T* addComponent(TArgs ...args);
	
	template<typename T>
	T* getComponent(int id) {
		return static_cast<T*>(componentsArray_[id]);
	}

	bool hasComponent(int id) {
		return componentsArray_[id] != nullptr;
	}
	
	void handleInput() {
		for (auto& c : components_) {
			c->handleInput();
		}
	}

	void update() {
		for (auto& c : components_) {
			c->update();
		}
	}

	void draw() {
		for (auto& c : components_) {
			c->render();
		}
	}

private:
	std::vector<Component*> components_;
	std::array<std::unique_ptr<Component>, ecs::_LastCmptId_> componentsArray_ = {}; // to prevent the vector from resizing, and delete automatically
	App* app_;

};

template<typename T, typename ...TArgs>
inline T* Entity::addComponent(TArgs ...args)
{
	T* t = new T(std::forward(static_cast<TArgs>(args)...));
	std::unique_ptr<Component> c(t);
	components_.push_back(std::move(c));
	componentsArray_[c->getID()] = c;
	c->setEntity(this);
	c->setGame(app_);
	c->init();
	return c;
}
