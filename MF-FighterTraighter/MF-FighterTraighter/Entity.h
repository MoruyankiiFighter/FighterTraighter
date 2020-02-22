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
		return components_[id] != nullptr;
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
	//std::array<Component*> componentsArray_ = {};

};

