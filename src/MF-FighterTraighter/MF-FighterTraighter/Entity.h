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
	T* getComponent(ecs::CmpIdType id) {
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

	inline App* getApp() const { return app_; }
	inline void setApp(App* app) { app_ = app; }
private:
	App* app_;
	std::vector<std::unique_ptr<Component>> components_;
	std::array<Component*, ecs::_LastCmptId_> componentsArray_ = {}; // to prevent the vector from resizing, and delete automatically

};

template<typename T, typename ...TArgs>
inline T* Entity::addComponent(TArgs ...args)
{
	T* t(new T(std::forward<TArgs>(args)...));
	std::unique_ptr<Component> c(t);
	components_.push_back(std::move(c));
	componentsArray_[c->getID()] = c;
	c->setEntity(this);
	c->setApp(app_);
	c->init();
	return c;
}
